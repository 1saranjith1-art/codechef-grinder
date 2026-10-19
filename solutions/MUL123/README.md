# [Make Multiple (MUL123)](https://www.codechef.com/problems/MUL123)

- **Difficulty Rating**: 959
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an integer $N$, we want to reach a number that is a multiple of 3 using the minimum number of operations. The allowed operations are:
1. Increment $N$ by 1 ($N = N + 1$).
2. Replace $N$ with the next multiple of 5 ($N = \text{next\_multiple\_of\_5}(N)$).

We need to find the shortest sequence of operations to make $N$ divisible by 3.

## Intuition & Mathematical Observation
Since the goal is to find the *shortest* path to a target state (any number $X$ where $X \equiv 0 \pmod 3$), **Breadth-First Search (BFS)** is the ideal algorithm. 

- **State Space**: The value of $N$ starts at most at 100. Even with the "next multiple of 5" operation, the numbers will not grow excessively large before hitting a multiple of 3. A limit of 500 for our `dist` array is more than sufficient to capture all reachable states.
- **Transitions**:
    - From $N$, we can move to $N+1$.
    - From $N$, we can move to `((N / 5) + 1) * 5`.
- **BFS Logic**: By using a queue, we explore all states reachable in 1 operation, then 2, and so on. The first time we encounter a number divisible by 3, the current distance is guaranteed to be the minimum.

## Complexity Analysis
- **Time Complexity**: $O(V + E)$, where $V$ is the number of states (500) and $E$ is the number of transitions (2 per state). Since the state space is constant and small, this effectively runs in $O(1)$ per test case.
- **Space Complexity**: $O(V)$, where $V$ is the size of the `dist` array (500), used to keep track of visited states and their distances.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We start with N. We have two operations:
 * 1. N = N + 1
 * 2. N = next_multiple_of_5(N)
 * 
 * Since N is small (up to 100), we can use Breadth-First Search (BFS) 
 * to find the shortest path to a multiple of 3.
 */

void solve() {
    int N;
    cin >> N;

    // If already a multiple of 3, 0 operations needed
    if (N % 3 == 0) {
        cout << 0 << "\n";
        return;
    }

    // dist[i] stores minimum operations to reach i
    vector<int> dist(500, -1);
    queue<int> q;

    q.push(N);
    dist[N] = 0;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        // Check if current number is a multiple of 3
        if (curr % 3 == 0) {
            cout << dist[curr] << "\n";
            return;
        }

        // Operation 1: Add 1
        int next1 = curr + 1;
        if (next1 < 500 && dist[next1] == -1) {
            dist[next1] = dist[curr] + 1;
            q.push(next1);
        }

        // Operation 2: Next multiple of 5
        int next2 = ((curr / 5) + 1) * 5;
        if (next2 < 500 && dist[next2] == -1) {
            dist[next2] = dist[curr] + 1;
            q.push(next2);
        }
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