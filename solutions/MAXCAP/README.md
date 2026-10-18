# [Maximum Capacity (MAXCAP)](https://www.codechef.com/problems/MAXCAP)

- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine if a group of $X$ friends, each weighing $Y$ kg, can fit into a lift. The lift has two strict safety constraints:
1. It can carry a maximum of **8 people**.
2. It can carry a maximum total weight of **500 kg**.

We need to output "YES" if both conditions are met, and "NO" otherwise.

## Intuition & Mathematical Observation
To solve this problem, we simply need to evaluate the two given constraints mathematically:
1. **Constraint 1 (Capacity):** The number of people $X$ must satisfy $X \le 8$.
2. **Constraint 2 (Weight):** The total weight is calculated as $X \times Y$. This must satisfy $X \times Y \le 500$.

If both conditions are true, the lift can accommodate the group. Since the constraints on $X$ and $Y$ are small ($1 \le X, Y \le 100$), the product $X \times Y$ will not exceed 10,000, which fits comfortably within a standard 32-bit integer.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic and comparison operations, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and do not require any auxiliary data structures.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The lift has two constraints:
 * 1. Maximum number of people: 8
 * 2. Maximum weight capacity: 500 kg
 * 
 * Given X friends each weighing Y kg:
 * - Total weight = X * Y
 * - Condition 1: X <= 8
 * - Condition 2: X * Y <= 500
 * 
 * Both conditions must be satisfied for the answer to be "YES".
 * Constraints: 1 <= T <= 1000, 1 <= X, Y <= 100.
 * Since X*Y <= 10000, standard 'int' is sufficient to prevent overflow.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int x, y;
        cin >> x >> y;
        
        // Check both constraints:
        // 1. Number of people must be <= 8
        // 2. Total weight must be <= 500
        if (x <= 8 && (x * y) <= 500) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}
```