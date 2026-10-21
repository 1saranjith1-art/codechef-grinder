#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given N days of profit/loss. We need to skip exactly one day such that
 * the sum of the remaining N-1 days is maximized.
 * 
 * Let S be the sum of all N days.
 * If we skip day i, the total profit is S - A[i].
 * To maximize (S - A[i]), we need to minimize A[i].
 * Therefore, the optimal strategy is to find the minimum value in the array
 * and subtract it from the total sum of the array.
 * 
 * Complexity:
 * Time: O(N) per test case, O(sum of N) total.
 * Space: O(1) auxiliary space (excluding input storage).
 */

void solve() {
    int N;
    cin >> N;
    
    vector<long long> A(N);
    long long total_sum = 0;
    long long min_val = 200; // Constraints say A_i >= -100
    
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        total_sum += A[i];
        if (A[i] < min_val) {
            min_val = A[i];
        }
    }
    
    // The result is the total sum minus the smallest element
    cout << (total_sum - min_val) << "\n";
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