# [Pizza Party (PIZZAPARTY)](https://www.codechef.com/problems/PIZZAPARTY)

- **Difficulty Rating**: 238
- **Solved in**: 2 attempt(s)

## Problem Summary
Chef is hosting a party with $A$ friends (all boys) and $B$ girls. Including Chef himself, there are $A+1$ boys. Each boy consumes 4 slices of pizza, and each girl consumes 3 slices. Given that each pizza contains 8 slices, calculate the minimum number of whole pizzas required to ensure everyone is fed.

## Intuition & Mathematical Observation
1. **Total Consumption**: 
   - Total boys = $A + 1$
   - Total girls = $B$
   - Total slices needed = $(A + 1) \times 4 + B \times 3$
2. **Ceiling Division**: 
   - Since we cannot order a fraction of a pizza, we need to round up the result of `Total Slices / 8`.
   - In integer arithmetic, the ceiling of $\frac{x}{y}$ can be calculated using the formula: `(x + y - 1) / y`.
   - Applying this to our problem: `(total_slices + 8 - 1) / 8` or `(total_slices + 7) / 8`.

## Complexity Analysis
- **Time Complexity**: $O(1)$ — The solution performs a constant number of arithmetic operations regardless of the input size.
- **Space Complexity**: $O(1)$ — We only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * - Chef is a boy, so total boys = A + 1.
 * - Total girls = B.
 * - Each boy eats 4 slices, each girl eats 3 slices.
 * - Total slices needed = (A + 1) * 4 + B * 3.
 * - Each pizza has 8 slices.
 * - Number of pizzas needed = ceil(Total slices / 8).
 * - Using integer arithmetic, ceil(x / y) = (x + y - 1) / y.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long A, B;
    // Read A and B directly as per the problem statement
    if (cin >> A >> B) {
        long long total_boys = A + 1;
        long long total_girls = B;
        
        long long total_slices = (total_boys * 4) + (total_girls * 3);
        
        // Calculate ceiling of (total_slices / 8)
        // Formula: (numerator + denominator - 1) / denominator
        long long pizzas = (total_slices + 7) / 8;
        
        cout << pizzas << endl;
    }
    
    return 0;
}
```