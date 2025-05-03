# Snake Game (Snike)

## Project Description

Snike is a classic Snake game implemented in C. In this project, the player controls a snake that moves around the screen to collect apples. Each time the snake eats an apple, it grows longer. The game ends if the snake collides with itself or the walls. The game includes three modes: **manual control** and two levels of **automatic control** (slow and fast).

The game is designed for terminal environments and uses UNIX system calls to handle input and output. The game logic and rendering are implemented using standard C libraries.

## Features

- **3 modes of play:**
  - **Manual Mode:** You control the snake using keyboard inputs (`WASD` keys).
  - **Automatic Modes:** The snake moves automatically with two speeds, slow and fast.
  
- **Snake Growth:** The snake grows after eating apples.
- **Collision Detection:** The game ends if the snake hits the wall or itself.
- **Apple Generation:** Apples are generated at random locations on the screen.
- **Score Tracking:** Displays score based on the number of apples eaten.
  
## How to Use

### Controls

- **Manual Mode:**
  - Use the `W`, `A`, `S`, `D` keys to control the snake (Up, Left, Down, Right).
  
- **Automatic Mode:**
  - The game will automatically move the snake. You can switch between fast and slow modes.

### Modes

- **Manual Mode (default)**: The snake is controlled by the user via the keyboard.
- **Auto Fast Mode**: The snake moves at a fast speed automatically.
- **Auto Slow Mode**: The snake moves at a slower speed automatically.

### Game Over

- The game will end when the snake collides with itself or the wall.
- The score is displayed at the end.

## Installation

### Prerequisites

- A UNIX-based operating system (Linux/macOS).
- GCC (GNU Compiler Collection) installed for compiling C programs.

### Steps to Install

1. **Clone the repository** (or download the source files):

   ```bash
   git clone https://your-repository-url.git
   cd snike
   ```

2. **Compile the program**:

   If you have `main.c`, `snike.c`, and `snike.h` files in the same directory, you can compile them using GCC:

   ```bash
   gcc -o snike main.c snike.c
   ```

3. **Run the program**:

   After compiling, you can run the game using:

   ```bash
   ./snike
   ```

## Methods Used

### `snike.h`

- **`initGame()`**: Initializes the game state.
- **`drawGame()`**: Renders the game.
- **`moveSnake()`**: Updates snake position.
- **`checkCollision()`**: Ends game on collision.
- **`generateApples()`**: Creates apples randomly.
- **`isApple()`**: Checks if apple is at a location.
- **`updateDirection()`**: Updates direction from input.
- **`kbhit()` / `getch()`**: Non-blocking input.

### `snike.c`

Contains the implementations of game functions.

### `main.c`

Handles the main game loop and mode selection.

## Contributing

If you would like to contribute to this project, feel free to fork the repository, make changes, and submit a pull request. Ensure that you test your changes thoroughly.

## License

This project is licensed under the trsvu1 License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments

- Implemented using C programming language and standard libraries.
