#include "../Header/twixtgame.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Game *game_new(void)
{
    Game *g = (Game *)malloc(sizeof(Game));
    if (!g)
        return NULL;
    g->board = board_new();
    if (!g->board)
    {
        free(g);
        return NULL;
    }
    g->turn = RED;
    return g;
}

void game_free(Game *g)
{
    if (!g)
        return;
    board_free(g->board);
    free(g);
}

void game_switch_turn(Game *g)
{
    if (!g)
        return;
    g->turn = (g->turn == RED) ? BLUE : RED;
}

Point game_parse(const Game *g, const char *s)
{
    (void)g;
    Point p;
    p.row = -1;
    p.col = -1;
    if (!s)
        return p;
    int r, c;
    if (sscanf(s, "%d %d", &r, &c) == 2)
    {
        p.row = r;
        p.col = c;
        return p;
    }
    if (sscanf(s, "%d,%d", &r, &c) == 2)
    {
        p.row = r;
        p.col = c;
        return p;
    }
    return p;
}

Point game_input(const Game *g)
{
    (void)g;
    char buf[256];
    if (!fgets(buf, sizeof(buf), stdin))
    {
        Point p = {-1, -1};
        return p;
    }
    size_t len = strlen(buf);
    while (len > 0 && (buf[len - 1] == '\n' || buf[len - 1] == '\r'))
        buf[--len] = '\0';

    if (len == 1 && (buf[0] == 'q' || buf[0] == 'Q'))
    {
        Point p = {-2, -2};
        return p;
    }

    return game_parse(g, buf);
}

void game_run(Game *g)
{
    if (!g || !g->board)
        return;

    printf("Simple Twixt for mid eval😎🤷‍♀️\n");
    while (1)
    {
        board_show(g->board);
        printf("Turn: %s\n", (g->turn == RED) ? "RED" : "BLUE");
        printf("WHAT YOU WANNA MOVE KIDDO? or 'q' to quit:\n> ");
        fflush(stdout);

        Point p = game_input(g);

        if (p.row == -2 && p.col == -2)
        {
            printf("Quitting. Goodbye.\n");
            break;
        }

        if (p.row == -1 && p.col == -1)
        {
            printf("SORRY😭Invalid input. Use two integers: row col  (0..%d)\n", BOARD_SIZE - 1);
            continue;
        }

        if (p.row < 0 || p.row >= BOARD_SIZE || p.col < 0 || p.col >= BOARD_SIZE)
        {
            printf("OOPSSSSS....Out of bounds. Valid range: 0..%d\n", BOARD_SIZE - 1);
            continue;
        }

        if (board_get(g->board, p) != EMPTY)
        {
            printf("OOOPSSSS.....Cell (%d, %d) already taken. Pick another one plz.\n", p.row, p.col);
            continue;
        }

        if (!board_put(g->board, p, g->turn))
        {
            printf("sorryyyyy....Could not place piece at (%d, %d). Try again.\n", p.row, p.col);
            continue;
        }

        printf("Placed..yay %s at (%d, %d)\n", (g->turn == RED) ? "RED" : "BLUE", p.row, p.col);
        game_switch_turn(g);
    }
}
