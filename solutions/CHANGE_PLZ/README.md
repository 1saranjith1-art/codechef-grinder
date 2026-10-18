# [Change Please (CHANGE_PLZ)](https://www.codechef.com/problems/CHANGE_PLZ)

- **Difficulty Rating**: 760
- **Solved in**: 1 attempt(s)

## Problem Summary
You pay a driver 100 dollars for a ride that costs $X$ dollars. The driver needs to return the change, which is $(100 - X)$ dollars. However, the driver only carries 10-dollar bills. You need to determine the total amount the driver will return to you, given that they can only return the largest multiple of 10 that is less than or equal to the actual change owed.

## Intuition & Mathematical Observation
1. **Calculate the Change Owed**: The total change the driver owes is $R = 100 - X$.
2. **Constraint**: The driver can only return multiples of 10.
3. **Mathematical Logic**: To find the largest multiple of 10 less than or equal to $R$, we can use integer division. In C++, dividing an integer by 10 automatically truncates the decimal part (effectively performing a `floor` operation).
   - Let `bills = (100 - X) / 10`.
   - The total amount returned is `bills * 10`.
   - For example, if $X = 83$, change owed is 17. $17 / 10 = 1$ (integer division). The driver returns $1 \times 10 = 10$.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. Each test case involves basic arithmetic operations which take $O(1)$ time.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the input and the result, regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * You pay 100 dollars. The cost is X.
 * The change owed to you is (100 - X).
 * The driver only has 10 dollar bills.
 * The driver can only return multiples of 10 that are less than or equal to (100 - X).
 * 
 * Let R = 100 - X be the amount owed.
 * We need to find the largest multiple of 10 such that 10 * k <= R.
 * This is equivalent to floor(R / 10) * 10.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int x;
        cin >> x;
        
        // Calculate the amount the driver owes back
        int change_owed = 100 - x;
        
        // The driver can only return multiples of 10.
        // We use integer division to find how many 10-dollar bills fit.
        int bills = change_owed / 10;
        
        // The total amount returned is bills * 10
        int result = bills * 10;
        
        cout << result << "\n";
    }
    
    return 0;
}
```