# [A Big Sale (BIGSALE)](https://www.codechef.com/problems/BIGSALE)

- **Difficulty Rating**: 1260
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to calculate the total loss incurred by a shopkeeper after a series of price adjustments. For each item, the shopkeeper first increases the price $p$ by $x\%$, and then applies a discount of $x\%$ on the new price. We are given the original price $p$, the quantity $q$, and the percentage $x$ for several items. We need to find the total loss across all items.

## Intuition & Mathematical Observation
Let the original price be $p$ and the percentage be $x$.

1. **Price after increase**: 
   The price becomes $p' = p \times (1 + \frac{x}{100})$.
   
2. **Price after discount**: 
   The final price $p''$ is the increased price $p'$ discounted by $x\%$:
   $p'' = p' \times (1 - \frac{x}{100})$
   $p'' = p \times (1 + \frac{x}{100}) \times (1 - \frac{x}{100})$

3. **Simplification**:
   Using the algebraic identity $(a+b)(a-b) = a^2 - b^2$:
   $p'' = p \times (1^2 - (\frac{x}{100})^2)$
   $p'' = p \times (1 - (\frac{x}{100})^2)$

4. **Loss Calculation**:
   The loss per unit is the difference between the original price and the final price:
   $\text{Loss per unit} = p - p''$
   $\text{Loss per unit} = p - p \times (1 - (\frac{x}{100})^2)$
   $\text{Loss per unit} = p \times (\frac{x}{100})^2$

5. **Total Loss**:
   For $q$ units, the total loss is $q \times \text{Loss per unit} = q \times p \times (\frac{x}{100})^2$.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of items. Given $T$ test cases, the total time complexity is $O(T \times N)$, which efficiently handles the constraints.
- **Space Complexity**: $O(1)$, as we only store a few variables to calculate the running total of the loss.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * For each recipe:
 * Original price = p
 * Discount percentage = x
 * 
 * Step 1: Increase price by x%
 * New price = p * (1 + x/100)
 * 
 * Step 2: Apply discount of x% on the new price
 * Final price = (p * (1 + x/100)) * (1 - x/100)
 * Final price = p * (1 - (x/100)^2)
 * 
 * Loss per unit = Original price - Final price
 * Loss per unit = p * (x/100)^2
 * 
 * Total loss = quantity * p * (x/100)^2
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int n;
        cin >> n;
        
        double total_loss = 0.0;
        for (int i = 0; i < n; ++i) {
            double p, q, x;
            cin >> p >> q >> x;
            
            // Loss per unit = p * (x/100)^2
            double loss_per_unit = p * (x / 100.0) * (x / 100.0);
            total_loss += (loss_per_unit * q);
        }
        
        // Output with required precision
        cout << fixed << setprecision(9) << total_loss << "\n";
    }
    
    return 0;
}
```