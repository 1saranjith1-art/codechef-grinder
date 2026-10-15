#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N workers with salaries W_i.
 * An operation consists of choosing one worker and increasing everyone else's salary by 1.
 * This is equivalent to saying: the chosen worker's salary remains the same, 
 * while everyone else's salary increases by 1.
 * 
 * Let the target salary for all workers be S. Since we can only increase salaries,
 * S must be at least the maximum salary currently present in the array.
 * However, notice that increasing everyone except one worker by 1 is equivalent to 
 * decreasing that one worker's salary by 1 relative to the others.
 * 
 * Specifically, if we want to equalize all salaries to the minimum value currently 
 * in the array, we would need to perform operations to bring everyone down to that 
 * minimum. But we can only increase.
 * 
 * Let the minimum salary be 'min_w'. To make all salaries equal to some value S,
 * each worker i needs (S - W_i) increments.
 * In one operation, we increase (N-1) workers by 1.
 * Total increments needed = sum(S - W_i) for all i.
 * Each operation contributes (N-1) to the total sum of increments.
 * 
 * Actually, there is a simpler observation:
 * Increasing everyone except worker i by 1 is equivalent to decreasing worker i 
 * by 1 relative to the others. To equalize all to the minimum value, we need 
 * to perform (W_i - min_w) operations for each worker i.
 * Total operations = sum(W_i - min_w) for all i.
 * 
 * Time Complexity: O(N) per test case.
 * Space Complexity: O(N) to store the salaries.
 */

void solve() {
    int n;
    cin >> n;
    vector<long long> w(n);
    long long min_w = 20000; // Larger than max constraint 10000
    long long sum_w = 0;
    
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
        if (w[i] < min_w) {
            min_w = w[i];
        }
        sum_w += w[i];
    }
    
    // The total number of operations is the sum of differences between 
    // each salary and the minimum salary.
    long long total_ops = 0;
    for (int i = 0; i < n; ++i) {
        total_ops += (w[i] - min_w);
    }
    
    cout << total_ops << "\n";
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