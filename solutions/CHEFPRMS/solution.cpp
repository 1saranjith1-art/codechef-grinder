#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A semi-prime is a product of two distinct primes.
 * N <= 200.
 * 
 * Step 1: Find all primes up to 200.
 * Step 2: Generate all semi-primes up to 200.
 * Step 3: Check if N can be represented as sum of two semi-primes.
 */

bool is_semi_prime(int n) {
    int count = 0;
    for (int i = 2; i < n; ++i) {
        if (n % i == 0) {
            int d1 = i;
            int d2 = n / i;
            // Check if d1 and d2 are distinct primes
            auto is_prime = [](int x) {
                if (x < 2) return false;
                for (int j = 2; j * j <= x; ++j) {
                    if (x % j == 0) return false;
                }
                return true;
            };
            if (d1 != d2 && is_prime(d1) && is_prime(d2)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> semi_primes;
    for (int i = 1; i <= 200; ++i) {
        if (is_semi_prime(i)) {
            semi_primes.push_back(i);
        }
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        bool found = false;
        for (int i = 0; i < semi_primes.size(); ++i) {
            for (int j = 0; j < semi_primes.size(); ++j) {
                if (semi_primes[i] + semi_primes[j] == n) {
                    found = true;
                    break;
                }
            }
            if (found) break;
        }

        if (found) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}