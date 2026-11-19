#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need a permutation P of length N (even) such that P[i] + P[N+1-i] are all distinct.
 * Let's try to construct the permutation by placing numbers in pairs.
 * If we use the sequence 1, 2, ..., N, we can arrange them such that the sums
 * of opposite elements are distinct.
 * 
 * A simple construction:
 * Place the numbers 1, 2, ..., N/2 in the first half and N, N-1, ..., N/2 + 1 in the second half.
 * Specifically, let's try:
 * P = [1, 2, ..., N/2, N, N-1, ..., N/2 + 1]
 * 
 * Let's check N=6:
 * P = [1, 2, 3, 6, 5, 4]
 * i=1: P[1]+P[6] = 1+4 = 5
 * i=2: P[2]+P[5] = 2+5 = 7
 * i=3: P[3]+P[4] = 3+6 = 9
 * Sums are {5, 7, 9}, which are distinct.
 * 
 * Let's check N=4:
 * P = [1, 2, 4, 3]
 * i=1: P[1]+P[4] = 1+3 = 4
 * i=2: P[2]+P[3] = 2+4 = 6
 * Sums are {4, 6}, which are distinct.
 * 
 * This construction P[i] = i for i <= N/2 and P[i] = N - (i - N/2 - 1) for i > N/2
 * works because the sums will be (1 + N), (2 + N-1), ..., (N/2 + N/2 + 1).
 * Wait, the sums are:
 * i=1: 1 + (N/2 + 1) = N/2 + 2
 * i=2: 2 + (N/2 + 2) = N/2 + 4
 * ...
 * i=k: k + (N/2 + k) = 2k + N/2
 * These are clearly distinct for different k.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> P(N);
    int left = 1;
    int right = N;
    
    // We want P[i] + P[N-1-i] to be distinct.
    // Let's fill the array such that we pick from the start and end of the range [1, N].
    // To ensure distinct sums, we can alternate picking from the start and end.
    // Actually, the simplest way is to just output 1, 2, ..., N/2, N, N-1, ..., N/2+1.
    
    for (int i = 0; i < N / 2; ++i) {
        P[i] = i + 1;
    }
    for (int i = N / 2; i < N; ++i) {
        P[i] = N - (i - N / 2);
    }
    
    for (int i = 0; i < N; ++i) {
        cout << P[i] << (i == N - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}