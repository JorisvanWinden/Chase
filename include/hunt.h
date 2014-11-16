#ifndef HUNT_H
#define HUNT_H

#include "board.h"

// sets all lights in this row to off
// stores all lights clicked in sol, if not NULL
void hunt_row(board_t * board, int m, solution_t * sol);

// sets all lights except in the bottom row off
// stores all lights clicked in sol, unless NULL
void hunt_board(board_t * board, solution_t * sol);

#endif
