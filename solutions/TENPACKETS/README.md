# [Buy Ten Packets (TENPACKETS)](https://www.codechef.com/problems/TENPACKETS)

- **Difficulty Rating**: 669
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef needs to purchase exactly 10 packets of noodles. He has two purchasing options:
1. Buy a pack of 2 for $X$ rupees.
2. Buy a pack of 4 for $Y$ rupees.

The goal is to determine the minimum cost to acquire exactly 10 packets.

## Intuition & Mathematical Observation
To get exactly 10 packets, we can analyze the possible combinations of the given packs:

1. **Using only 2-packs**: We need $10 / 2 = 5$ packs. The cost is $5 \times X$.
2. **Using 4-packs and 2-packs**: To maximize the use of the larger (and potentially cheaper) 4-packs, we can buy two 4-packs (totaling 8 packets) and one 2-pack (totaling 2 packets). The cost is $2 \times Y + X$.

*Note: While the problem states $Y \le 2X$, which implies that a 4-pack is always more cost-effective than two 2-packs, we still need to compare the total cost of the specific combinations required to reach exactly 10.*

By calculating both `5 * X` and `2 * Y + X`, we can simply output the minimum of the two values.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. Each test case performs a constant number of arithmetic operations.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and results.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef needs 10 packets.
 * Options:
 * - 2 packets for X
 * - 4 packets for Y
 * 
 * Possible combinations to get 10 packets:
 * 1. Five 2-packs: 5 * X
 * 2. Two 4-packs and one 2-pack: 2 * Y + X
 * 
 * We need to find the minimum of these two values.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long x, y;
        cin >> x >> y;

        // Option 1: 5 * 2-packs = 5 * X
        long long option1 = 5 * x;

        // Option 2: 2 * 4-packs + 1 * 2-pack = 2 * Y + X
        long long option2 = 2 * y + x;

        // Output the minimum
        cout << min(option1, option2) << "\n";
    }

    return 0;
}
```