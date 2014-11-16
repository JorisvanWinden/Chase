#include <stdio.h>
#include "board.h"
#include "solve.h"

/*
lets user enter coordinates of square to be turnt on.
Then solve that shit, or don't
*/
board_t * create_custom_board()
{
	int M, N;
	printf("Enter board width: ");
	scanf("%d", &N);
	printf("Enter board height: ");
	scanf("%d", &M);

	board_t * board = create_board(M, N);

	do {
		printf("Turn on a light? (y/n) ");
		char res;
		scanf(" %c", &res);

		if(res == 'n' || res == 'N')
		{
			break;
		}

		int hor, ver;

		printf("Enter vertical coordinate: ");
		scanf("%d", &ver);

		printf("Enter horizontal coordinate: ");
		scanf("%d", &hor);

		hor--;
		ver--;
		
		if(hor >= 0 && hor < N && ver >= 0 && ver < M)
		{
			turn(board, ver, hor);
		}
		print_board(board);
	} while (1);

	return board;
}

// asks for board with and height, then jumps to solve_custom
int main(int argc, char * argv[])
{
	board_t * board = create_custom_board();

	solution_t * solution = create_board(board->M, board->N);

	solve(board, solution);

	printf("The solution is:\n");

	print_board(solution);

	destroy_board(board);
	destroy_board(solution);
}
