#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The theater has 2N+1 seats.
 * Occupied seats are 1, 3, 5, ..., 2N+1.
 * Empty seats are 2, 4, 6, ..., 2N.
 * 
 * Let A_1, A_2, ..., A_{N+1} be the hype levels of people in seats 1, 3, 5, ..., 2N+1.
 * Empty seat 2 is between seat 1 and seat 3. Loudness = max(A_1, A_2).
 * Empty seat 4 is between seat 3 and seat 5. Loudness = max(A_2, A_3).
 * ...
 * Empty seat 2i is between seat 2i-1 and seat 2i+1. Loudness = max(A_i, A_{i+1}).
 * 
 * We need to find the minimum loudness among all empty seats i = 1 to N.
 * The loudness of the i-th empty seat (seat 2i) is max(A_i, A_{i+1}).
 * We iterate from i = 1 to N, calculate max(A_i, A_{i+1}), and find the minimum of these values.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    
    vector<long long> A(N + 1);
    for (int i = 0; i <= N; ++i) {
        cin >> A[i];
    }
    
    // Initialize min_loudness with a value larger than any possible A_i (max A_i is 100)
    long long min_loudness = 200; 
    
    // There are N empty seats, corresponding to indices 2, 4, ..., 2N.
    // The i-th empty seat (1-indexed, i from 1 to N) is between A[i-1] and A[i].
    for (int i = 0; i < N; ++i) {
        long long current_loudness = max(A[i], A[i + 1]);
        if (current_loudness < min_loudness) {
            min_loudness = current_loudness;
        }
    }
    
    cout << min_loudness << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}