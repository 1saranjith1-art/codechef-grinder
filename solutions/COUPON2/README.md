# [Chef and Coupon (COUPON2)](https://www.codechef.com/problems/COUPON2)

- **Difficulty Rating**: 1222
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef wants to order food for two days. Each day, he orders three items. There is a delivery charge $D$ for each order unless the total cost of items on that day is at least 150. Chef can also purchase a coupon for price $C$, which makes the delivery charge 0 for both days, regardless of the order totals. We need to determine if buying the coupon is strictly cheaper than not buying it.

## Intuition & Mathematical Observation
To decide whether to buy the coupon, we compare two scenarios:

1.  **Without Coupon**:
    *   Chef pays for all items on Day 1 ($SumA$) and Day 2 ($SumB$).
    *   Chef pays the delivery charge $D$ for Day 1 if $SumA < 150$.
    *   Chef pays the delivery charge $D$ for Day 2 if $SumB < 150$.
    *   Total Cost = $SumA + SumB + (\text{delivery}_1) + (\text{delivery}_2)$, where $\text{delivery}_i = D$ if $Sum_i < 150$ else $0$.

2.  **With Coupon**:
    *   Chef pays for all items on Day 1 ($SumA$) and Day 2 ($SumB$).
    *   Chef pays the coupon price $C$.
    *   Delivery charges are waived for both days.
    *   Total Cost = $SumA + SumB + C$.

**Decision Rule**:
Buy the coupon if `CostWithCoupon < CostWithoutCoupon`.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations.
- **Space Complexity**: $O(1)$, as we only use a fixed number of variables to store the sums and costs.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * - Cost without coupon: (SumA + delivery_charge_day1) + (SumB + delivery_charge_day2)
 * - Cost with coupon: SumA + SumB + C
 * 
 * Chef buys the coupon if: Cost_with_coupon < Cost_without_coupon
 */

void solve() {
    long long D, C;
    cin >> D >> C;
    
    long long A1, A2, A3;
    cin >> A1 >> A2 >> A3;
    long long sumA = A1 + A2 + A3;
    
    long long B1, B2, B3;
    cin >> B1 >> B2 >> B3;
    long long sumB = B1 + B2 + B3;
    
    // Cost without coupon
    long long deliveryDay1 = (sumA >= 150) ? 0 : D;
    long long deliveryDay2 = (sumB >= 150) ? 0 : D;
    long long costWithout = sumA + sumB + deliveryDay1 + deliveryDay2;
    
    // Cost with coupon
    long long costWith = sumA + sumB + C;
    
    if (costWith < costWithout) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
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