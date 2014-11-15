#ifndef BOARD_H
#define BOARD_H

typedef struct {
	int N;
	int M;
	int ** fields;
} board_t;

void print_board(board_t * board);

void print_row(board_t * board, int row);

board_t * create_board(int M, int N);

void clear_board(board_t * board);

void destroy_board(board_t * board);

int convert(int src);

void turn(board_t * board, int m, int n);

void click(board_t * board, int m, int n);

void click_series(board_t * board, int n, int * bin);

#endif
