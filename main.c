#include <stdio.h>
#include <stdlib.h>
#include "../Header/twixtgame.h"

int main(void)
{
    Game *g = game_new();
    if (!g)
    {
        printf("Could not start the game.\n");
        return 1;
    }

    game_run(g);

    game_free(g);
    return 0;
}
