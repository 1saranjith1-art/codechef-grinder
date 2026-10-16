#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The operation S[i] = max(S[i], S[i+1]) effectively propagates a '1' from right to left.
 * If we have a '1' at index j, we can move it to any index i < j using (j - i) operations.
 * Specifically, if we have a '1' at index j, we can make all positions from i to j equal to '1'
 * using (j - i) operations.
 * 
 * Since N is very small (N <= 10), we can observe that the operation allows us to 
 * "pull" a 1 to the left. If we have a 1 at index j, we can fill all positions 
 * from i to j with 1s using j-i operations.
 * 
 * Given the constraints and the nature of the operation, this is equivalent to:
 * We can pick a '1' at index j and use k operations to turn k positions to its left into '1's.
 * Since we want to maximize the total number of 1s, we should identify all existing 1s
 * and use our K operations to expand them to the left as much as possible.
 * 
 * Because N is small, we can simulate the process or use a greedy approach.
 * The optimal strategy is to always use the operation to turn a '0' into a '1' if there is 
 * a '1' to its right.
 */

void solve() {
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;

    // Since N is very small (up to 10), we can use a simple greedy approach.
    // In each step, if we have K > 0, we look for an index i such that S[i] == '0'
    // and there exists some j > i where S[j] == '1'.
    // To maximize 1s, we should prioritize turning '0's that are adjacent to '1's.
    
    for (int k = 0; k < K; ++k) {
        bool changed = false;
        for (int i = 0; i < N - 1; ++i) {
            if (S[i] == '0' && S[i + 1] == '1') {
                S[i] = '1';
                changed = true;
                break;
            }
        }
        if (!changed) break;
    }

    int count = 0;
    for (char c : S) {
        if (c == '1') count++;
    }
    cout << count << "\n";
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