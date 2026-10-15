# [Sunny Day (SUNNYDAY)](https://www.codechef.com/problems/SUNNYDAY)

- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef decides to go for a picnic only if the temperature $X$ is strictly greater than 24 degrees Celsius. Given $T$ test cases, each containing a temperature $X$, determine whether Chef will go for the picnic or not. Output "YES" if $X > 24$, otherwise output "NO".

## Intuition & Mathematical Observation
The problem provides a simple conditional requirement. We are given an integer $X$ representing the temperature. The condition for Chef to go to the picnic is defined by the inequality:
$$X > 24$$

Since the constraints are small ($1 \le X \le 100$), a simple `if-else` statement is sufficient to evaluate the condition for each test case. We read the number of test cases $T$, and for each test case, we perform a comparison check.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. We perform a constant time operation for each test case.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and do not require any auxiliary data structures.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: SUNNYDAY
 * Chef goes to the picnic if X > 24.
 * Constraints: 1 <= T <= 100, 1 <= X <= 100.
 * Time Complexity: O(T)
 * Space Complexity: O(1)
 */

int main() {
    // Optimize standard I/O operations for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long x;
        cin >> x;
        
        // Check if the temperature is strictly greater than 24
        if (x > 24) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}
```