#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given N members. Each member i reports to Ri.
 * A potential killer is someone who nobody reports to.
 * This means we need to find all indices j (1 to N) such that 
 * no member i has Ri == j.
 * 
 * Approach:
 * 1. Create a boolean array (or frequency array) 'is_reported' of size N+1, initialized to false.
 * 2. Iterate through the input array R. For each Ri, if Ri != 0, mark is_reported[Ri] = true.
 * 3. After processing all members, iterate from 1 to N. If is_reported[i] is false, 
 *    then index i is a potential killer.
 * 4. Print these indices in ascending order.
 * 
 * Complexity:
 * Time: O(N) to read input and O(N) to iterate through the array. Total O(N).
 * Space: O(N) to store the status of each member.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    // is_reported[i] will be true if someone reports to member i
    vector<bool> is_reported(N + 1, false);

    for (int i = 0; i < N; ++i) {
        int r;
        cin >> r;
        // If r is 0, it's the Don, nobody reports to the Don in the context of 
        // the reporting structure (the Don is the root).
        // If r > 0, member r is being reported to.
        if (r >= 0 && r <= N) {
            is_reported[r] = true;
        }
    }

    // Collect and print all members who are not reported to
    bool first = true;
    for (int i = 1; i <= N; ++i) {
        if (!is_reported[i]) {
            if (!first) {
                cout << " ";
            }
            cout << i;
            first = false;
        }
    }
    cout << "\n";

    return 0;
}