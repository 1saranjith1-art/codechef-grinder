#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given an array A of size N and we want to transform it into a permutation
 * of {1, 2, ..., N} using only increment operations.
 * 
 * 1. Since we can only increase elements, if an element A[i] is already greater 
 *    than N, it is impossible to transform it into any value in {1, ..., N}.
 *    Thus, if any A[i] > N, output -1.
 * 
 * 2. To minimize the total number of operations, we should sort the array A.
 *    Let the sorted array be A'. We want to map each A'[i] to a unique value 
 *    in {1, 2, ..., N}.
 * 
 * 3. After sorting, the optimal strategy is to match the smallest elements 
 *    of A' to the smallest available values in the target permutation {1, 2, ..., N}.
 *    Specifically, if A'[i] > (i + 1), it is impossible to reach (i + 1) 
 *    because we can only increase values.
 * 
 * 4. If A'[i] <= (i + 1), the cost to transform A'[i] to (i + 1) is (i + 1) - A'[i].
 *    Summing these costs gives the minimum operations.
 */

void solve() {
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    long long total_ops = 0;
    for (int i = 0; i < N; ++i) {
        // Target value for the i-th smallest element is (i + 1)
        long long target = i + 1;
        
        // If the current element is already greater than the target,
        // we cannot decrease it, so it's impossible.
        if (A[i] > target) {
            cout << -1 << "\n";
            return;
        }
        
        // Otherwise, we increase A[i] to target
        total_ops += (target - A[i]);
    }

    cout << total_ops << "\n";
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