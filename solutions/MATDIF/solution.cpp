#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to fill an N x N matrix with numbers 1 to N^2 such that no two 
 * adjacent cells (including diagonals, 8-connectivity) have an absolute 
 * difference of 1.
 * 
 * Strategy:
 * A simple way to ensure the difference is > 1 is to place all odd numbers 
 * first, followed by all even numbers. 
 * 
 * Let's list all odd numbers from 1 to N^2 in increasing order, then all 
 * even numbers from 1 to N^2 in increasing order.
 * Example N=4:
 * Odds: 1, 3, 5, 7, 9, 11, 13, 15
 * Evens: 2, 4, 6, 8, 10, 12, 14, 16
 * Combined sequence: 1, 3, 5, 7, 9, 11, 13, 15, 2, 4, 6, 8, 10, 12, 14, 16
 * 
 * Filling the matrix row by row with this sequence works because:
 * 1. The difference between any two odd numbers is at least 2.
 * 2. The difference between any two even numbers is at least 2.
 * 3. The difference between the last odd number and the first even number 
 *    is |(largest odd) - 2| = |(N^2 or N^2-1) - 2|, which is > 1 for N >= 4.
 * 4. The transition between rows also maintains this property.
 */

void solve() {
    int N;
    cin >> N;
    vector<vector<int>> matrix(N, vector<int>(N));
    
    vector<int> sequence;
    // Add all odd numbers
    for (int i = 1; i <= N * N; i += 2) {
        sequence.push_back(i);
    }
    // Add all even numbers
    for (int i = 2; i <= N * N; i += 2) {
        sequence.push_back(i);
    }
    
    int idx = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            matrix[i][j] = sequence[idx++];
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
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}