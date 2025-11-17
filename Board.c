#include "../Header/board.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Board *board_new(void)
{
    Board *b = (Board *)malloc(sizeof(Board));
    if (!b)
        return NULL;
    for (int r = 0; r < BOARD_SIZE; ++r)
    {
        for (int c = 0; c < BOARD_SIZE; ++c)
        {
            b->cell[r][c] = EMPTY;
        }
    }
    return b;
}

void board_free(Board *b)
{
    if (!b)
        return;
    free(b);
}

void board_show(const Board *b)
{
    if (!b)
        return;

    printf("\n    ");

    for (int c = 0; c < BOARD_SIZE; ++c)
    {
        printf("%2d ", c);
    }
    printf("\n");

    for (int r = 0; r < BOARD_SIZE; ++r)
    {
        printf("%2d | ", r);

        for (int c = 0; c < BOARD_SIZE; ++c)
        {
            Piece p = b->cell[r][c];
            char ch = '.';
            if (p == RED)
                ch = 'R';
            else if (p == BLUE)
                ch = 'B';

            printf("%c  ", ch);
        }
        printf("\n");
    }

    printf("\n");
}

bool board_put(Board *b, Point p, Piece who)
{
    if (!b)
        return false;
    if (p.row < 0 || p.row >= BOARD_SIZE)
        return false;
    if (p.col < 0 || p.col >= BOARD_SIZE)
        return false;
    if (who == EMPTY)
        return false;
    if (b->cell[p.row][p.col] != EMPTY)
        return false;
    b->cell[p.row][p.col] = who;
    return true;
}

Piece board_get(const Board *b, Point p)
{
    if (!b)
        return EMPTY;
    if (p.row < 0 || p.row >= BOARD_SIZE)
        return EMPTY;
    if (p.col < 0 || p.col >= BOARD_SIZE)
        return EMPTY;
    return b->cell[p.row][p.col];
}
