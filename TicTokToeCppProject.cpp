
#include <iostream>
#include <vector>

using namespace std;

//Function to  Print the game board 
void printBoard(const vector<char>& board) {
    cout << " " << board[0] << " | " << board[1] << " | " << board[2] << " \n";
    cout << "---+---+---\n";
    cout << " " << board[3] << " | " << board[4] << " | " << board[5] << " \n";
    cout << "---+---+---\n";
    cout << " " << board[6] << " | " << board[7] << " | " << board[8] << " \n";
}

// Check if the game has been won
bool checkWin(const vector<char>& board, char symbol) {
    if (board[0] == symbol && board[1] == symbol && board[2] == symbol) {
        return true;
    }
    if (board[3] == symbol && board[4] == symbol && board[5] == symbol) {
        return true;
    }
    if (board[6] == symbol && board[7] == symbol && board[8] == symbol) {
        return true;
    }
    if (board[0] == symbol && board[3] == symbol && board[6] == symbol) {
        return true;
    }
    if (board[1] == symbol && board[4] == symbol && board[7] == symbol) {
        return true;
    }
    if (board[2] == symbol && board[5] == symbol && board[8] == symbol) {
        return true;
    }
    if (board[0] == symbol && board[4] == symbol && board[8] == symbol) {
        return true;
    }
    if (board[2] == symbol && board[4] == symbol && board[6] == symbol) {
        return true;
    }
    return false;
}

int main() {
    vector<char> board(9, ' ');
    char player = 'X';

    cout << "Welcome to Tic Tac Toe!\n";
    cout << "Player 1: X\n";
    cout << "Player 2: O\n";
    cout << "To make a move, enter a number 1-9 corresponding to the position on the board.\n";
    cout << " 1 | 2 | 3 \n";
    cout << "---+---+---\n";
    cout << " 4 | 5 | 6 \n";
    cout << "---+---+---\n";
    cout << " 7 | 8 | 9 \n";

    for (int i = 0; i < 9; i++) {
        int move;
        cout << "Player " << player << ", make your move: ";
        cin >> move;

        if (move < 1 || move > 9 || board[move-1] != ' ') {
            cout << "Invalid move. Try again.\n";
            i--;
            continue;
        }

        board[move-1] = player;
        printBoard(board);

        if (checkWin(board, player)) {
            cout << "Player " << player << " wins!\n";
            return 0;
        }

        player = (player == 'X') ? 'O' : 'X';
    }

    cout << "It's a tie!\n";
    return 0;
}
