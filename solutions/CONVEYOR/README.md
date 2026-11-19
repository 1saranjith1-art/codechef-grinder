# [Conveyor Belt (CONVEYOR)](https://www.codechef.com/problems/CONVEYOR)

- **Difficulty Rating**: 1034
- **Solved in**: 3 attempt(s)

## Problem Summary
You are given a conveyor belt with $N$ slots, indexed from $1$ to $N$. A package starts at position $P$. Each slot contains a direction: 'L' (moves the package to the left, $i-1$) or 'R' (moves the package to the right, $i+1$). The package falls off the belt if it reaches index $0$ or index $N+1$. You can change the direction of any slot at the cost of 1 operation per change. The goal is to find the minimum number of operations required to make the package fall off the belt either at the left end ($0$) or the right end ($N+1$).

## Intuition & Mathematical Observation
To make the package fall off the belt, we have two primary strategies:

1.  **Exit Left (Index 0):** For the package to reach index $0$ starting from $P$, every slot from $1$ to $P$ must be set to 'L'. If any slot in this range is currently 'R', it must be flipped. The cost is the count of 'R' characters in the substring $S[0 \dots P-1]$.
2.  **Exit Right (Index $N+1$):** For the package to reach index $N+1$ starting from $P$, every slot from $P$ to $N$ must be set to 'R'. If any slot in this range is currently 'L', it must be flipped. The cost is the count of 'L' characters in the substring $S[P-1 \dots N-1]$.

The final answer is simply the minimum of these two calculated costs: `min(cost_left, cost_right)`.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the string at most twice to count the necessary changes.
- **Space Complexity**: $O(N)$ to store the string $S$ representing the conveyor belt.

## Solution Code

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem: CONVEYOR
 * Logic:
 * To reach the left end (0), all slots from 1 to P must be 'L'.
 * To reach the right end (N+1), all slots from P to N must be 'R'.
 * We calculate the number of changes needed for both paths and take the minimum.
 */

void solve() {
    int N, P;
    cin >> N >> P;
    string S;
    cin >> S;

    // S is 0-indexed, so slot i is S[i-1]
    
    // Cost to go Left: Need all slots from 1 to P to be 'L'
    int cost_left = 0;
    for (int i = 0; i < P; ++i) {
        if (S[i] == 'R') {
            cost_left++;
        }
    }

    // Cost to go Right: Need all slots from P to N to be 'R'
    int cost_right = 0;
    for (int i = P - 1; i < N; ++i) {
        if (S[i] == 'L') {
            cost_right++;
        }
    }

    cout << min(cost_left, cost_right) << endl;
}

int main() {
    // Optimize I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}
```