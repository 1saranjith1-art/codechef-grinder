#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem Analysis:
 * We need to buy items 1 to m.
 * Cost = (Sum of A[0...m-1]) - (Max of A[0...m-1]).
 * We need Cost <= K.
 * Since the cost function is monotonically non-decreasing with m,
 * we can binary search for the maximum m.
 */

bool can_buy(int m, long long K, const vector<long long>& A, const vector<long long>& prefix_sum, const vector<int>& prefix_max) {
    if (m == 0) return true;
    long long total_sum = prefix_sum[m];
    long long max_val = prefix_max[m];
    return (total_sum - max_val) <= K;
}

void solve() {
    int N;
    long long K;
    cin >> N >> K;
    vector<long long> A(N);
    vector<long long> prefix_sum(N + 1, 0);
    vector<int> prefix_max(N + 1, 0);

    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        prefix_sum[i + 1] = prefix_sum[i] + A[i];
        prefix_max[i + 1] = max((long long)prefix_max[i], A[i]);
    }

    int low = 0, high = N, ans = 0;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (can_buy(mid, K, A, prefix_sum, prefix_max)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}