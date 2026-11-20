# [My First Geometry Problem (FIRSTGEO)](https://www.codechef.com/problems/FIRSTGEO)

- **Difficulty Rating**: 1171
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given a 2D grid where coordinates $(x, y)$ range from $-10$ to $10$. We are provided with a 4-character binary string representing whether movement is allowed in the Left, Right, Up, and Down directions respectively. We need to calculate the total number of distinct integer coordinates $(x, y)$ that can be reached starting from $(0, 0)$ given these constraints.

## Intuition & Mathematical Observation
The problem asks for the number of integer points $(x, y)$ such that $x \in [x_{min}, x_{max}]$ and $y \in [y_{min}, y_{max}]$.

1.  **Defining Bounds**:
    *   If `Left` is allowed, $x$ can range from $-10$ to $0$.
    *   If `Right` is allowed, $x$ can range from $0$ to $10$.
    *   If `Down` is allowed, $y$ can range from $-10$ to $0$.
    *   If `Up` is allowed, $y$ can range from $0$ to $10$.

2.  **Calculating Ranges**:
    *   $x_{min} = -10$ if `Left` is enabled, else $0$.
    *   $x_{max} = 10$ if `Right` is enabled, else $0$.
    *   $y_{min} = -10$ if `Down` is enabled, else $0$.
    *   $y_{max} = 10$ if `Up` is enabled, else $0$.

3.  **Counting Points**:
    The number of integers in a range $[a, b]$ is $(b - a + 1)$. Since the grid is defined by the Cartesian product of the valid $x$ range and the valid $y$ range, the total number of points is:
    $$\text{Total Points} = (\text{count of valid } x) \times (\text{count of valid } y)$$
    Where the count for a dimension is $(max - min + 1)$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we perform a constant number of arithmetic operations regardless of the input string.
- **Space Complexity**: $O(1)$, as we only store a few integer variables.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The grid is defined as -10 <= x, y <= 10.
 * We determine the range of x and y based on the input flags.
 * The total number of points is the product of the number of valid x-coordinates 
 * and the number of valid y-coordinates.
 */

void solve() {
    string s;
    cin >> s;
    
    // Parse the binary string
    int L = s[0] - '0';
    int R = s[1] - '0';
    int U = s[2] - '0';
    int D = s[3] - '0';

    // Determine bounds
    int x_min = L ? -10 : 0;
    int x_max = R ? 10 : 0;
    int y_min = D ? -10 : 0;
    int y_max = U ? 10 : 0;

    // Calculate number of integers in the range [min, max]
    // If min == max == 0, there is only 1 point (0)
    int x_count = (x_max - x_min + 1);
    int y_count = (y_max - y_min + 1);

    cout << x_count * y_count << "\n";
}

int main() {
    // Optimize I/O operations
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