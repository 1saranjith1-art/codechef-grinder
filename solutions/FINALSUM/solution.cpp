#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * In one operation on [L, R], we add 1 to A[L], subtract 1 from A[L+1], 
 * add 1 to A[L+2], subtract 1 from A[L+3], and so on.
 * 
 * Let's look at the change in the total sum of the array:
 * The sequence of changes is +1, -1, +1, -1, ...
 * - If the length of the subarray (R - L + 1) is even, there are an equal 
 *   number of +1s and -1s. The net change to the sum is 0.
 * - If the length of the subarray (R - L + 1) is odd, there is one more +1 
 *   than -1. The net change to the sum is +1.
 * 
 * Therefore, for each query [L, R], the total sum increases by 1 if (R - L + 1) 
 * is odd, and increases by 0 if (R - L + 1) is even.
 * 
 * (R - L + 1) is odd if and only if (R - L) is even.
 * (R - L) is even if L and R have the same parity (both odd or both even).
 * 
 * Complexity:
 * Time: O(N + Q) per test case.
 * Space: O(N) to store the initial array.
 */

void solve() {
    int N, Q;
    if (!(cin >> N >> Q)) return;
    
    long long current_sum = 0;
    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val;
        current_sum += val;
    }
    
    for (int i = 0; i < Q; ++i) {
        int L, R;
        cin >> L >> R;
        // Length = R - L + 1
        // If length is odd, sum increases by 1
        if ((R - L + 1) % 2 != 0) {
            current_sum += 1;
        }
    }
    
    cout << current_sum << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}