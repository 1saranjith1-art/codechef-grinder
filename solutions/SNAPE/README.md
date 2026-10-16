# [Snape and Ladder (SNAPE)](https://www.codechef.com/problems/SNAPE)

- **Difficulty Rating**: 828
- **Solved in**: 1 attempt(s)

## Problem Summary
Given the base distance $B$ between two points on the ground and the length of one side of the ladder $LS$, we need to find the minimum and maximum possible values for the length of the other side of the ladder ($RS$) such that the apex of the ladder forms a right-angled triangle with the ground.

## Intuition & Mathematical Observation
The problem describes a setup where the apex of the ladder is at a height $H$ above the ground. The base $B$ is the horizontal distance between the two points where the ladder touches the ground.

1.  **Minimum $RS$**:
    The minimum height $H$ occurs when the side $LS$ is the hypotenuse of a right triangle with base $B$. By the Pythagorean theorem:
    $H^2 + B^2 = LS^2 \implies H = \sqrt{LS^2 - B^2}$
    The minimum $RS$ occurs when the second side is perfectly vertical, meaning $RS = H$. Thus, $RS_{min} = \sqrt{LS^2 - B^2}$.

2.  **Maximum $RS$**:
    The maximum height $H$ occurs when the side $LS$ is perfectly vertical. In this scenario, the second side $RS$ acts as the hypotenuse of a right triangle with base $B$ and height $LS$. By the Pythagorean theorem:
    $RS^2 = B^2 + LS^2 \implies RS = \sqrt{B^2 + LS^2}$

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations and square root calculations.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and results.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have a right-angled triangle formed by the ladder sides and the ground.
 * Let B be the base (separation), LS be the length of the left side, and RS be the length of the right side.
 * 
 * Minimum RS: Occurs when the apex is at the lowest possible height H.
 * H = sqrt(LS^2 - B^2), and RS = H.
 * 
 * Maximum RS: Occurs when the apex is at the highest possible height H = LS.
 * RS = sqrt(H^2 + B^2) = sqrt(LS^2 + B^2).
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        double b, ls;
        cin >> b >> ls;

        // Calculate min and max RS based on Pythagorean theorem
        double min_rs = sqrt(max(0.0, ls * ls - b * b));
        double max_rs = sqrt(ls * ls + b * b);

        // Output with required precision
        cout << fixed << setprecision(5) << min_rs << " " << max_rs << "\n";
    }

    return 0;
}
```