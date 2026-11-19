# [Car Range (CARRANGE)](https://www.codechef.com/problems/CARRANGE)

- **Difficulty Rating**: 938
- **Solved in**: 1 attempt(s)

## Problem Summary
A car has a fuel capacity of $V$ litres. When there is only the driver in the car, the fuel economy is $M$ km/l. For every additional passenger (beyond the driver), the fuel economy decreases by 1 km/l. Given the total number of people $P$ (including the driver), calculate the maximum distance the car can travel.

## Intuition & Mathematical Observation
1. **Identify the variables**:
   - $P$: Total people in the car.
   - $M$: Fuel economy with only the driver.
   - $V$: Total fuel in litres.
2. **Calculate extra passengers**: Since the driver is already included in $P$, the number of extra passengers is $(P - 1)$.
3. **Calculate effective fuel economy**: Each extra passenger reduces the mileage by 1 km/l. Therefore, the new fuel economy is $M - (P - 1)$.
4. **Calculate distance**: The total distance is simply the product of the effective fuel economy and the total fuel capacity:
   $$\text{Distance} = (M - (P - 1)) \times V$$

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the calculation involves basic arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * - Base fuel economy is M km/l (for 1 person).
 * - Every extra passenger decreases fuel economy by 1 km/l.
 * - Total people = P.
 * - Extra passengers = P - 1.
 * - Effective fuel economy = M - (P - 1).
 * - Total fuel = V litres.
 * - Max distance = Effective fuel economy * V.
 * 
 * Constraints:
 * T <= 3*10^4, P <= 5, M <= 56, V <= 100.
 * The result will fit in a standard integer, but using long long is safe.
 * Time complexity per test case: O(1).
 * Total time complexity: O(T).
 */

int main() {
    // Optimize standard I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long P, M, V;
        cin >> P >> M >> V;

        // Calculate effective fuel economy
        // The driver is 1 person, so there are (P - 1) extra passengers.
        long long effective_economy = M - (P - 1);

        // Calculate maximum distance
        long long max_distance = effective_economy * V;

        cout << max_distance << "\n";
    }

    return 0;
}
```