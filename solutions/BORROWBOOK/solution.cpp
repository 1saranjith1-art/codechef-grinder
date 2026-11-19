#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N books. The i-th book (1-indexed) was returned i days late.
 * The i-th book was returned on day A_i.
 * Rule: If multiple books are returned on the same day, only the maximum 
 * penalty (number of days late) among them is counted for that day.
 * 
 * Strategy:
 * 1. Create a map or an array to store the maximum penalty for each day.
 * 2. Since A_i can be up to 10^5, an array of size 100001 is sufficient.
 * 3. Iterate through each book i (from 1 to N):
 *    - The penalty for book i is i.
 *    - The day it was returned is A_i.
 *    - Update max_penalty[A_i] = max(max_penalty[A_i], i).
 * 4. Sum up all values in the max_penalty array.
 * 5. Use long long for the total sum to prevent overflow, although with N=10^5,
 *    the max possible sum is roughly sum(1..10^5) = 5*10^9, which exceeds 32-bit int.
 */

void solve() {
    int N;
    cin >> N;
    
    // Using a vector to store the maximum penalty for each day.
    // Constraints: A_i <= 10^5.
    vector<int> max_penalty(100001, 0);
    
    for (int i = 1; i <= N; ++i) {
        int day;
        cin >> day;
        // The penalty for the i-th book is i.
        if (i > max_penalty[day]) {
            max_penalty[day] = i;
        }
    }
    
    long long total_penalty = 0;
    for (int i = 1; i <= 100000; ++i) {
        total_penalty += max_penalty[i];
    }
    
    cout << total_penalty << "\n";
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