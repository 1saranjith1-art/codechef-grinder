#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N bags, each with A_i coins (A_i <= X).
 * We can change A_i to X at a cost of C.
 * We want to maximize (Sum of A_i) - (Total Cost).
 * 
 * For each bag i, if we perform the operation, the net change to the total sum is:
 * (X - A_i) - C.
 * 
 * If (X - A_i) - C > 0, it is beneficial to perform the operation.
 * This is equivalent to X - C > A_i.
 * If X - C <= A_i, performing the operation either decreases the total or keeps it the same,
 * so we should not perform it.
 * 
 * Time Complexity: O(N) per test case.
 * Space Complexity: O(1) auxiliary space (or O(N) to store the array).
 */

void solve() {
    int N;
    long long X, C;
    cin >> N >> X >> C;
    
    vector<long long> A(N);
    long long current_sum = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        current_sum += A[i];
    }
    
    long long total_profit = 0;
    long long operations = 0;
    
    for (int i = 0; i < N; ++i) {
        // Check if performing the operation increases the net value
        if (X - A[i] > C) {
            operations++;
        }
    }
    
    // The final sum will be the original sum minus the sum of A_i for bags changed,
    // plus (operations * X), minus (operations * C).
    // Simplified: (Original Sum) + operations * (X - C) - (sum of A_i for changed bags)
    // Actually, it's simpler:
    // Final Value = Sum(A_i for unchanged) + Sum(X for changed) - (operations * C)
    
    long long final_sum = 0;
    for (int i = 0; i < N; ++i) {
        if (X - A[i] > C) {
            final_sum += X;
        } else {
            final_sum += A[i];
        }
    }
    
    cout << final_sum - (operations * C) << "\n";
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