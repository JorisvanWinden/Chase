#include <stdio.h>
#include <stdlib.h>

int ** board;
int M;
int N;

void print_board()
{
	for(int i = 0; i < M; i++) {
		for(int j = 0; j < N; j++) {
			printf("%d ", board[i][j]);
		}
		printf("\n");
	}
}

void init_board()
{
	board = malloc(sizeof(int*) * M);
	for(int i = 0; i < M; i++) {
		board[i] = malloc(sizeof(int) * N);
		for(int j = 0; j < N; j++) {
			board[i][j] = 0;
		}
	}
}

void destroy_board()
{
	for(int i = 0; i < M; i++)
	{
		free(board[i]);
	}
	free(board);
}

int convert(int src)
{
	if(src == 0)
	{
		return 1;
	} else {
		return 0;
	}
}

void turn(int m, int n)
{
	if(m >= 0 && m < M && n >= 0 && n < N)
	{
		board[m][n] = convert(board[m][n]);
	} else {
	}
}

void click(int m, int n)
{
	turn(m, n);
	turn(m + 1, n);
	turn(m - 1, n);
	turn(m, n - 1);
	turn(m, n + 1);
}

void hunt_row(int m)
{
	for(int i = 0; i < N; i++)
	{
		if(board[m][i] == 1) {
			click(m + 1, i);
		}
	}
}

void hunt_all()
{
	for(int i = 0; i  < M - 1; i++)
	{
		hunt_row(i);
	}
}

int main(int argc, char * argv[])
{
	printf("Enter width: ");
	scanf("%d", &N);
	printf("Enter height: ");
	scanf("%d", &M);

	init_board();

	while(1)
	{
		int hor;
		int ver;

		printf("Enter vertical: ");
		scanf("%d", &ver);

		printf("Enter horizontal: ");
		scanf("%d", &hor);

		hor--;
		ver--;
		
		if(hor >= 0 && hor < N && ver >= 0 && ver < M)
		{
			click(ver, hor);
		}
		print_board();
		printf("Enter -1 to hunt, or 0 to click again: ");
		int res;
		scanf("%d", &res);
		if(res == -1)
		{
			break;
		}
	}
	
	hunt_all();
	print_board();
	destroy_board();
}
