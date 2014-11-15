#include "hunt.h"
#include "board.h"
#include "solution.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

// sets all lights in this row to off
// stores all lights clicked in sol, if not NULL
void hunt_row(board_t * board, int m, solution_t * sol)
{
	for(int i = 0; i < board->N; i++)
	{
		if(board->fields[m][i] == 1) {
			click(board, m + 1, i);
			if(sol != NULL)
			{
				sol->ver[sol->count] = m + 1;
				sol->hor[sol->count] = i;
				sol->count++;
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


//hunts all possible combinations of the upper row
void hunt_all(int M, int N)
{
	int count = pow(2, N);
	board_t * board = create_board(M, N);

	for(int i = 0; i < count; i++)
	{
		clear_board(board);

		// the array of 1's and 0's is stored in bin
		int * bin = malloc(sizeof(int) * N);

		click_series(board, i, bin);

		hunt_board(board, NULL);

		// prints in this form: 110:101
		for(int j = 0; j < N; j++)
		{
			printf("%d", bin[j]);
		}
		printf(":");
		print_row(board, M - 1);

		free(bin);
	}
	printf("\n");
	destroy_board(board);
}

// lets user enter coordinates of square to be turnt on
void hunt_custom(int M, int N)
{
	board_t * board = create_board(M, N);
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
			turn(board, ver, hor);
		}
		print_board(board);
		printf("Enter -1 to hunt, or 0 to switch another light: ");
		int res;
		scanf("%d", &res);
		if(res == -1)
		{
			break;
		}
	}
	solution_t * sol = malloc(sizeof(solution_t));

	sol->hor = malloc(sizeof(int) * N * M);
	sol->ver = malloc(sizeof(int) * N * M);
	sol->count = 0;

	hunt_board(board, sol);

	for(int i = 0; i < sol->count; i++)
	{
		printf("Click %d, %d\n", sol->ver[i] + 1, sol->hor[i] + 1);
	}

	free(sol->hor);
	free(sol->ver);
	free(sol);

	printf("Bottom row is: ");
	print_row(board, M - 1);
	printf("\n");

	destroy_board(board);
}
