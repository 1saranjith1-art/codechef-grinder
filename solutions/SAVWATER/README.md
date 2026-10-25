# [A - Save Water Save Life (SAVWATER)](https://www.codechef.com/problems/SAVWATER)

- **Difficulty Rating**: 918
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine if a given total capacity of water ($C$) is sufficient to support $H$ households. Each household consumes $x$ liters of mandatory freshwater and $y$ liters of greywater. However, the greywater consumption is effectively halved (using floor division) due to recycling. We must output "YES" if the total water required is less than or equal to $C$, and "NO" otherwise.

## Intuition & Mathematical Observation
1. **Consumption Calculation**: For a single household, the total water usage is the sum of the mandatory freshwater ($x$) and the recycled greywater ($\lfloor y/2 \rfloor$).
2. **Total Usage**: Since there are $H$ households, the total water required is $H \times (x + \lfloor y/2 \rfloor)$.
3. **Comparison**: We simply compare this calculated total against the available capacity $C$. If $H \times (x + \lfloor y/2 \rfloor) \le C$, the condition is satisfied.
4. **Integer Division**: In C++, the `/` operator on integers automatically performs floor division, which perfectly matches the requirement $\lfloor y/2 \rfloor$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case. Since we perform a constant number of arithmetic operations, the total time complexity is $O(T)$, where $T$ is the number of test cases.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the calculated result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Each household consumes 'x' liters of mandatory freshwater.
 * Each household consumes 'y' liters of greywater, which is reduced to floor(y/2).
 * Total consumption per household = x + floor(y/2).
 * Total consumption for H households = H * (x + floor(y/2)).
 * We need to check if this total consumption <= C.
 * 
 * Constraints:
 * H, x, y <= 10, C <= 100.
 * The maximum possible consumption is 10 * (10 + 10) = 200, which fits in a standard int.
 * Using long long is safe practice to prevent overflow in competitive programming.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long H, x, y, C;
        cin >> H >> x >> y >> C;

        // Calculate consumption per household
        // floor(y/2) is equivalent to y/2 in integer division
        long long consumption_per_household = x + (y / 2);
        
        // Calculate total consumption for all households
        long long total_consumption = H * consumption_per_household;

        // Check if total consumption is within the available capacity C
        if (total_consumption <= C) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}
```