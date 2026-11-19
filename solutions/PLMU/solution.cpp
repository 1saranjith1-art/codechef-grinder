#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to find the number of pairs (i, j) with 1 <= i < j <= N such that:
 * A_i + A_j = A_i * A_j
 * 
 * Rearranging the equation:
 * A_i * A_j - A_i - A_j = 0
 * A_i * A_j - A_i - A_j + 1 = 1
 * (A_i - 1) * (A_j - 1) = 1
 * 
 * Since A_i are integers, the only possible integer factors of 1 are:
 * 1) (A_i - 1) = 1  AND (A_j - 1) = 1  => A_i = 2, A_j = 2
 * 2) (A_i - 1) = -1 AND (A_j - 1) = -1 => A_i = 0, A_j = 0
 * 
 * Thus, we only need to count the number of 2s and the number of 0s in the array.
 * If there are 'c2' twos, the number of pairs (i, j) with A_i = A_j = 2 is c2 * (c2 - 1) / 2.
 * If there are 'c0' zeros, the number of pairs (i, j) with A_i = A_j = 0 is c0 * (c0 - 1) / 2.
 * The total number of valid pairs is the sum of these two values.
 */

void solve() {
    int N;
    cin >> N;
    
    long long count0 = 0;
    long long count2 = 0;
    
    for (int i = 0; i < N; ++i) {
        long long val;
        cin >> val;
        if (val == 0) {
            count0++;
        } else if (val == 2) {
            count2++;
        }
    }
    
    // Number of ways to choose 2 items from count0 is count0 * (count0 - 1) / 2
    // Number of ways to choose 2 items from count2 is count2 * (count2 - 1) / 2
    long long pairs0 = (count0 * (count0 - 1)) / 2;
    long long pairs2 = (count2 * (count2 - 1)) / 2;
    
    cout << (pairs0 + pairs2) << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}