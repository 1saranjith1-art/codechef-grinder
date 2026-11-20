#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need (Sum * Product) < 0 for every row and every column.
 * 
 * Case 1: N is even.
 * If we fill the entire grid with -1:
 * Sum of each row/column = N * (-1) = -N.
 * Product of each row/column = (-1)^N = 1 (since N is even).
 * Sum * Product = -N * 1 = -N < 0.
 * This satisfies the condition for all rows and columns.
 * 
 * Case 2: N is odd.
 * If we fill the entire grid with -1, Product = (-1)^N = -1.
 * Sum = -N. Sum * Product = (-N) * (-1) = N > 0. (Fails)
 * 
 * We need to change the product to 1 or the sum to positive.
 * If we set the diagonal elements (i, i) to 1, we change the product of row i and column i.
 * For N=3:
 * 1 -1 -1
 * -1 1 -1
 * -1 -1 1
 * Row 0: Sum = -1, Prod = 1. Sum*Prod = -1 < 0. (Correct)
 * This pattern works for any odd N.
 */

void solve() {
    int N;
    cin >> N;
    if (N % 2 == 0) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cout << -1 << (j == N - 1 ? "" : " ");
            }
            cout << "\n";
        }
    } else {
        // For odd N, place 1s on the main diagonal and -1s elsewhere.
        // This makes each row/column have (N-1) -1s and one 1.
        // Sum = (N-1)*(-1) + 1 = -N + 2.
        // Product = (-1)^(N-1) * 1 = 1.
        // Sum * Product = -N + 2. Since N >= 3, -N + 2 < 0.
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (i == j) {
                    cout << 1 << (j == N - 1 ? "" : " ");
                } else {
                    cout << -1 << (j == N - 1 ? "" : " ");
                }
            }
            cout << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}