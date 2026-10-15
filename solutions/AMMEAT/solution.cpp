#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N plates with P_i meatballs. We need at least M meatballs.
 * To minimize the number of plates, we should always pick the plates with the 
 * largest number of meatballs first (Greedy approach).
 * 
 * Algorithm:
 * 1. Read N and M.
 * 2. Read all P_i into a vector.
 * 3. Sort the vector in descending order.
 * 4. Calculate the prefix sum. If the total sum of all plates < M, output -1.
 * 5. Otherwise, iterate through the sorted plates and keep adding them until 
 *    the sum is >= M. The number of plates used is the answer.
 * 
 * Constraints:
 * N <= 7 (Wait, the problem description says N <= 7, but usually these problems 
 * have N up to 10^5. The logic holds regardless of N).
 * M, P_i <= 10^18, so use long long.
 */

void solve() {
    int n;
    long long m;
    cin >> n >> m;
    
    vector<long long> p(n);
    long long total_sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        total_sum += p[i];
    }
    
    // If total meatballs available are less than required, impossible.
    if (total_sum < m) {
        cout << -1 << "\n";
        return;
    }
    
    // Sort in descending order to pick largest plates first
    sort(p.rbegin(), p.rend());
    
    long long current_sum = 0;
    int count = 0;
    for (int i = 0; i < n; ++i) {
        current_sum += p[i];
        count++;
        if (current_sum >= m) {
            cout << count << "\n";
            return;
        }
    }
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