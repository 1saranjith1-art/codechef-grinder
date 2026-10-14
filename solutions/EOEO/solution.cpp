#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let TS = 2^k * m, where m is odd.
 * The game proceeds by dividing both TS and JS by 2 as long as both are even.
 * This is equivalent to removing all factors of 2 from both numbers.
 * Let TS' = TS / 2^k = m (which is odd).
 * Let JS = 2^p * n, where n is odd.
 * 
 * The game ends when:
 * 1. Both are odd: TS' and n are odd. Since TS' is odd, this happens if n = TS'.
 * 2. TS is even, JS is odd: Tom wins.
 * 3. TS is odd, JS is even: Jerry wins.
 * 
 * After dividing both by 2^min(k, p):
 * - If k < p: TS becomes odd, JS becomes even. Jerry wins.
 * - If k > p: TS becomes even, JS becomes odd. Tom wins.
 * - If k == p: Both become odd. If the resulting odd parts are equal, it's a tie.
 * 
 * Jerry wins if after dividing both by 2^min(k, p), the resulting TS is odd and JS is even.
 * This happens if the power of 2 dividing JS (let's call it 2^p) is strictly greater 
 * than the power of 2 dividing TS (2^k).
 * 
 * So, we need to count JS in [1, TS] such that JS = 2^p * n, where p > k.
 * JS = 2^p * n <= TS
 * n * 2^p <= TS
 * Since n must be at least 1, we have 2^p <= TS / n.
 * Actually, it's simpler:
 * Let TS = 2^k * m.
 * We need JS = 2^p * n such that p > k and 1 <= JS <= TS.
 * JS must be a multiple of 2^(k+1).
 * The number of multiples of 2^(k+1) in the range [1, TS] is floor(TS / 2^(k+1)).
 */

void solve() {
    long long ts;
    cin >> ts;

    // Find the power of 2 that divides ts
    long long temp_ts = ts;
    long long power_of_2 = 1;
    while (temp_ts % 2 == 0) {
        power_of_2 *= 2;
        temp_ts /= 2;
    }

    // We need JS to be a multiple of (power_of_2 * 2)
    // such that JS <= TS.
    // The number of such multiples is TS / (power_of_2 * 2)
    long long divisor = power_of_2 * 2;
    cout << ts / divisor << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}