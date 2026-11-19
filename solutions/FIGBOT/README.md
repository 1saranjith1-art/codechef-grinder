# [FightBots (FIGBOT)](https://www.codechef.com/problems/FIGBOT)

- **Difficulty Rating**: 1329
- **Solved in**: 1 attempt(s)

## Problem Summary
Alice starts at $(0, 0)$ and follows a sequence of $N$ moves (Up, Down, Left, Right). Bob starts at $(X, Y)$. At each second $k$ (from $1$ to $N$), Alice moves to a new position $(Ax_k, Ay_k)$. We need to determine if there exists any time $k$ such that Bob can reach Alice's position $(Ax_k, Ay_k)$ starting from $(X, Y)$ within exactly $k$ seconds.

## Intuition & Mathematical Observation
To determine if Bob can reach Alice's position at time $k$, we use the properties of Manhattan distance on a 2D grid:

1.  **Distance Constraint**: The Manhattan distance between Bob's starting position $(X, Y)$ and Alice's position $(Ax_k, Ay_k)$ is defined as $dist = |Ax_k - X| + |Ay_k - Y|$. Bob can only reach this point if he has enough time, meaning $k \ge dist$.
2.  **Parity Constraint**: In each second, Bob must move to an adjacent cell (changing his Manhattan distance to the target by exactly $1$). This implies that the parity of the number of steps taken must match the parity of the Manhattan distance. Specifically, $(k - dist)$ must be an even number, or equivalently, $k \equiv dist \pmod 2$.

If both conditions ($k \ge dist$ and $k \equiv dist \pmod 2$) are satisfied for any $k \in [1, N]$, Bob can successfully intercept Alice.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the string of moves exactly once.
- **Space Complexity**: $O(N)$ to store the input string $S$, or $O(1)$ if we process the characters one by one.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Alice starts at (0, 0). Bob starts at (X, Y).
 * After k seconds (1 <= k <= N), Alice is at some position (Ax_k, Ay_k).
 * The Manhattan distance between Bob's starting position and Alice's position at time k is:
 * dist = |Ax_k - X| + |Ay_k - Y|.
 * 
 * Bob can reach Alice's position at time k if and only if:
 * 1. The Manhattan distance between Bob's start and Alice's position is <= k.
 * 2. The parity of the Manhattan distance is the same as the parity of k.
 */

void solve() {
    int N;
    long long X, Y;
    cin >> N >> X >> Y;
    string S;
    cin >> S;

    long long ax = 0, ay = 0;
    bool possible = false;

    for (int k = 1; k <= N; ++k) {
        char move = S[k - 1];
        if (move == 'L') ax -= 1;
        else if (move == 'R') ax += 1;
        else if (move == 'U') ay += 1;
        else if (move == 'D') ay -= 1;

        long long dist = abs(ax - X) + abs(ay - Y);
        
        // Bob can reach (ax, ay) at time k if:
        // 1. He has enough time (k >= dist)
        // 2. The parity of the distance matches the time (k % 2 == dist % 2)
        if (k >= dist && (k % 2 == dist % 2)) {
            possible = true;
            break;
        }
    }

    if (possible) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
```