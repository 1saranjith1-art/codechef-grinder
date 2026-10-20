#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to find the nearest multiple of 3 for a given integer N.
 * The distance between N and the nearest multiple of 3 is defined by |N - X|.
 * 
 * Logic:
 * If N % 3 == 0, the nearest multiple is N itself.
 * If N % 3 == 1, the multiples are (N-1) and (N+2). 
 *    Distance to (N-1) is 1, distance to (N+2) is 2. So (N-1) is closer.
 * If N % 3 == 2, the multiples are (N-2) and (N+1).
 *    Distance to (N-2) is 2, distance to (N+1) is 1. So (N+1) is closer.
 * 
 * Constraints: 1 <= N <= 10.
 * The logic holds for all positive integers.
 */

void solve() {
    long long n;
    if (!(cin >> n)) return;

    long long remainder = n % 3;

    if (remainder == 0) {
        cout << n << "\n";
    } else if (remainder == 1) {
        // For N=1, 1%3=1, 1-1=0. Correct.
        cout << (n - 1) << "\n";
    } else {
        // For N=5, 5%3=2, 5+1=6. Correct.
        cout << (n + 1) << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // The problem description implies a single input N per run, 
    // but standard competitive programming practice often involves 
    // handling test cases if specified. Given the prompt structure:
    solve();

    return 0;
}