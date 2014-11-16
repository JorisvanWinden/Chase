#ifndef SOLVE_H
#define SOLVE_H

#include "board.h"

/*
Try to find a hunt with the same result as serialized_result,
store the entire hunt in solution.
Assumes solution is not NULL
Returns 0 if succes, -1 if failure.
*/
int find_solution(solution_t * solution, int desired_result, int M, int N);

/*
store the solution for board in sol
assumes sol is not NULL
*/
void solve(board_t * board, solution_t * solution);

#endif
