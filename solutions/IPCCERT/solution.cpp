#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given N students, each watched K lectures.
 * For each student, we have the duration of K lectures and the number of questions asked (Q_i).
 * Criteria for certificate:
 * 1. Total time watched >= M
 * 2. Questions asked <= 10
 * 
 * Constraints:
 * N, K <= 1000
 * M <= 10^6
 * T_{i,j} <= 1000
 * Q_i <= 10^6
 * 
 * Total time per student can be up to 1000 * 1000 = 1,000,000.
 * This fits within a standard 32-bit integer, but using long long is safer 
 * and good practice in competitive programming to avoid overflow.
 * Time complexity: O(N * K), which is 10^6 operations, well within the 3s limit.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    long long M;
    int K;

    if (!(cin >> N >> M >> K)) return 0;

    int eligible_count = 0;

    for (int i = 0; i < N; ++i) {
        long long total_time = 0;
        for (int j = 0; j < K; ++j) {
            int time_watched;
            cin >> time_watched;
            total_time += time_watched;
        }
        
        int questions;
        cin >> questions;

        // Check criteria
        if (total_time >= M && questions <= 10) {
            eligible_count++;
        }
    }

    cout << eligible_count << "\n";

    return 0;
}