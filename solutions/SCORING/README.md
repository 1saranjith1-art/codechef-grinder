# [Scoring (SCORING)](https://www.codechef.com/problems/SCORING)

- **Difficulty Rating**: 569
- **Solved in**: 1 attempt(s)

## Problem Summary
Given the difference ($X$) and the sum ($Y$) of Alice's score ($A$) and Bob's score ($B$), determine the individual scores of Alice and Bob. We are given the equations:
1. $A - B = X$
2. $A + B = Y$

We need to find $A$ and $B$ such that both equations are satisfied.

## Intuition & Mathematical Observation
This is a classic system of linear equations with two variables. We can solve for $A$ and $B$ using the elimination method:

1. **Find $A$**: Add the two equations together:
   $(A - B) + (A + B) = X + Y$
   $2A = X + Y$
   $A = \frac{X + Y}{2}$

2. **Find $B$**: Subtract the first equation from the second:
   $(A + B) - (A - B) = Y - X$
   $2B = Y - X$
   $B = \frac{Y - X}{2}$

Since the problem guarantees that a valid solution exists, $X+Y$ and $Y-X$ will always be even and non-negative, allowing for integer division.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. Each test case involves simple arithmetic operations performed in $O(1)$ time.
- **Space Complexity**: $O(1)$, as we only use a constant amount of extra space for variables.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let A be Alice's score and B be Bob's score.
 * We are given:
 * 1) A - B = X
 * 2) A + B = Y
 * 
 * Adding the two equations:
 * 2A = X + Y  =>  A = (X + Y) / 2
 * 
 * Subtracting the first from the second:
 * 2B = Y - X  =>  B = (Y - X) / 2
 */

int main() {
    // Optimize standard I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long x, y;
        cin >> x >> y;

        // Calculate Alice and Bob's scores using the derived formulas
        long long alice = (x + y) / 2;
        long long bob = (y - x) / 2;

        cout << alice << " " << bob << "\n";
    }

    return 0;
}
```