#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given an array A of size N. We need to find if there exists an array B 
 * of non-negative integers such that C_i = A_i + B_i forms a permutation of 1 to N.
 * 
 * Since B_i >= 0, it implies C_i >= A_i.
 * For C to be a permutation of 1 to N, every value from 1 to N must appear exactly once.
 * 
 * Let's sort the array A in non-decreasing order.
 * If we sort A, we have A_1 <= A_2 <= ... <= A_N.
 * To satisfy the condition, we need to map these A_i values to the set {1, 2, ..., N}
 * such that for each pair (A_i, C_i), A_i <= C_i.
 * 
 * If we sort A, the best strategy is to check if the i-th smallest element of A 
 * can be mapped to the i-th smallest value of the permutation (which is i+1).
 * Actually, it's simpler: if we sort A, then for every i from 0 to N-1, 
 * we must have A[i] <= (i + 1). 
 * If this condition holds for all i, then we can always find non-negative B_i 
 * such that C_i = i + 1.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    // Sort A to check the condition A[i] <= i+1
    sort(A.begin(), A.end());
    
    bool possible = true;
    for (int i = 0; i < N; ++i) {
        // The smallest available value in the permutation is i+1.
        // Since B_i >= 0, we must have A[i] <= C_i.
        // If the smallest A[i] is greater than the smallest available C_i,
        // we cannot form a permutation.
        if (A[i] > (i + 1)) {
            possible = false;
            break;
        }
    }
    
    if (possible) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
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