#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Given an integer N, we need to find the count of odd divisors and even divisors.
 * Since N is small (up to 100), we can iterate from 1 to N to find all divisors.
 * A divisor 'i' of N satisfies (N % i == 0).
 * If 'i' is odd (i % 2 != 0), increment the odd count.
 * If 'i' is even (i % 2 == 0), increment the even count.
 * 
 * Time Complexity: O(T * N), where T is the number of test cases and N is the input integer.
 * Given T <= 100 and N <= 100, this is well within the time limit.
 * Space Complexity: O(1).
 */

void solve() {
    int n;
    cin >> n;
    
    int odd_divisors = 0;
    int even_divisors = 0;
    
    for (int i = 1; i <= n; ++i) {
        if (n % i == 0) {
            if (i % 2 != 0) {
                odd_divisors++;
            } else {
                even_divisors++;
            }
        }
    }
    
    cout << odd_divisors << " " << even_divisors << "\n";
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    
    return 0;
}