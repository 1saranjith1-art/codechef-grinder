#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have an N x M chocolate bar.
 * Alice can make at most one cut (horizontal or vertical).
 * If she makes a cut, she gets two pieces of size (N1 x M) and (N2 x M) where N1+N2 = N,
 * or (N x M1) and (N x M2) where M1+M2 = M.
 * She gives one piece to Bob, and keeps the other.
 * Bob must receive at least K squares.
 * We want to maximize the number of squares Alice keeps.
 * 
 * Possible scenarios:
 * 1. No cut: Alice keeps N*M, but only if Bob receives 0 (or if Bob is satisfied with 0).
 *    Actually, the problem says "Alice can also choose to not break the bar at all".
 *    If she doesn't break, she gives nothing to Bob (Bob gets 0).
 *    If K > 0, she MUST cut to give Bob at least K.
 * 2. Horizontal cut: Cut N into N1 and N2. Pieces are (N1*M) and (N2*M).
 *    If N1*M >= K, Alice can give N1*M to Bob and keep N2*M.
 *    If N2*M >= K, Alice can give N2*M to Bob and keep N1*M.
 * 3. Vertical cut: Cut M into M1 and M2. Pieces are (N*M1) and (N*M2).
 *    If N*M1 >= K, Alice can give N*M1 to Bob and keep N*M2.
 *    If N*M2 >= K, Alice can give N*M2 to Bob and keep N*M1.
 * 
 * Constraints are small (N, M <= 10), so we can iterate through all possible cuts.
 */

void solve() {
    long long N, M, K;
    cin >> N >> M >> K;

    long long max_alice = 0;

    // Case 0: No cut
    // If Bob needs 0, Alice keeps everything.
    if (K == 0) {
        cout << N * M << "\n";
        return;
    }

    // Case 1: Horizontal cuts
    // Cut N into i and (N-i) for i from 1 to N-1
    for (int i = 1; i < N; ++i) {
        long long p1 = (long long)i * M;
        long long p2 = (long long)(N - i) * M;
        
        if (p1 >= K) max_alice = max(max_alice, p2);
        if (p2 >= K) max_alice = max(max_alice, p1);
    }

    // Case 2: Vertical cuts
    // Cut M into j and (M-j) for j from 1 to M-1
    for (int j = 1; j < M; ++j) {
        long long p1 = (long long)N * j;
        long long p2 = (long long)N * (M - j);
        
        if (p1 >= K) max_alice = max(max_alice, p2);
        if (p2 >= K) max_alice = max(max_alice, p1);
    }

    // Case 3: Giving the whole bar to Bob
    if (N * M >= K) {
        max_alice = max(max_alice, 0LL);
    }

    cout << max_alice << "\n";
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