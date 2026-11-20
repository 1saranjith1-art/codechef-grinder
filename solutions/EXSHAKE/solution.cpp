#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N groups with sizes A_i.
 * If we invite a set of groups with total people P, the number of handshakes is P*(P-1)/2.
 * We want to maximize the number of groups invited such that P*(P-1)/2 <= M.
 * 
 * Since we want to maximize the number of groups, we should always pick the groups 
 * with the smallest number of people first. This is a greedy approach.
 * 
 * Algorithm:
 * 1. Sort the array A in non-decreasing order.
 * 2. Iterate through the sorted array, keeping track of the cumulative sum of people (P).
 * 3. For each group added, calculate the number of handshakes: P*(P-1)/2.
 * 4. If the number of handshakes is <= M, increment the count of groups.
 * 5. If it exceeds M, stop and return the count.
 * 
 * Constraints:
 * N <= 100, A_i <= 100. Max total people = 100 * 100 = 10,000.
 * Max handshakes = 10,000 * 9,999 / 2 approx 5 * 10^7.
 * This fits within a standard 32-bit integer, but using long long is safer.
 */

void solve() {
    int N;
    long long M;
    cin >> N >> M;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Sort to pick smallest groups first to maximize the count
    sort(A.begin(), A.end());

    long long current_people = 0;
    int groups_invited = 0;

    for (int i = 0; i < N; ++i) {
        long long next_people = current_people + A[i];
        long long handshakes = (next_people * (next_people - 1)) / 2;

        if (handshakes <= M) {
            current_people = next_people;
            groups_invited++;
        } else {
            // Cannot add more groups
            break;
        }
    }

    cout << groups_invited << "\n";
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