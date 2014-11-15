#include "board.h"
#include <stdio.h>
#include <stdlib.h>

// prints the board to stdout
void print_board(board_t * board)
{
	for(int i = 0; i < board->M; i++) {
		for(int j = 0; j < board->N; j++) {
			printf("%d ", board->fields[i][j]);
		}
		printf("\n");
	}
}

// prints one row of the board.
// assumes valid input
void print_row(board_t * board, int row)
{
	for(int i = 0; i < board->N; i++)
	{
		printf("%d", board->fields[row][i]);
	}
}

// allocates memory for the board and sets it to 0
board_t * create_board(int M, int N)
{
	board_t * board = malloc(sizeof(board_t));
	board->fields = malloc(sizeof(int*) * M);
	board->M = M;
	board->N = N;
	for(int i = 0; i < M; i++) {
		board->fields[i] = malloc(sizeof(int) * N);
		for(int j = 0; j < N; j++) {
			board->fields[i][j] = 0;
		}
	}
	return board;
}

// resets board
void clear_board(board_t * board)
{
	for(int i = 0; i < board->M; i++)
	{
		for(int j = 0; j < board->N; j++)
		{
			board->fields[i][j] = 0;
		}
	}
}

// deallocates memory of the board
void destroy_board(board_t * board)
{
	for(int i = 0; i < board->M; i++)
	{
		free(board->fields[i]);
	}
	free(board->fields);
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
void turn(board_t * board, int m, int n)
{
	if(m >= 0 && m < board->M && n >= 0 && n < board->N)
	{
		board->fields[m][n] = convert(board->fields[m][n]);
	}
}

// changes board[m][n] and all of it's non-diagonal neighbours
void click(board_t * board, int m, int n)
{
	turn(board, m, n);
	turn(board, m + 1, n);
	turn(board, m - 1, n);
	turn(board, m, n - 1);
	turn(board, m, n + 1);
}

void click_series(board_t * board, int n, int * bin)
{

	for(int i = 0; i < board->N; i++)
	{
		int num = (n >> i) & 1;
		if(num == 1)
		{
			click(board, 0, i);
		}
		if(bin != NULL)
		{
			bin[i] = num;
		}
	}
	printf("\n");
}
