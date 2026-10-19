#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The condition requires that for any square submatrix, the sum of diagonal elements
 * must be even. This implies that the parity of M[r][c] must be the same as M[r+a][c+a],
 * and M[r][c+a] must have the same parity as M[r+a][c].
 * 
 * A simple way to satisfy this is to fill the matrix such that the parity of the 
 * elements follows a checkerboard pattern.
 * 
 * Let's fill the matrix with numbers 1 to N^2.
 * If we fill the matrix row by row:
 * Row 1: 1, 2, 3, ..., N
 * Row 2: N+1, N+2, ..., 2N
 * ...
 * 
 * To ensure the parity condition, we can alternate the order of filling for even rows.
 * For odd rows (1, 3, 5...), fill left to right.
 * For even rows (2, 4, 6...), fill right to left.
 * 
 * This ensures that adjacent cells have different parities, and the diagonal 
 * parity condition is satisfied because the parity of M[i][j] will be 
 * (i + j) % 2.
 */

void solve() {
    int N;
    cin >> N;
    
    int current = 1;
    vector<vector<int>> matrix(N, vector<int>(N));
    
    for (int i = 0; i < N; ++i) {
        if (i % 2 == 0) {
            // Fill left to right
            for (int j = 0; j < N; ++j) {
                matrix[i][j] = current++;
            }
        } else {
            // Fill right to left
            for (int j = N - 1; j >= 0; --j) {
                matrix[i][j] = current++;
            }
        }
    }
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << matrix[i][j] << (j == N - 1 ? "" : " ");
        }
        cout << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}