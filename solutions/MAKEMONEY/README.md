# [Make Money (MAKEMONEY)](https://www.codechef.com/problems/MAKEMONEY)

- **Difficulty Rating**: 1101
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given $N$ bags, each containing $A_i$ coins. You have the option to replace the number of coins in any bag $i$ with $X$, provided that $A_i \le X$. Each time you perform this operation, you must pay a cost of $C$. The goal is to maximize the total number of coins remaining after subtracting the total cost incurred from the operations.

## Intuition & Mathematical Observation
For each bag $i$, we have two choices:
1. **Keep the original amount $A_i$**: The contribution to the total is simply $A_i$.
2. **Perform the operation**: We replace $A_i$ with $X$ and pay $C$. The net contribution to the total becomes $(X - C)$.

We should perform the operation if and only if the net gain is positive. Specifically, replacing $A_i$ with $X$ is beneficial if:
$$(X - C) > A_i$$

If this condition holds, the bag's value effectively becomes $X$ and we subtract $C$ from our total. If the condition does not hold, it is mathematically better (or neutral) to keep the original value $A_i$, as replacing it would either decrease the total or result in no change.

**Algorithm:**
1. Iterate through each bag $A_i$.
2. Check if $(X - A_i) > C$.
3. If true, count this as an operation and add $X$ to a running total.
4. If false, add $A_i$ to the running total.
5. Finally, subtract the total cost (number of operations $\times C$) from the running total.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the array of $N$ bags exactly once.
- **Space Complexity**: $O(N)$ to store the input array (or $O(1)$ if we process the input values on the fly).

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * For each bag i, if we perform the operation, the net change to the total sum is:
 * (X - A_i) - C.
 * 
 * If (X - A_i) - C > 0, it is beneficial to perform the operation.
 * This is equivalent to X - C > A_i.
 */

void solve() {
    int N;
    long long X, C;
    cin >> N >> X >> C;
    
    vector<long long> A(N);
    long long operations = 0;
    long long final_sum = 0;
    
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        // Check if performing the operation increases the net value
        if (X - A[i] > C) {
            final_sum += X;
            operations++;
        } else {
            final_sum += A[i];
        }
    }
    
    // Subtract the total cost incurred from the operations
    cout << final_sum - (operations * C) << "\n";
}

int main() {
    // Fast I/O
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