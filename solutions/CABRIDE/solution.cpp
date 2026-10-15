#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A cab can hold at most 4 people.
 * Cost for X people in one cab = max(200, 100 * X).
 * 
 * If we put 1 person in a cab, cost = max(200, 100) = 200.
 * If we put 2 people in a cab, cost = max(200, 200) = 200.
 * If we put 3 people in a cab, cost = max(200, 300) = 300.
 * If we put 4 people in a cab, cost = max(200, 400) = 400.
 * 
 * To minimize cost, we want to maximize the number of people per cab while keeping 
 * the cost per person low. 
 * Notice that 2 people in one cab costs 200 (100 per person), while 1 person costs 200.
 * 4 people in one cab costs 400 (100 per person).
 * 
 * Since we want to minimize total cost, we should fill cabs as much as possible.
 * For N people, we need ceil(N / 4) cabs.
 * However, we can distribute people to minimize the cost function.
 * Actually, the cost function max(200, 100 * X) is equivalent to 100 * max(2, X).
 * Total cost = sum of 100 * max(2, X_i) for each cab i.
 * To minimize this, we should make X_i as close to 2 as possible if X_i < 2, 
 * or as close to 4 as possible if we want to utilize the capacity.
 * 
 * Given the constraints N <= 50, we can use dynamic programming or a greedy approach.
 * Since each cab can take at most 4, and the cost is 100 * max(2, X), 
 * the optimal strategy is to use as many 4-person cabs as possible, 
 * and handle the remainder.
 */

void solve() {
    int N;
    cin >> N;
    
    // dp[i] = minimum cost to transport i people
    vector<long long> dp(N + 1, 1e18);
    dp[0] = 0;
    
    for (int i = 1; i <= N; ++i) {
        // Try putting j people in the last cab (1 <= j <= 4)
        for (int j = 1; j <= 4 && i - j >= 0; ++j) {
            long long cost = max(200, 100 * j);
            dp[i] = min(dp[i], dp[i - j] + cost);
        }
    }
    
    cout << dp[N] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}