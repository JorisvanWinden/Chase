#include "hunt.h"
#include "board.h"
#include <stdlib.h>

// sets all lights in this row to off
// stores all lights clicked in sol, if not NULL
void hunt_row(board_t * board, int m, solution_t * sol)
{
	for(int i = 0; i < board->N; i++)
	{
		if(board->fields[m][i] == 1) {
			// click the light under this light
			click(board, m + 1, i);
			if(sol != NULL)
			{
				turn(sol, m + 1, i);
			}
		}
	}
}

// sets all lights except in the bottom row off
// stores all lights clicked in sol, unless NULL
void hunt_board(board_t * board, solution_t * sol)
{
	for(int i = 0; i  < board->M - 1; i++)
	{
		hunt_row(board, i, sol);
	}
}
