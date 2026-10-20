#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N cups with amounts A_i.
 * In one operation, we move all water from cup i to cup j.
 * This effectively merges the contents of two cups.
 * We need to perform exactly K operations.
 * 
 * Each operation reduces the number of non-empty cups by 1.
 * If we start with N non-empty cups, after K operations, we will have 
 * N - K non-empty cups (if K < N). If K >= N-1, we can merge everything 
 * into a single cup.
 * 
 * To maximize the maximum amount in any cup:
 * 1. If K >= N-1, we can merge all water into one cup. The result is the sum of all A_i.
 * 2. If K < N-1, we want to pick the largest cup and keep adding the largest 
 *    available cups to it for K operations.
 * 
 * Strategy:
 * Sort the array A in descending order.
 * The largest cup is A[0].
 * In each of the K operations, we take the next largest available cup and add it to our target cup.
 * Since we want to maximize the result, we should always add the largest available values 
 * to the largest initial value.
 */

void solve() {
    int N, K;
    cin >> N >> K;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Sort in descending order to easily pick the largest values
    sort(A.rbegin(), A.rend());

    // If K >= N-1, we can merge all cups into one.
    // The maximum possible value is the sum of all elements.
    if (K >= N - 1) {
        long long sum = 0;
        for (long long x : A) {
            sum += x;
        }
        cout << sum << "\n";
    } else {
        // We perform K operations. Each operation adds one cup to the largest cup.
        // We start with A[0] and add A[1], A[2], ..., A[K].
        long long max_val = A[0];
        for (int i = 1; i <= K; ++i) {
            max_val += A[i];
        }
        cout << max_val << "\n";
    }
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