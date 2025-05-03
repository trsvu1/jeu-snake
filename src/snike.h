#ifndef SNIKE_H
#define SNIKE_H

#define WIDTH 40
#define HEIGHT 20
#define MAX_LENGTH 100

typedef enum { UP, DOWN, LEFT, RIGHT } Direction;
typedef enum { MANUAL, AUTO_SLOW, AUTO_FAST } Mode;

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point body[MAX_LENGTH];
    int length;
    Direction dir;
} Snake;

typedef struct {
    Snake snake;
    Point apples[3];
    int applesEaten;
    Mode mode;
    int score;
    int gameOver;
} GameState;

void initGame(GameState *game);
void drawGame(GameState *game);
void moveSnake(GameState *game);
int checkCollision(GameState *game);
void generateApples(GameState *game);
int isApple(Point p, GameState *game);
void updateDirection(GameState *game);

// Unix equivalents
int kbhit(void);
int getch(void);
void delay(int milliseconds);

#endif