# [Chef and Serves (CHSERVE)](https://www.codechef.com/problems/CHSERVE)

- **Difficulty Rating**: 1101
- **Solved in**: 3 attempt(s)

## Problem Summary
In a game of table tennis, Chef and Cook take turns serving. The server changes every $K$ points. Specifically, the first $K$ points are served by Chef, the next $K$ points by Cook, the next $K$ by Chef, and so on. Given the current score of Chef ($P1$) and Cook ($P2$), determine who is currently serving.

## Intuition & Mathematical Observation
The total number of points played in the game is $S = P1 + P2$. Since the server changes every $K$ points, we can determine how many "blocks" of $K$ serves have been completed by calculating:
$$\text{blocks} = \lfloor \frac{P1 + P2}{K} \rfloor$$

By observing the pattern:
- **0 to $K-1$ points**: 0 blocks completed $\rightarrow$ Chef serves (Even)
- **$K$ to $2K-1$ points**: 1 block completed $\rightarrow$ Cook serves (Odd)
- **$2K$ to $3K-1$ points**: 2 blocks completed $\rightarrow$ Chef serves (Even)
- **$3K$ to $4K-1$ points**: 3 blocks completed $\rightarrow$ Cook serves (Odd)

We can conclude that if the number of completed blocks is **even**, it is Chef's turn. If the number of completed blocks is **odd**, it is Cook's turn.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves only basic arithmetic operations.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * Total points played: S = P1 + P2.
 * The server changes every K points.
 * Number of full K-point intervals passed: blocks = (P1 + P2) / K.
 * 
 * - 0 to K-1 points: Chef serves (0 blocks)
 * - K to 2K-1 points: Cook serves (1 block)
 * - 2K to 3K-1 points: Chef serves (2 blocks)
 * - 3K to 4K-1 points: Cook serves (3 blocks)
 * 
 * Rule: If (blocks % 2 == 0), it is Chef's turn. Otherwise, it is Cook's turn.
 * 
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Optimize standard I/O operations for speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long p1, p2, k;
        cin >> p1 >> p2 >> k;

        // Calculate total points and the number of completed K-point intervals
        long long total_points = p1 + p2;
        long long blocks = total_points / k;

        // Determine the server based on the parity of the blocks
        if (blocks % 2 == 0) {
            cout << "CHEF" << "\n";
        } else {
            cout << "COOK" << "\n";
        }
    }

    return 0;
}
```