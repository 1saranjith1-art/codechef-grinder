# [Chess Pairing (CHESS_PAIR)](https://www.codechef.com/problems/CHESS_PAIR)

- **Difficulty Rating**: 892
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given $2N$ total players, where $X$ players are rated and the remaining $(2N - X)$ players are unrated. We need to form $N$ pairs of players such that the number of rated players paired with other rated players is minimized. We are asked to output this minimum number.

## Intuition & Mathematical Observation
To minimize the number of rated players paired with other rated players, we should prioritize pairing rated players with unrated players.

1.  **Total Players**: $2N$
2.  **Rated Players ($X$)**: $X$
3.  **Unrated Players ($U$)**: $2N - X$

Each unrated player can "neutralize" one rated player by being paired with them. 
*   If the number of rated players $X$ is less than or equal to the number of available slots for unrated pairings (which is $N$, since we can pair all $X$ rated players with $X$ unrated players), then we can ensure no two rated players are paired together. Thus, the answer is **0**.
*   If $X > N$, we have more rated players than we can pair with unrated players. We use all $U = (2N - X)$ unrated players to pair with $(2N - X)$ rated players. 
*   The remaining rated players are $X - (2N - X) = 2X - 2N = 2(X - N)$. 
*   Since these remaining players must be paired with each other, all of them will be paired with another rated player. Therefore, the number of rated players with rated opponents is $2(X - N)$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves simple arithmetic operations. With $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have 2N total players, X of whom are rated.
 * We want to minimize the number of rated players paired with other rated players.
 * 
 * Let R = X (rated players)
 * Let U = 2N - X (unrated players)
 * 
 * If X <= N, we can pair all X rated players with X unrated players. 
 * The number of rated players with rated opponents is 0.
 * 
 * If X > N, we have more rated players than unrated players.
 * We use all U unrated players to pair with U rated players.
 * Remaining rated players = X - U = X - (2N - X) = 2X - 2N = 2 * (X - N).
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n, x;
        cin >> n >> x;

        if (x <= n) {
            cout << 0 << "\n";
        } else {
            // Number of rated players who must be paired with each other
            cout << 2 * (x - n) << "\n";
        }
    }

    return 0;
}
```