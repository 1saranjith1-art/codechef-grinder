#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to select n marbles of k different colors such that we have at least one of each color.
 * This is a classic stars and bars problem.
 * Let x_i be the number of marbles of color i.
 * We need x_1 + x_2 + ... + x_k = n, where x_i >= 1.
 * Let y_i = x_i - 1, then y_i >= 0.
 * Substituting: (y_1 + 1) + (y_2 + 1) + ... + (y_k + 1) = n
 * y_1 + y_2 + ... + y_k = n - k, where y_i >= 0.
 * The number of non-negative integer solutions is given by the formula:
 * C(N + K - 1, K - 1) where N = n - k and K = k.
 * This simplifies to C(n - k + k - 1, k - 1) = C(n - 1, k - 1).
 * 
 * Using the property C(n, k) = C(n, n - k), we can compute C(n-1, k-1) 
 * as C(n-1, min(k-1, n-k)).
 * Since n, k <= 1,000,000, we compute the combination iteratively to avoid overflow 
 * and ensure it fits in a 64-bit integer.
 */

long long solve() {
    long long n, k;
    cin >> n >> k;
    
    // We need to calculate C(n-1, k-1)
    long long N = n - 1;
    long long K = k - 1;
    
    // Optimization: C(N, K) = C(N, N-K)
    if (K > N / 2) {
        K = N - K;
    }
    
    long long res = 1;
    for (long long i = 1; i <= K; ++i) {
        res = res * (N - i + 1) / i;
    }
    
    return res;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        cout << solve() << "\n";
    }
    return 0;
}