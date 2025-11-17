#ifndef BOARD_H
#define BOARD_H

#include <stdbool.h>
#include <stddef.h>

#define BOARD_SIZE 24

typedef enum
{
    EMPTY = 0,
    RED,
    BLUE
} Piece;

typedef struct
{
    int row;
    int col;
} Point;

typedef struct
{
    Piece cell[BOARD_SIZE][BOARD_SIZE];
} Board;

Board *board_new(void);
void board_free(Board *b);

void board_show(const Board *b);
bool board_put(Board *b, Point p, Piece who);
Piece board_get(const Board *b, Point p);

#endif
