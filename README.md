# N-Queens Game

## 📌 Overview
This is a **C++ console-based game** based on the **N-Queens problem**, where the player must place queens on an **N × N** chessboard without any queen attacking another. The game **ends immediately** if a queen is placed in an attackable position.

## 🎮 How to Play
1. Run the program and enter the board size `N`.
2. Enter queen positions in the format: `row column` (0-based index).
3. Type `help` to highlight all attackable positions on the board.
4. The game ends if a queen is placed in an attackable position.

## ✨ Features
✅ **Custom Board Size** - Choose any value for `N`.
✅ **Live Attack Zone Highlighting** - Type `help` to see under-attack positions (`X`).
✅ **Chessboard Formatting** - Row and column numbers improve readability.
✅ **Instant Game Over** - Placing a queen under attack ends the game immediately.

## 🖥️ Installation & Execution
1. **Clone the repository:**
   ```sh
   git clone https://github.com/your-username/NQueensGame.git
   cd NQueensGame
   ```
2. **Compile the program:**
   ```sh
   g++ -o nqueens nqueens.cpp
   ```
3. **Run the game:**
   ```sh
   ./nqueens
   ```

## 📜 Code Structure
- `NQueensGame` class handles board mechanics and user input.
- `printBoard()` displays the chessboard with proper formatting.
- `isUnderAttack()` checks if a position is under attack.
- `play()` runs the game loop and takes user input.

## 🖼️ Example Gameplay
```
Enter board size (N): 5
Enter position: 2 3
     0  1  2  3  4
   ---------------
 0|  .  .  .  .  .
 1|  .  .  .  .  .
 2|  .  .  .  Q  .
 3|  .  .  .  .  .
 4|  .  .  .  .  .
```

## 🏆 Contributions
Feel free to submit **issues** or **pull requests** to improve the game! 🚀

## 📜 License
This project is licensed under the MIT License. See `LICENSE` for details.

