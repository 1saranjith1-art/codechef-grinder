# [Buying Sweets (BUYING2)](https://www.codechef.com/problems/BUYING2)

- **Difficulty Rating**: 1133
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given $N$ banknotes with various denominations and the cost $X$ of a single sweet. You want to determine the maximum number of sweets you can buy. However, there is a constraint: the shopkeeper is "adequate" only if removing any single banknote from your collection results in a total sum that is insufficient to buy the same number of sweets you could have bought with all banknotes combined. If this condition is not met, you cannot buy any sweets (output -1). Otherwise, output the maximum number of sweets.

## Intuition & Mathematical Observation
1. **Calculate Potential Sweets**: Let $S$ be the total sum of all banknotes. The maximum number of sweets you can buy is $K = \lfloor S / X \rfloor$.
2. **The "Adequate" Condition**: The problem states that if you remove any banknote $A_i$, the remaining sum $(S - A_i)$ must be less than $K \times X$.
   - We know $S = K \times X + R$, where $R$ is the remainder ($0 \le R < X$).
   - The condition $(S - A_i) < K \times X$ simplifies to:
     $(K \times X + R - A_i) < K \times X$
     $R - A_i < 0 \implies R < A_i$.
3. **Logical Deduction**: For the condition to hold for *all* banknotes, it must specifically hold for the smallest banknote in your collection ($min(A_i)$).
   - If $R < min(A_i)$, then $R < A_i$ for every banknote, meaning the condition is satisfied. The answer is $K$.
   - If $R \ge min(A_i)$, then removing the smallest banknote leaves you with enough money to still buy $K$ sweets (or more), violating the condition. In this case, the answer is $-1$.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of banknotes. We iterate through the array once to calculate the sum and find the minimum value.
- **Space Complexity**: $O(1)$ auxiliary space (or $O(N)$ if storing the input array), as we only need to track the running sum and the minimum value.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let S be the sum of all banknotes.
 * The maximum number of sweets the customer can buy is K = floor(S / X).
 * 
 * The condition for an "adequate" customer is:
 * If you remove any single banknote A_i, the remaining sum (S - A_i) 
 * must be less than K * X.
 * 
 * If (S - A_i) < K * X for all i, then the customer is adequate.
 * Since K = floor(S / X), we know S = K * X + R, where 0 <= R < X.
 * The condition (S - A_i) < K * X is equivalent to:
 * (K * X + R - A_i) < K * X
 * R - A_i < 0
 * R < A_i
 * 
 * This must hold for all banknotes A_i. 
 * Specifically, it must hold for the smallest banknote, min(A_i).
 * If R < min(A_i), then the customer is adequate and the answer is K.
 * If R >= min(A_i), then removing the smallest banknote still leaves 
 * enough money to buy K sweets, meaning the customer is inadequate.
 */

void solve() {
    int N, X;
    cin >> N >> X;
    
    vector<int> A(N);
    long long sum = 0;
    int min_val = 101; // Constraints state A_i <= 100
    
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        sum += A[i];
        if (A[i] < min_val) {
            min_val = A[i];
        }
    }
    
    long long K = sum / X;
    long long remainder = sum % X;
    
    // If the remainder is greater than or equal to the smallest banknote,
    // we can remove that banknote and still afford K sweets.
    if (remainder >= min_val) {
        cout << -1 << "\n";
    } else {
        cout << K << "\n";
    }
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