#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have an N x M grid of students. Each student must move to an adjacent cell.
 * This is equivalent to finding a perfect matching in the grid graph where each 
 * node (cell) is matched with an adjacent node.
 * 
 * A grid graph is a bipartite graph. A perfect matching exists if and only if 
 * the total number of vertices (N * M) is even and the graph satisfies Hall's 
 * Marriage Theorem conditions.
 * 
 * Specifically for a grid graph:
 * 1. If N * M is odd, it is impossible to have a perfect matching because 
 *    the number of black and white cells in a checkerboard coloring will differ by 1.
 * 2. If N * M is even, we can always find a perfect matching.
 *    - If N is even, we can pair each row with itself by matching (i, j) with (i, j+1) 
 *      for all j in steps of 2.
 *    - If M is even, we can pair each column with itself by matching (i, j) with (i+1, j) 
 *      for all i in steps of 2.
 * 
 * Therefore, the condition for "YES" is simply that (N * M) is even, which is 
 * equivalent to saying at least one of N or M must be even.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n, m;
        cin >> n >> m;

        // If either N or M is even, the total number of cells N*M is even.
        // A perfect matching exists if and only if the total number of cells is even.
        if (n % 2 == 0 || m % 2 == 0) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}