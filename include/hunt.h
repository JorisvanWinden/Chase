#ifndef HUNT_H
#define HUNT_H

#include "board.h"
#include "solution.h"

void hunt_row(board_t * board, int m, solution_t * sol);

void hunt_board(board_t * board, solution_t * sol);

void hunt_all(int M, int N);

void hunt_custom(int M, int N);

#endif
