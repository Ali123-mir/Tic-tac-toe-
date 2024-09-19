#include <iostream>
using namespace std;

char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
char currentPlayer = 'X';

void displayBoard() {
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

bool isMoveValid(int move) {
    if (move < 1 || move > 9) return false;
    int row = (move - 1) / 3;
    int col = (move - 1) % 3;
    return (board[row][col] != 'X' && board[row][col] != 'O');
}

void makeMove(int move, char player) {
    int row = (move - 1) / 3;
    int col = (move - 1) % 3;
    board[row][col] = player;
}

bool checkWin() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||
            (board[0][i] == board[1][i] && board[1][i] == board[2][i]))
            return true;
    }
    // Check diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0]))
        return true;
   
    return false;
}

bool checkTie() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int move;
    bool gameWon = false, gameTie = false;

    while (!gameWon && !gameTie) {
        displayBoard();
        cout << "Player " << currentPlayer << ", enter a move (1-9): ";
        cin >> move;

        if (cin.fail() || !isMoveValid(move)) {
            cin.clear(); // clear error flags
            cin.ignore(10000, '\n');
            cout << "Invalid move! Try again." << endl;
        } else {
            makeMove(move, currentPlayer);
            gameWon = checkWin();
            if (gameWon) {
                displayBoard();
                cout << "Player " << currentPlayer << " wins!" << endl;
            } else if (checkTie()) {
                displayBoard();
                cout << "It's a tie!" << endl;
                gameTie = true;
            } else {
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        }
    }

    return 0;
}
