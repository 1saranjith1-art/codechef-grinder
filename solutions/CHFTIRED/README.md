# [Chef and Difficult Contests (CHFTIRED)](https://www.codechef.com/problems/CHFTIRED)

- **Difficulty Rating**: 1130
- **Solved in**: 2 attempt(s)

## Problem Summary
Given two integers $a$ and $b$, we are allowed to perform two types of operations any number of times:
1. Choose an integer $d \ge 1$, then $a \to a+d$ and $b \to b+d-1$.
2. Choose an integer $d \ge 1$, then $a \to a+d-1$ and $b \to b+d$.

The goal is to determine if it is possible to make $a$ equal to $b$ after performing these operations.

## Intuition & Mathematical Observation
Let the difference between the two numbers be $D = a - b$.

*   **Operation 1:** The new difference becomes $(a+d) - (b+d-1) = a - b + 1$.
*   **Operation 2:** The new difference becomes $(a+d-1) - (b+d) = a - b - 1$.

In each operation, we can change the difference $(a - b)$ by exactly $+1$ or $-1$. Since we can perform these operations an arbitrary number of times, we can effectively change the difference by any integer amount. Specifically, if the current difference is $D$, we can apply Operation 2 $D$ times (if $D > 0$) or Operation 1 $|D|$ times (if $D < 0$) to make the difference exactly $0$.

Because we can always reach a state where $a - b = 0$, the answer is **always "YES"** for any valid input of $a$ and $b$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform a constant number of operations (printing "YES"). For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input.

## Solution Code

```cpp
#include <iostream>

/**
 * Problem Analysis:
 * Let the difference be D = a - b.
 * Operation 1: a' = a + d, b' = b + d - 1 => (a' - b') = (a - b) + 1
 * Operation 2: a' = a + d - 1, b' = b + d => (a' - b') = (a - b) - 1
 * 
 * In each step, we can change the difference (a - b) by exactly 1.
 * Since we can perform this operation any number of times, we can 
 * always bridge any initial difference to reach 0.
 * 
 * Thus, the answer is always "YES" for any positive integers a and b.
 */

using namespace std;

int main() {
    // Optimize I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long a, b;
        cin >> a >> b;
        // As derived, it is always possible to make a equal to b.
        cout << "YES" << "\n";
    }

    return 0;
}
```