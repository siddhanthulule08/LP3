#include <iostream>
using namespace std;

const int N = 8;  // Change N for different board sizes
int board[N][N];

// Function to print the board
void printBoard() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << (board[i][j] ? "Q " : ". ");
        }
        cout << endl;
    }
}

// Function to check if placing a queen at (row, col) is safe
bool isSafe(int row, int col) {
    // Check column
    for (int i = 0; i < row; i++)
        if (board[i][col]) return false;

    // Check upper-left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j]) return false;

    // Check upper-right diagonal
    for (int i = row, j = col; i >= 0 && j < N; i--, j++)
        if (board[i][j]) return false;

    return true;
}

// Function to solve the n-Queens problem using backtracking
bool solve(int row) {
    if (row >= N) return true;  // All queens are placed

    for (int col = 0; col < N; col++) {
        if (isSafe(row, col)) {
            board[row][col] = 1;  // Place queen

            if (solve(row + 1))  // Move to the next row
                return true;

            board[row][col] = 0;  // Backtrack
        }
    }
    return false;  // No solution in this configuration
}

int main() {
    // Place the first queen at (0, 0) and solve from the second row
    board[0][0] = 1;
    
    if (solve(1)) {  // Start solving from the second row
        cout << "Solution for the " << N << "-Queens problem:\n";
        printBoard();
    } else {
        cout << "No solution exists.\n";
    }

    return 0;
}
