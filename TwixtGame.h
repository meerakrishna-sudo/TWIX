#ifndef TWIXTGAME_H
#define TWIXTGAME_H

#include <stdbool.h>
#include "board.h"

typedef struct
{
    Board *board;
    Piece turn;
} Game;

Game *game_new(void);
void game_free(Game *g);

void game_run(Game *g);

void game_switch_turn(Game *g);
Point game_input(const Game *g);
Point game_parse(const Game *g, const char *s);

#endif
