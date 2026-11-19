# [Pair Me (SUMPOS)](https://www.codechef.com/problems/SUMPOS)

- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary
Given three integers $x$, $y$, and $z$, determine if any one of these integers can be expressed as the sum of the other two. In other words, check if $x = y + z$, $y = x + z$, or $z = x + y$ holds true.

## Intuition & Mathematical Observation
The problem asks us to verify if the given triplet $(x, y, z)$ satisfies the property of being a "sum-pair" triplet. 

Instead of sorting the numbers, we can directly evaluate the three logical conditions provided by the problem statement:
1. $x = y + z$
2. $y = x + z$
3. $z = x + y$

If any of these conditions evaluate to `true`, the output should be "YES". Otherwise, it should be "NO". Since the constraints are small ($1 \le x, y, z \le 1000$), standard integer arithmetic is perfectly safe, though `long long` is used here as a best practice to avoid potential overflow in similar problems.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case. Since we perform a constant number of arithmetic operations and comparisons, the complexity is constant. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$. We only use a fixed amount of memory to store the three integers regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Given three integers x, y, and z, we need to check if:
 * x = y + z OR y = x + z OR z = x + y.
 * 
 * Since the constraints are small (1 <= x, y, z <= 1000), 
 * standard integer types are sufficient, but using long long 
 * is a safe practice in competitive programming to prevent overflow.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long x, y, z;
        cin >> x >> y >> z;
        
        // Check the three possible conditions
        if ((x == y + z) || (y == x + z) || (z == x + y)) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}
```