#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int ** board;
int M;
int N;

// prints the board to stdout
void print_board()
{
	for(int i = 0; i < M; i++) {
		for(int j = 0; j < N; j++) {
			printf("%d ", board[i][j]);
		}
		printf("\n");
	}
}

// prints one row of the board.
// assumes valid input
void print_row(int row)
{
	for(int i = 0; i < N; i++)
	{
		printf("%d", board[row][i]);
	}
}

// allocates memory for the board and sets it to 0
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

// resets board
void clear_board()
{
	for(int i = 0; i < M; i++)
	{
		for(int j = 0; j < N; j++)
		{
			board[i][j] = 0;
		}
	}
}

// deallocates memory of the board
void destroy_board()
{
	for(int i = 0; i < M; i++)
	{
		free(board[i]);
	}
	free(board);
}

// returns what this square should look like after one of it's neighbours changes
int convert(int src)
{
	if(src == 0)
	{
		return 1;
	} else {
		return 0;
	}
}

// changes board[m][n] to the converted value
// checks for valid input
void turn(int m, int n)
{
	if(m >= 0 && m < M && n >= 0 && n < N)
	{
		board[m][n] = convert(board[m][n]);
	} else {
	}
}

// changes board[m][n] and all of it's non-diagonal neighbours
void click(int m, int n)
{
	turn(m, n);
	turn(m + 1, n);
	turn(m - 1, n);
	turn(m, n - 1);
	turn(m, n + 1);
}

// sets all lights in this row to off
void hunt_row(int m)
{
	for(int i = 0; i < N; i++)
	{
		if(board[m][i] == 1) {
			click(m + 1, i);
		}
	}
}

// sets all lights except in the bottom row off
void hunt_board()
{
	for(int i = 0; i  < M - 1; i++)
	{
		hunt_row(i);
	}
}

/*
receives an int, ranging from 0 to 2^N
converts the number to a binary sequence, then 'clicks' all on the lights where the index is 1
example: 2 -> 01 -> the second light of the upper row will be 'clicked'

returns the binary sequence as an array of integers

exspects caller to free memory
*/

int* click_series(int n)
{
	int * bin = malloc(sizeof(int) * N);

	for(int i = 0; i < N; i++)
	{
		int num = (n >> i) & 1;
		if(num == 1)
		{
			click(0, i);
		}
		bin[i] = num;
	}
	printf("\n");
	return bin;
}

//hunts all possible combinations of the upper row
void hunt_all()
{
	int count = pow(2, N);

	for(int i = 0; i < count; i++)
	{
		clear_board();

		// the array of 1's and 0's is stored in bin
		int * bin;
		bin = click_series(i);

		hunt_board();

		// prints in this form: 110:101
		for(int j = 0; j < N; j++)
		{
			printf("%d", bin[j]);
		}
		printf(":");
		print_row(M - 1);

		free(bin);
	}
	printf("\n");
}

// lets user enter coordinates of square to be turnt on
void hunt_custom()
{
	while(1)
	{
		int hor;
		int ver;

		printf("Enter vertical coordinate of light switch on: ");
		scanf("%d", &ver);

		printf("Enter horizontal coordinate of light to switch on: ");
		scanf("%d", &hor);

		hor--;
		ver--;
		
		if(hor >= 0 && hor < N && ver >= 0 && ver < M)
		{
			turn(ver, hor);
		}
		print_board();
		printf("Enter -1 to hunt, or 0 to switch another light: ");
		int res;
		scanf("%d", &res);
		if(res == -1)
		{
			break;
		}
	}

	hunt_board();

	print_row(M - 1);
}

// asks for board with and height, prompts what to do, does it. Cleans up.
int main(int argc, char * argv[])
{
	printf("Enter board width: ");
	scanf("%d", &N);
	printf("Enter board height: ");
	scanf("%d", &M);

	printf("Enter 1 to display all hunts\nEnter 2 to create a custom hunt: ");
	int res;
	scanf("%d", &res);

	init_board();

	if(res == 1)
	{
		hunt_all();
	} else if (res == 2)
	{
		hunt_custom();
	}

	
	destroy_board();
}
