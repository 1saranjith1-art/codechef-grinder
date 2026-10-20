# [Christmas Trees (XMASTREE)](https://www.codechef.com/problems/XMASTREE)

- **Difficulty Rating**: 300
- **Solved in**: 2 attempt(s)

## Problem Summary
Chef buys $N$ Christmas trees at a cost of $A$ rupees each and sells $M$ of those trees at a price of $B$ rupees each. The goal is to calculate the total profit made by Chef, which is defined as the difference between the total revenue generated from sales and the total cost incurred from purchasing.

## Intuition & Mathematical Observation
The problem is a straightforward arithmetic calculation. 
1. **Total Cost**: Since Chef buys $N$ trees at $A$ rupees each, the total expenditure is $N \times A$.
2. **Total Revenue**: Since Chef sells $M$ trees at $B$ rupees each, the total income is $M \times B$.
3. **Profit**: The profit is simply the difference between the revenue and the cost:
   $$\text{Profit} = (M \times B) - (N \times A)$$

**Note on Data Types**: While the constraints for this specific problem are small, it is good practice to use `long long` in C++ to prevent potential integer overflow if the inputs were larger.

## Complexity Analysis
- **Time Complexity**: $O(1)$ — The solution performs a constant number of arithmetic operations regardless of the input size.
- **Space Complexity**: $O(1)$ — We only use a few variables to store the input and the result, requiring constant extra space.

## Solution Code

```cpp
#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * Chef bought N trees for A rupees each (Total Cost = N * A).
 * Chef sold M trees for B rupees each (Total Revenue = M * B).
 * Profit = Total Revenue - Total Cost = (M * B) - (N * A).
 */

int main() {
    // Optimize I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long N, A, M, B;
    
    // Read the single line of input containing N, A, M, and B
    if (cin >> N >> A >> M >> B) {
        // Calculate total cost and total revenue
        long long total_cost = N * A;
        long long total_revenue = M * B;
        
        // Profit = Revenue - Cost
        long long profit = total_revenue - total_cost;
        
        // Output the result
        cout << profit << endl;
    }

    return 0;
}
```