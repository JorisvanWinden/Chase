#include <stdlib.h>
#include <math.h>
#include "solve.h"
#include "board.h"
#include "hunt.h"

/*
Try to find a hunt with the same result as serialized_result,
store the entire hunt in solution.
Assumes solution is not NULL
Returns 0 if succes, -1 if failure.
*/
int find_solution(solution_t * solution, int serialized_result, int M, int N)
{
	int count = pow(2, N);

	board_t * board = create_board(M, N);
	solution_t * temp = create_board(M, N);

	for(int i = 0; i < count; i++)
	{
		clear_board(board);
		clear_board(temp);

		click_series(board, temp, i);
		hunt_board(board, temp);

		int result = serialize_row(board, board->M - 1);
		if(result == serialized_result)
		{
			// if lights are set in the temporary solution, turn them in the real solution
			for(int i = 0; i < M; i++)
			{
				for(int j = 0; j < N; j++)
				{
					if(temp->fields[i][j] == 1)
					{
						turn(solution, i, j);
					}
				}
			}
			destroy_board(temp);
			destroy_board(board);
			return 0;
		}
	}
	destroy_board(temp);
	destroy_board(board);
	return -1;
}



/*
store the solution for board in sol
assumes sol is not NULL
*/
void solve(board_t * board, solution_t * sol)
{
	hunt_board(board, sol);

	// bottom row is the serialized result of the first hunt
	int bottom_row_result = serialize_row(board, board->M - 1);

	int status = find_solution(sol, bottom_row_result, board->M, board->N);

	if(status == -1)
	{
		clear_board(sol);
	}
}
