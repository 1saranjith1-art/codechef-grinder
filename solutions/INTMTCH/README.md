# [Interesting Match (INTMTCH)](https://www.codechef.com/problems/INTMTCH)

- **Difficulty Rating**: 240
- **Solved in**: 2 attempt(s)

## Problem Summary
The problem asks us to determine if a match is "Interesting" or "Boring" based on the scores of two players, $X$ and $Y$. A match is considered "Interesting" if the absolute difference between the two scores is at most 2 (i.e., $|X - Y| \le 2$). Otherwise, it is considered "Boring".

## Intuition & Mathematical Observation
The core of the problem is a simple conditional check. We are given two integers, $X$ and $Y$. We need to calculate the absolute difference $|X - Y|$. 
- If $|X - Y| \le 2$, the condition is satisfied, and we output "Interesting".
- If $|X - Y| > 2$, the condition is not satisfied, and we output "Boring".

Since the problem does not specify a number of test cases ($T$), we read the two integers directly and perform the comparison. Using the `abs()` function from the `<cmath>` or `<cstdlib>` library makes the calculation straightforward.

## Complexity Analysis
- **Time Complexity**: $O(1)$. The solution performs a constant number of arithmetic operations and comparisons regardless of the input size.
- **Space Complexity**: $O(1)$. We only use a fixed amount of memory to store the two input integers and the calculated difference.

## Solution Code

```cpp
#include <iostream>
#include <cmath>

using namespace std;

/**
 * Problem: INTMTCH
 * The problem asks to determine if the absolute difference between two integers X and Y
 * is at most 2.
 */

int main() {
    // Optimize I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x, y;
    
    // Read the two integers X and Y
    if (cin >> x >> y) {
        // Calculate absolute difference using abs()
        int diff = abs(x - y);

        // Check if the difference is at most 2
        if (diff <= 2) {
            cout << "Interesting" << endl;
        } else {
            cout << "Boring" << endl;
        }
    }

    return 0;
}
```