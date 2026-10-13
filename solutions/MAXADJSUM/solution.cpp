#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

/**
 * Problem Analysis:
 * f(A) = (A_1 + A_2) + (A_2 + A_3) + ... + (A_{N-1} + A_N)
 * f(A) = A_1 + 2*A_2 + 2*A_3 + ... + 2*A_{N-1} + A_N
 * f(A) = 2 * sum(A) - (A_1 + A_N)
 * To maximize f(A), we must minimize (A_1 + A_N).
 * We sort the array and pick the two smallest elements as the ends.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    vector<long long> A(N);
    long long total_sum = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        total_sum += A[i];
    }
    
    sort(A.begin(), A.end());
    
    // The two smallest elements are A[0] and A[1]
    long long min_ends = A[0] + A[1];
    long long result = 2 * total_sum - min_ends;
    
    cout << result << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}