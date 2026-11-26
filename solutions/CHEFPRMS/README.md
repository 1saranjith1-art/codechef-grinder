# [Chef and Semi-Primes (CHEFPRMS)](https://www.codechef.com/problems/CHEFPRMS)

- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine if a given integer $N$ ($1 \le N \le 200$) can be expressed as the sum of two semi-primes. A semi-prime is defined here as the product of two **distinct** prime numbers.

## Intuition & Mathematical Observation
1. **Definition**: A number $S$ is a semi-prime if $S = p \times q$, where $p$ and $q$ are prime numbers and $p \neq q$.
2. **Constraint Analysis**: Since $N \le 200$, the search space is extremely small. We can precompute all semi-primes up to 200.
3. **Precomputation**:
   - Iterate through all numbers $i$ from 1 to 200.
   - For each $i$, check if it can be factored into two distinct primes.
   - Store these valid semi-primes in a list.
4. **Verification**: For each test case $N$, iterate through the list of precomputed semi-primes. Check if there exists a pair $(S_1, S_2)$ such that $S_1 + S_2 = N$. If such a pair is found, output "YES"; otherwise, output "NO".

## Complexity Analysis
- **Time Complexity**: 
  - Precomputation: $O(N \sqrt{N})$ to identify semi-primes up to $N=200$.
  - Query: For each test case, we perform a nested loop over the list of semi-primes. Since there are at most 200 numbers, the number of semi-primes is small (constant $K < 200$), leading to $O(T \cdot K^2)$ per test case. Given the constraints, this is well within the time limit.
- **Space Complexity**: $O(N)$ to store the list of semi-primes up to $N$.

## Solution Code

```cpp
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

    // Precompute semi-primes up to 200
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
        // Check if N is a sum of two semi-primes
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
```