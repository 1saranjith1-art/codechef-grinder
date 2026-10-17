#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given N types of donuts with initial counts A_1, A_2, ..., A_N.
 * M customers arrive sequentially, each wanting a specific type B_i.
 * If the count of type B_i is > 0, we decrement the count and the customer is satisfied.
 * If the count is 0, the customer is sad.
 * We need to count the total number of sad customers.
 * 
 * Constraints:
 * T <= 100, N <= 100, M <= 100, A_i <= 100.
 * A simple simulation approach will have a time complexity of O(T * M),
 * which is well within the 1s time limit (100 * 100 = 10,000 operations).
 */

void solve() {
    int N, M;
    if (!(cin >> N >> M)) return;

    // Use a vector to store donut counts. 
    // Since types are 1-indexed, we use size N+1.
    vector<int> A(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    int sad_customers = 0;
    for (int i = 0; i < M; ++i) {
        int type;
        cin >> type;
        
        // Check if the requested donut type is available
        if (A[type] > 0) {
            A[type]--;
        } else {
            // No donuts left of this type, customer is sad
            sad_customers++;
        }
    }

    cout << sad_customers << "\n";
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}