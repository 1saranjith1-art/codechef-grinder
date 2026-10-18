#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The array contains the first N positive odd numbers.
 * The first N odd numbers are: 1, 3, 5, ..., (2N - 1).
 * The sum of the first N odd numbers is N^2.
 * 
 * Let the number that appears K times be X.
 * The array consists of all numbers from 1 to (2N-1) once, 
 * plus (K-1) additional copies of X.
 * 
 * Total Sum S = (Sum of first N odd numbers) + (K-1) * X
 * S = N^2 + (K-1) * X
 * 
 * Rearranging to solve for X:
 * (K-1) * X = S - N^2
 * X = (S - N^2) / (K - 1)
 * 
 * Constraints:
 * N <= 10^4, N^2 <= 10^8.
 * S <= 10^9.
 * K <= 10^4.
 * All calculations fit within a 64-bit integer (long long).
 */

void solve() {
    long long N, K, S;
    if (!(cin >> N >> K >> S)) return;

    // Calculate the sum of the first N odd numbers
    long long sum_n = N * N;
    
    // Calculate the difference
    long long diff = S - sum_n;
    
    // Calculate X
    long long X = diff / (K - 1);
    
    cout << X << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}