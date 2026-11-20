#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef chooses a threshold L >= 0.
 * For a fixed L, Chef can eat any subset of snacks where B_i <= L.
 * To maximize (Sum of A_i - L), for a fixed L, Chef should pick all snacks 
 * where B_i <= L AND A_i > 0.
 * If the sum of such A_i is S_L, the satisfaction is S_L - L.
 * Since L must be a non-negative integer, and the constraints on B_i are 
 * small (1 <= B_i <= 100), we can iterate through all possible values of L.
 * The relevant values for L are 0 and any B_i present in the input.
 * Since B_i <= 100, we can check all L from 0 to 100.
 */

void solve() {
    int N;
    cin >> N;
    vector<long long> A(N), B(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N; ++i) cin >> B[i];

    long long max_satisfaction = 0; // Choosing L=0 and eating nothing gives 0-0 = 0

    // Possible values for L are 0 to 100 (based on constraints B_i <= 100)
    for (int L = 0; L <= 100; ++L) {
        long long current_sum = 0;
        for (int i = 0; i < N; ++i) {
            // If snack satisfies threshold and has positive tastiness, eat it
            if (B[i] <= L && A[i] > 0) {
                current_sum += A[i];
            }
        }
        max_satisfaction = max(max_satisfaction, current_sum - L);
    }

    cout << max_satisfaction << "\n";
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