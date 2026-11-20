#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * An integer X is "good" if there exists an element in the array smaller than X
 * and an element in the array larger than X.
 * Let min_val be the minimum value in the array A.
 * Let max_val be the maximum value in the array A.
 * 
 * For X to be good:
 * 1. There must exist A_i < X, which implies X > min_val.
 * 2. There must exist A_j > X, which implies X < max_val.
 * 
 * Therefore, X must satisfy: min_val < X < max_val.
 * The number of such integers is the count of integers in the open interval (min_val, max_val).
 * If min_val >= max_val (which happens if all elements are the same), there are no such integers.
 * Otherwise, the count is (max_val - min_val - 1).
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    int min_val = 101;
    int max_val = 0;
    
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        if (A[i] < min_val) min_val = A[i];
        if (A[i] > max_val) max_val = A[i];
    }
    
    if (min_val >= max_val) {
        cout << 0 << "\n";
    } else {
        // The number of integers X such that min_val < X < max_val
        // is (max_val - 1) - (min_val + 1) + 1 = max_val - min_val - 1
        cout << (max_val - min_val - 1) << "\n";
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