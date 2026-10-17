# [Chef in Heaven (CCHEAVEN)](https://www.codechef.com/problems/CCHEAVEN)

- **Difficulty Rating**: 1317
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef lives for $L$ years, represented by a binary string $S$ of length $L$. A '1' represents a good year, and a '0' represents a bad year. Chef can go to heaven if there exists at least one prefix of the string (of length $L'$, where $1 \le L' \le L$) such that the number of good years in that prefix is at least 50% of the total years in that prefix.

## Intuition & Mathematical Observation
Let $i$ be the current year (1-indexed, $1 \le i \le L$) and $G_i$ be the count of good years ('1's) encountered up to year $i$. 

The condition for Chef to go to heaven is:
$$\frac{G_i}{i} \ge 0.5$$

To avoid floating-point precision issues, we can multiply both sides by $2i$:
$$2 \cdot G_i \ge i$$

By iterating through the string once and maintaining a running count of good years, we can check this condition at every step. If the condition is satisfied for any $i$, we immediately know Chef can go to heaven and can terminate the search early.

## Complexity Analysis
- **Time Complexity**: $O(L)$ per test case, where $L$ is the length of the string. We perform a single pass through the string.
- **Space Complexity**: $O(L)$ to store the input string $S$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef lives for L years. We are given a string S of length L where '1' is a good year
 * and '0' is a bad year. Chef goes to heaven if there exists some L' (1 <= L' <= L)
 * such that the number of good years in the first L' years is >= 50% of L'.
 * 
 * Let 'good' be the count of '1's in the prefix of length i (1-indexed).
 * The condition is: good / i >= 0.5
 * This is equivalent to: 2 * good >= i
 * 
 * We iterate through the string, maintaining a running count of good years.
 * At each year i, we check if 2 * good >= i. If this condition is met at any point,
 * Chef can go to heaven.
 */

void solve() {
    int L;
    cin >> L;
    string S;
    cin >> S;

    int good_years = 0;
    bool possible = false;

    for (int i = 0; i < L; ++i) {
        if (S[i] == '1') {
            good_years++;
        }
        
        // Current year is i + 1
        // Condition: good_years / (i + 1) >= 0.5
        // Equivalent to: 2 * good_years >= i + 1
        if (2 * good_years >= (i + 1)) {
            possible = true;
            break;
        }
    }

    if (possible) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
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
```