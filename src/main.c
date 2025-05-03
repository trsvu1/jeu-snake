#include <stdio.h>
#include <stdlib.h>
#include "snike.h"

int main() {
    GameState game;
    initGame(&game);

    while (!game.gameOver) {
        drawGame(&game);

        if (kbhit()) {
            updateDirection(&game);
        }

        moveSnake(&game);
        game.gameOver = checkCollision(&game);

        delay((game.mode == AUTO_FAST) ? 100 : (game.mode == AUTO_SLOW) ? 300 : 200);
    }

    printf("\nGAME OVER! Score: %d\n", game.score);
    return 0;
}