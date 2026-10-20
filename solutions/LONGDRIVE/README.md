# [Long Drive (LONGDRIVE)](https://www.codechef.com/problems/LONGDRIVE)

- **Difficulty Rating**: 939
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has already driven for 10 hours at an average speed of $X$ km/h. He wants his overall average speed for the entire trip to be at least $Y$ km/h. Given that Chef can drive at a maximum speed of 100 km/h for any additional hours, find the minimum number of additional hours required to achieve an average speed of at least $Y$.

## Intuition & Mathematical Observation
Let $n$ be the number of additional hours.
1. The total distance covered in the first 10 hours is $10 \times X$.
2. The maximum distance Chef can cover in $n$ additional hours is $100 \times n$.
3. The total time spent is $10 + n$.
4. The condition for the average speed is:
   $$\frac{10X + 100n}{10 + n} \ge Y$$

Rearranging the inequality to solve for $n$:
$$10X + 100n \ge Y(10 + n)$$
$$10X + 100n \ge 10Y + nY$$
$$100n - nY \ge 10Y - 10X$$
$$n(100 - Y) \ge 10(Y - X)$$
$$n \ge \frac{10(Y - X)}{100 - Y}$$

Since $n$ must be an integer, we take the ceiling of the result. Using integer arithmetic, the ceiling of $\frac{a}{b}$ is calculated as `(a + b - 1) / b`.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves basic arithmetic operations. Total time complexity is $O(T)$, where $T$ is the number of test cases.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We derived the inequality: n * (100 - Y) >= 10 * (Y - X)
 * Where n is the number of additional hours.
 * We solve for the smallest integer n using ceiling division.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long X, Y;
        cin >> X >> Y;

        // Numerator: 10 * (Y - X)
        // Denominator: 100 - Y
        long long numerator = 10 * (Y - X);
        long long denominator = 100 - Y;
        
        // Ceiling division for positive integers: (a + b - 1) / b
        long long n = (numerator + denominator - 1) / denominator;
        
        cout << n << "\n";
    }

    return 0;
}
```