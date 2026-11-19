# [Accommodation (ACMDT)](https://www.codechef.com/problems/ACMDT)

- **Difficulty Rating**: 1286
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given $B$ boys and $G$ girls who need to be accommodated in rooms. Each room must contain at least $X$ boys and $Y$ girls, and the total number of people in any room cannot exceed $N$. We need to find the minimum number of rooms required to accommodate all $B+G$ people while satisfying these constraints. If it is impossible, output -1.

## Intuition & Mathematical Observation
To solve this, we define the constraints on the number of rooms, $k$:

1.  **Capacity Constraint**: Each room has a maximum capacity of $N$. Therefore, the total number of rooms must be at least enough to hold all people:
    $$k \ge \lceil \frac{B + G}{N} \rceil$$
    Let `min_rooms` = $\lceil \frac{B + G}{N} \rceil$.

2.  **Minimum Requirement Constraint**: Each room must contain at least $X$ boys and $Y$ girls. This implies:
    *   $k \cdot X \le B \implies k \le \lfloor \frac{B}{X} \rfloor$
    *   $k \cdot Y \le G \implies k \le \lfloor \frac{G}{Y} \rfloor$
    
    Combining these, the maximum number of rooms we can form while ensuring every room meets the minimum requirement is:
    `max_rooms` = $\min(\lfloor \frac{B}{X} \rfloor, \lfloor \frac{G}{Y} \rfloor)$.

3.  **Feasibility**:
    *   If $X + Y > N$, it is impossible to satisfy the minimum requirement in any room, so we output -1.
    *   If `min_rooms > max_rooms`, it is impossible to satisfy both the capacity limit and the minimum requirements simultaneously, so we output -1.
    *   Otherwise, the minimum number of rooms required is simply `min_rooms`.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves basic arithmetic operations. With $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and calculated values.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Each room must have at least X boys and Y girls.
 * Total capacity of each room is at most N.
 * Therefore, each room must contain at least (X + Y) people.
 * If (X + Y) > N, it is impossible to satisfy the constraints, so output -1.
 */

void solve() {
    long long B, G, X, Y, N;
    cin >> B >> G >> X >> Y >> N;

    // If the minimum requirement exceeds the room capacity, it's impossible.
    if (X + Y > N) {
        cout << -1 << "\n";
        return;
    }

    // Minimum rooms required to fit all people given capacity N:
    // ceil((B + G) / N) calculated using integer division: (B + G + N - 1) / N
    long long min_rooms = (B + G + N - 1) / N;

    // Maximum rooms possible given the constraints on boys and girls:
    // Each room must have at least X boys and Y girls.
    long long max_rooms = min(B / X, G / Y);

    // If the minimum required rooms exceed the maximum allowed rooms, it's impossible.
    if (min_rooms > max_rooms) {
        cout << -1 << "\n";
    } else {
        cout << min_rooms << "\n";
    }
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