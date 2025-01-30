#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

class NQueensGame {
private:
    int n;
    vector<vector<char>> board;
    vector<pair<int, int>> queens;

    bool isUnderAttack(int x, int y) {
        for (auto &q : queens) {
            int qx = q.first, qy = q.second;
            if (qx == x || qy == y || abs(qx - x) == abs(qy - y)) {
                return true;
            }
        }
        return false;
    }

    void printBoard(bool highlightAttacks = false) {
        vector<vector<char>> tempBoard = board;

        if (highlightAttacks) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (tempBoard[i][j] == '.' && isUnderAttack(i, j)) {
                        tempBoard[i][j] = 'X';
                    }
                }
            }
        }

        
        cout << "   "; 
        for (int j = 0; j < n; j++) {
            cout << setw(3) << j;
        }
        cout << "\n";

        cout << "   " << string(n * 3, '-') << "\n";

        for (int i = 0; i < n; i++) {
            cout << setw(2) << i << "|"; 
            for (int j = 0; j < n; j++) {
                cout << setw(3) << tempBoard[i][j];
            }
            cout << "\n";
        }
    }

public:
    NQueensGame(int size) : n(size), board(size, vector<char>(size, '.')) {}

    void play() {
        cout << "Enter queen positions as 'row column' (0-based index)." << endl;
        cout << "Type 'help' to see all under-attack positions." << endl;
        cout << "Game ends if a queen can attack another." << endl;
        printBoard();

        while (true) {
            string input;
            cout << "Enter position: ";
            cin >> input;

            if (input == "help") {
                cout << "Under attack positions (X marked):" << endl;
                printBoard(true);
                continue;
            }

            int x, y;
            try {
                x = stoi(input);
                cin >> y;
            } catch (...) {
                cout << "Invalid input. Use 'row column' or type 'help'." << endl;
                continue;
            }

            if (x < 0 || x >= n || y < 0 || y >= n) {
                cout << "Invalid position. Try again." << endl;
                continue;
            }

            if (board[x][y] == 'Q') {
                cout << "Position already occupied. Try again." << endl;
                continue;
            }

            if (isUnderAttack(x, y)) {
                cout << "Game Over! The queen at (" << x << ", " << y << ") is under attack." << endl;
                break;
            }

            board[x][y] = 'Q';
            queens.push_back({x, y});
            printBoard();
        }
    }
};

int main() {
    int n;
    cout << "Enter board size (N): ";
    cin >> n;

    NQueensGame game(n);
    game.play();

    return 0;
}
