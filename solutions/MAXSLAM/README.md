# [Maximum Slams (MAXSLAM)](https://www.codechef.com/problems/MAXSLAM)

- **Difficulty Rating**: 224
- **Solved in**: 2 attempt(s)

## Problem Summary
Chef currently has $X$ Grand Slams. He wants to reach a total of at least 25 Grand Slams. Given that Chef wins 4 Grand Slams every year, calculate the minimum number of years required for Chef to reach his goal.

## Intuition & Mathematical Observation
To solve this, we need to determine how many years ($Y$) are required such that the total number of Grand Slams becomes at least 25.

1.  **The Inequality**: $X + 4 \times Y \geq 25$
2.  **Rearranging**: $4 \times Y \geq 25 - X$
3.  **Solving for Y**: $Y \geq \frac{25 - X}{4}$

Since $Y$ must be a non-negative integer, we take the ceiling of the result. If $X \geq 25$, the answer is simply $0$. Otherwise, we calculate the ceiling of the division using integer arithmetic: `(needed + 3) / 4`, where `needed = 25 - X`.

## Complexity Analysis
- **Time Complexity**: $O(1)$ — The solution performs a constant number of arithmetic operations regardless of the input size.
- **Space Complexity**: $O(1)$ — We only use a few integer variables to store the input and the result.

## Solution Code

```cpp
#include <iostream>

/**
 * Problem Analysis:
 * Chef needs at least 25 Grand Slams.
 * Chef currently has X Grand Slams.
 * Chef wins 4 Grand Slams per year.
 * Let Y be the number of years.
 * We need: X + 4 * Y >= 25
 * 4 * Y >= 25 - X
 * Y >= (25 - X) / 4
 * Since Y must be an integer, Y = ceil((25 - X) / 4.0)
 * Using integer arithmetic, this is equivalent to (25 - X + 3) / 4.
 */

int main() {
    // Fast I/O setup
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int X;
    // The problem specifies the input is a single integer X.
    if (std::cin >> X) {
        int needed = 25 - X;
        if (needed <= 0) {
            std::cout << 0 << "\n";
        } else {
            // Ceiling division of needed / 4
            int years = (needed + 3) / 4;
            std::cout << years << "\n";
        }
    }

    return 0;
}
```