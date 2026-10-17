# [Far from origin (FARFROMO)](https://www.codechef.com/problems/FARFROMO)

- **Difficulty Rating**: 750
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine which of two people, Alex or Bob, is located farther from the origin $(0, 0)$ on a 2D Cartesian plane. We are given the coordinates $(X_1, Y_1)$ for Alex and $(X_2, Y_2)$ for Bob. We need to output "ALEX" if Alex is farther, "BOB" if Bob is farther, or "EQUAL" if they are at the same distance.

## Intuition & Mathematical Observation
The distance $d$ of a point $(x, y)$ from the origin $(0, 0)$ is calculated using the Euclidean distance formula:
$$d = \sqrt{x^2 + y^2}$$

To compare the distances of two points, we compare $\sqrt{x_1^2 + y_1^2}$ and $\sqrt{x_2^2 + y_2^2}$. Since the square root function is monotonically increasing for non-negative values, we can avoid floating-point precision issues by comparing the squared distances instead:
$$d^2 = x^2 + y^2$$

- If $x_1^2 + y_1^2 > x_2^2 + y_2^2$, then Alex is farther.
- If $x_1^2 + y_1^2 < x_2^2 + y_2^2$, then Bob is farther.
- If $x_1^2 + y_1^2 = x_2^2 + y_2^2$, they are at an equal distance.

Given the constraints (coordinates between -1000 and 1000), the maximum squared distance is $1000^2 + 1000^2 = 2,000,000$, which fits well within a standard 32-bit integer.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the coordinates and squared distances.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The distance of a point (x, y) from the origin (0, 0) is given by the formula:
 * Distance = sqrt(x^2 + y^2)
 * To compare the distances of Alex (X1, Y1) and Bob (X2, Y2), we can compare
 * the squares of their distances to avoid floating point precision issues:
 * Dist1^2 = X1^2 + Y1^2
 * Dist2^2 = X2^2 + Y2^2
 * 
 * If Dist1^2 > Dist2^2, Alex is farther.
 * If Dist1^2 < Dist2^2, Bob is farther.
 * If Dist1^2 == Dist2^2, they are at the same distance.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        // Calculate squared distances
        long long dist1_sq = (x1 * x1) + (y1 * y1);
        long long dist2_sq = (x2 * x2) + (y2 * y2);
        
        // Compare squared distances
        if (dist1_sq > dist2_sq) {
            cout << "ALEX" << "\n";
        } else if (dist2_sq > dist1_sq) {
            cout << "BOB" << "\n";
        } else {
            cout << "EQUAL" << "\n";
        }
    }
    
    return 0;
}
```