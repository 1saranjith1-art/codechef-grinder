# [Count Odd Even Divisors (CNTODDEVEN)](https://www.codechef.com/problems/CNTODDEVEN)

- **Difficulty Rating**: 538
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an integer $N$, the task is to determine the number of divisors of $N$ that are odd and the number of divisors that are even. We need to output these two counts for each test case.

## Intuition & Mathematical Observation
Since the constraints on $N$ are very small ($N \le 100$), we do not need complex prime factorization or number-theoretic functions. A simple brute-force approach is sufficient:
1. Iterate through every integer $i$ from $1$ to $N$.
2. Check if $i$ is a divisor of $N$ by verifying if `N % i == 0`.
3. If it is a divisor, check its parity:
   - If `i % 2 != 0`, it is an **odd divisor**.
   - If `i % 2 == 0`, it is an **even divisor**.
4. Maintain two counters and increment them accordingly.

## Complexity Analysis
- **Time Complexity**: $O(T \times N)$, where $T$ is the number of test cases and $N$ is the input integer. Given $T, N \le 100$, the total operations are roughly $10^4$, which easily passes within the time limit.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the counts and the loop index.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Given an integer N, we need to find the count of odd divisors and even divisors.
 * Since N is small (up to 100), we can iterate from 1 to N to find all divisors.
 * A divisor 'i' of N satisfies (N % i == 0).
 * If 'i' is odd (i % 2 != 0), increment the odd count.
 * If 'i' is even (i % 2 == 0), increment the even count.
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
```