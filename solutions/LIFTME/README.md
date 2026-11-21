# [Lift Requests (LIFTME)](https://www.codechef.com/problems/LIFTME)

- **Difficulty Rating**: 1247
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to calculate the total distance traveled by an elevator starting at floor 0. We are given $Q$ requests, where each request consists of a source floor $f_i$ and a destination floor $d_i$. For every request, the elevator must travel from its current position to $f_i$, and then from $f_i$ to $d_i$. After each request, the elevator remains at $d_i$. We need to output the total distance covered across all requests.

## Intuition & Mathematical Observation
The movement of the elevator is sequential. Let `current_floor` be the position of the elevator before a request. For each request $(f_i, d_i)$:
1. The distance to reach the source floor is $|f_i - \text{current\_floor}|$.
2. The distance to reach the destination floor from the source is $|d_i - f_i|$.
3. The total distance for the request is the sum of these two values.
4. After the request, the `current_floor` is updated to $d_i$.

**Key Considerations:**
- **Data Types**: Since the number of floors and requests can be large, the cumulative distance can easily exceed the capacity of a 32-bit integer. Therefore, we must use `long long` to store the `total_distance`.
- **Efficiency**: With $Q$ up to $10^5$, an $O(Q)$ approach per test case is optimal and will comfortably pass within the 1-second time limit. Using Fast I/O (`ios_base::sync_with_stdio(false); cin.tie(NULL);`) is recommended to handle the input volume efficiently.

## Complexity Analysis
- **Time Complexity**: $O(Q)$ per test case, where $Q$ is the number of requests. The total time complexity is $O(\sum Q)$ across all test cases.
- **Space Complexity**: $O(1)$, as we only store a few variables (`current_floor`, `total_distance`, `f`, `d`) regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The lift starts at floor 0.
 * For each request (f_i, d_i):
 * 1. The lift moves from its current position (let's call it 'curr') to f_i.
 *    Distance traveled: |f_i - curr|
 * 2. The lift moves from f_i to d_i.
 *    Distance traveled: |d_i - f_i|
 * 3. Update 'curr' to d_i.
 * 
 * Total distance is the sum of these movements for all Q requests.
 * Since N <= 10^6 and Q <= 10^5, the total distance can exceed 2^31 - 1.
 * We must use 'long long' to store the total distance.
 */

void solve() {
    int N, Q;
    if (!(cin >> N >> Q)) return;

    long long total_distance = 0;
    int current_floor = 0;

    for (int i = 0; i < Q; ++i) {
        int f, d;
        cin >> f >> d;

        // Distance to move to source floor
        total_distance += abs(f - current_floor);
        // Distance to move to destination floor
        total_distance += abs(d - f);

        // Update current floor to the destination
        current_floor = d;
    }

    cout << total_distance << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}
```