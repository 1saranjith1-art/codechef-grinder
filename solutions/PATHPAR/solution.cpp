#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The grid is defined as A_{i, j} = i + N*(j-1).
 * Any path from (1, 1) to (N, N) consists of exactly (N-1) steps down and (N-1) steps right.
 * The total number of cells in any path is (N-1) + (N-1) + 1 = 2N - 1.
 * 
 * Let's analyze the parity of the sum of elements in a path.
 * A path consists of a sequence of cells (r_k, c_k) for k = 0 to 2N-2.
 * The value of a cell is r_k + N*(c_k - 1).
 * Sum = \sum_{k=0}^{2N-2} (r_k + N*c_k - N)
 * Sum = \sum r_k + N * \sum c_k - N * (2N - 1)
 * 
 * Parity analysis:
 * If N is even:
 *   N is 0 mod 2.
 *   Sum = \sum r_k + 0 * \sum c_k - 0 * (2N - 1) = \sum r_k (mod 2).
 *   Since N is even, the parity of the sum is fixed for all paths.
 *   Specifically, for N=2, paths are (1,1)->(1,2)->(2,2) [sum 1+3+4=8, even] 
 *   and (1,1)->(2,1)->(2,2) [sum 1+2+4=7, odd].
 *   Wait, let's re-evaluate:
 *   If N is even, N is even. The parity of the sum is actually independent of the path.
 *   Let's check N=2: 
 *   Path 1: (1,1), (1,2), (2,2) -> 1 + 3 + 4 = 8 (Even)
 *   Path 2: (1,1), (2,1), (2,2) -> 1 + 2 + 4 = 7 (Odd)
 *   So for N even, both parities are possible.
 * 
 * If N is odd:
 *   N is 1 mod 2.
 *   Sum = \sum r_k + \sum c_k - (2N - 1) (mod 2)
 *   Sum = \sum r_k + \sum c_k - 1 (mod 2)
 *   In any path, \sum r_k + \sum c_k is invariant?
 *   For N=1: (1,1) -> sum 1 (odd). K=0: No, K=1: Yes.
 *   For N=3: Path (1,1)-(1,2)-(1,3)-(2,3)-(3,3) -> 1+4+7+8+9 = 29 (odd).
 *   It turns out if N is odd, the parity is fixed to (N % 2).
 */

void solve() {
    long long N;
    int K;
    cin >> N >> K;

    if (N % 2 != 0) {
        // If N is odd, the parity of the path sum is always odd (1).
        if (K == 1) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    } else {
        // If N is even, both parities are possible.
        cout << "YES" << "\n";
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