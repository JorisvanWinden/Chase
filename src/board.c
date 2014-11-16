#include "board.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// prints the board to stdout
void print_board(board_t * board)
{
	for(int i = 0; i < board->M; i++) {
		print_row(board, i);
	}
}

// serializs the row into an integer, where set bits represent lights which are on, and unset bits represent lights which are off
int serialize_row(board_t * board, int row)
{
	int result = 0;
	for(int i = 0; i < board->N; i++)
	{
		if(board->fields[row][i] == 1)
		{
			result += pow(2, i);
		}
	}
	return result;
}

// prints one row of the board.
// assumes valid input
void print_row(board_t * board, int row)
{
	for(int i = 0; i < board->N; i++)
	{
		printf("%d", board->fields[row][i]);
	}
	printf("\n");
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

/*
click all the lights on the upper row of the board which are set in n, where n is serialized
stores all lights clicked in solution
*/
void click_series(board_t * board, solution_t * solution, int n)
{

	for(int i = 0; i < board->N; i++)
	{
		int light  = (n >> i) & 1;
		if(light == 1)
		{
			click(board, 0, i);
			if(solution != NULL)
			{
				turn(solution, 0, i);
			}
		}
	}
}
