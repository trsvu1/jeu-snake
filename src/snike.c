#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <termios.h>
#include <fcntl.h>
#include "snike.h"

void delay(int milliseconds) {
    usleep(milliseconds * 1000);
}

int kbhit(void) {
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
}

int getch(void) {
    struct termios oldt, newt;
    int ch;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);

    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    return ch;
}

void initGame(GameState *game) {
    srand(time(NULL));
    game->snake.length = 3;
    game->snake.body[0] = (Point){WIDTH / 2, HEIGHT / 2};
    game->snake.body[1] = (Point){WIDTH / 2 - 1, HEIGHT / 2};
    game->snake.body[2] = (Point){WIDTH / 2 - 2, HEIGHT / 2};
    game->snake.dir = RIGHT;
    game->applesEaten = 0;
    game->mode = MANUAL;
    game->score = 0;
    game->gameOver = 0;
    generateApples(game);
}

void drawGame(GameState *game) {
    printf("\033[H\033[J"); // clear screen (portable)
    for (int y = 0; y <= HEIGHT; y++) {
        for (int x = 0; x <= WIDTH; x++) {
            int printed = 0;

            if (y == 0 || y == HEIGHT || x == 0 || x == WIDTH) {
                printf("#");
                continue;
            }

            if (game->snake.body[0].x == x && game->snake.body[0].y == y) {
                printf("o");
                continue;
            }

            for (int i = 1; i < game->snake.length; i++) {
                if (game->snake.body[i].x == x && game->snake.body[i].y == y) {
                    printf("0");
                    printed = 1;
                    break;
                }
            }

            for (int i = 0; i < 3; i++) {
                if (game->apples[i].x == x && game->apples[i].y == y) {
                    printf("*");
                    printed = 1;
                    break;
                }
            }

            if (!printed) printf(" ");
        }
        printf("\n");
    }

    printf("Score: %d | Apples eaten this round: %d/3\n", game->score, game->applesEaten);
}

void generateApples(GameState *game) {
    for (int i = 0; i < 3; i++) {
        game->apples[i].x = 1 + rand() % (WIDTH - 2);
        game->apples[i].y = 1 + rand() % (HEIGHT - 2);
    }
}

int isApple(Point p, GameState *game) {
    for (int i = 0; i < 3; i++) {
        if (game->apples[i].x == p.x && game->apples[i].y == p.y) return i;
    }
    return -1;
}

void moveSnake(GameState *game) {
    Point next = game->snake.body[0];
    switch (game->snake.dir) {
        case UP:    next.y--; break;
        case DOWN:  next.y++; break;
        case LEFT:  next.x--; break;
        case RIGHT: next.x++; break;
    }

    for (int i = game->snake.length - 1; i > 0; i--) {
        game->snake.body[i] = game->snake.body[i - 1];
    }
    game->snake.body[0] = next;

    int appleIndex = isApple(next, game);
    if (appleIndex != -1) {
        game->applesEaten++;
        game->score += 10;
        generateApples(game);

        if (game->applesEaten == 3 && game->snake.length < MAX_LENGTH) {
            game->snake.length++;
            game->applesEaten = 0;
        }
    }
}

int checkCollision(GameState *game) {
    Point head = game->snake.body[0];

    if (head.x <= 0 || head.x >= WIDTH || head.y <= 0 || head.y >= HEIGHT) return 1;

    for (int i = 1; i < game->snake.length; i++) {
        if (head.x == game->snake.body[i].x && head.y == game->snake.body[i].y) return 1;
    }

    return 0;
}

void updateDirection(GameState *game) {
    char key = getch();
    switch (key) {
        case 'w': if (game->snake.dir != DOWN)  game->snake.dir = UP;    break;
        case 's': if (game->snake.dir != UP)    game->snake.dir = DOWN;  break;
        case 'a': if (game->snake.dir != RIGHT) game->snake.dir = LEFT;  break;
        case 'd': if (game->snake.dir != LEFT)  game->snake.dir = RIGHT; break;
    }
}