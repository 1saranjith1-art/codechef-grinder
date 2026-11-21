# [Red Yellow Cards (RYCARDS)](https://www.codechef.com/problems/RYCARDS)

- **Difficulty Rating**: 985
- **Solved in**: 2 attempt(s)

## Problem Summary
In a game, a player is sent off if they receive:
1. One red card.
2. Two yellow cards.

Additionally, a red card can "absorb" any existing yellow cards (resetting the yellow card count to zero). We are given the total number of red cards ($R$) and yellow cards ($Y$) received by a player. We need to calculate the total number of send-offs, assuming the player plays optimally to minimize the number of send-offs.

## Intuition & Mathematical Observation
To minimize the number of send-offs, we should use the red cards strategically to "absorb" as many yellow cards as possible.

1. **Red Cards**: Every red card results in a send-off. Therefore, we will always have at least $R$ send-offs.
2. **Yellow Cards**: Every two yellow cards result in a send-off.
3. **Optimization**: Since a red card can absorb yellow cards, we should use our $R$ red cards to neutralize up to $R$ yellow cards. 
    - If $Y \le R$, all yellow cards can be absorbed by the red cards, resulting in 0 additional send-offs from yellow cards.
    - If $Y > R$, we use all $R$ red cards to absorb $R$ yellow cards. The remaining yellow cards ($Y - R$) will then form pairs, contributing $(Y - R) / 2$ additional send-offs.

**Formula**:
$$\text{Total Send-offs} = R + \max\left(0, \frac{Y - R}{2}\right)$$

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the calculation involves simple arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the input and the result.

## Solution Code

```cpp
#include <iostream>
#include <algorithm>

using namespace std;

/**
 * Logic:
 * Each red card causes a send-off.
 * Each red card can "absorb" one yellow card.
 * Remaining yellow cards form pairs (2 yellow = 1 send-off).
 * Total send-offs = R + max(0, (Y - R) / 2).
 */

void solve() {
    int R, Y;
    if (!(cin >> R >> Y)) return;

    // Calculate how many yellow cards are left after being absorbed by red cards
    int absorbed = min(Y, R);
    int remaining_y = Y - absorbed;
    
    // Each pair of remaining yellow cards results in a send-off
    int sendoffs = R + (remaining_y / 2);
    
    cout << sendoffs << "\n";
}

int main() {
    // Optimize I/O operations
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