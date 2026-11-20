#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The alternating sum is A_1 - A_2 + A_3 - A_4 + ...
 * Let N be the length of the array.
 * If N is even, there are N/2 positive terms and N/2 negative terms.
 * If N is odd, there are (N+1)/2 positive terms and (N-1)/2 negative terms.
 * 
 * To maximize the sum, we should assign the largest elements to the positive positions
 * and the smallest elements to the negative positions.
 * 
 * Let the sorted array be A_1 <= A_2 <= ... <= A_N.
 * 
 * Case 1: N is even (N = 2k)
 * We have k positive positions and k negative positions.
 * We pick the k largest elements for the positive positions and the k smallest for the negative.
 * Sum = (A_{k+1} + ... + A_{2k}) - (A_1 + ... + A_k)
 * 
 * Case 2: N is odd (N = 2k + 1)
 * We have k+1 positive positions and k negative positions.
 * We pick the k+1 largest elements for the positive positions and the k smallest for the negative.
 * Sum = (A_{k+1} + ... + A_{2k+1}) - (A_1 + ... + A_k)
 */

void solve() {
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    long long sum = 0;
    int k = N / 2;

    // The first k elements are subtracted
    for (int i = 0; i < k; ++i) {
        sum -= A[i];
    }
    // The remaining elements are added
    for (int i = k; i < N; ++i) {
        sum += A[i];
    }

    cout << sum << "\n";
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