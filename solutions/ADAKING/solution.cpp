#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to place a king at some position (r, c) and place obstacles such that
 * the king can reach exactly K cells.
 * 
 * A simple strategy:
 * Place the king at (0, 0).
 * Fill the board with '.' initially.
 * We need to mark 64 - K cells as 'X' (obstacles).
 * Since the king can reach all connected '.' cells starting from (0, 0),
 * we can simply fill the board row by row, column by column, and turn the 
 * remaining cells into 'X' until we have exactly K '.' cells left.
 * 
 * The king is at (0, 0), so it occupies 1 cell. We need K-1 more cells.
 */

void solve() {
    int K;
    cin >> K;

    char board[8][8];
    int count = 0;

    // Fill the board with '.' and place the king at (0, 0)
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (i == 0 && j == 0) {
                board[i][j] = 'O';
                count++;
            } else {
                if (count < K) {
                    board[i][j] = '.';
                    count++;
                } else {
                    board[i][j] = 'X';
                }
            }
        }
    }

    // Print the board
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            cout << board[i][j];
        }
        cout << "\n";
    }
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
        // The problem description says "The descriptions of the chessboard for each test case 
        // are separated by blank lines for clarity. Note that these lines should not appear 
        // on the output of your submission."
        // So we do not print extra newlines between test cases.
    }
    return 0;
}