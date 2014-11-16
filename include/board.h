#ifndef BOARD_H
#define BOARD_H

typedef struct {
	int N;
	int M;
	int ** fields;
} board_t, solution_t;

// prints the board to stdout
void print_board(board_t * board);

// serializs the row into an integer, where set bits represent lights which are on, and unset bits represent lights which are off
int serialize_row(board_t * board, int row);

// prints one row of the board.
// assumes valid input
void print_row(board_t * board, int row);

// allocates memory for the board and sets it to 0
board_t * create_board(int M, int N);

// resets board
void clear_board(board_t * board);

// deallocates memory of the board
void destroy_board(board_t * board);

// returns what this square should look like after one of it's neighbours changes
int convert(int src);

// changes board[m][n] to the converted value
// checks for valid input
void turn(board_t * board, int m, int n);

// changes board[m][n] and all of it's non-diagonal neighbours
void click(board_t * board, int m, int n);

/*
clicks all the lights on the upper row of the board which are set in n, where n is serialized.
stores all lights clicked in solution
*/
void click_series(board_t * board, solution_t * solution, int n);

#endif
