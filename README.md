# 🐍 Snike - Terminal Snake Game

Welcome to **Snike**, a classic Snake game built in **C** and playable directly from your terminal!  
This version adds fun gameplay mechanics and includes features like auto mode, adjustable speeds, and game saving functionality.

---

## 🚀 Features

- 🎮 Classic Snake mechanics
- 🍎 Eat 3 apples to grow
- 🧱 Collision detection (walls & self)
- 💾 Save and load functionality (planned)
- 🧠 Auto-play mode with two speeds
- 🖥️ Works on macOS and Linux terminals

---

## 📦 Files Structure

- `main.c` – Main game loop
- `snike.c` – Core game logic (drawing, movement, collisions)
- `snike.h` – Header file with data structures and function declarations

---

## ⚙️ Installation & Compilation

### ✅ Prerequisites

- A C compiler like `gcc`
- Works on macOS or Linux terminal (uses `termios` & `unistd`)

### 🧪 Compile the project

```bash
gcc main.c snike.c -o snike
```

### ▶️ Run the game

```bash
./snike
```

---

## 🎮 Controls

Use the following keys to play:

- `W` – Move Up
- `S` – Move Down
- `A` – Move Left
- `D` – Move Right

Press any of these keys during the game to change direction.

---

## 🛠️ Methods Used

- `termios.h` & `fcntl.h` for keyboard input without Enter
- `usleep()` from `unistd.h` for timing/speed
- Simple `printf` drawing with ANSI escape codes
- Enum-based direction and game mode control

---

## 💡 Future Improvements

- ✅ Auto mode (slow/fast)
- ✅ Unix-compatible `getch()` and `kbhit()`
- ⏳ Add save/load functionality with files
- 🔊 Add optional sound feedback (beep)
- 🎨 Better UI/UX in terminal

---

## 🧠 Author & License

Created by trsvu1 for classic games.  
Free to use, modify, and learn from.

License: MIT

---
Enjoy playing **Snike** and improving your C programming! 🐍
