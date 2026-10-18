# [Covid Run (CVDRUN)](https://www.codechef.com/problems/CVDRUN)

- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary
There are $N$ cities arranged in a circle, labeled from $0$ to $N-1$. A virus starts at city $X$ and jumps to city $(X + K) \pmod N$ in each step. We need to determine if the virus will ever reach city $Y$ given the parameters $N, K, X,$ and $Y$.

## Intuition & Mathematical Observation
The virus follows a sequence of cities defined by $X_i = (X + i \cdot K) \pmod N$. Since there are only $N$ possible cities, the sequence must eventually repeat. 

Mathematically, the virus reaches city $Y$ if there exists a non-negative integer $i$ such that:
$$(X + i \cdot K) \equiv Y \pmod N$$
This is equivalent to solving the linear congruence:
$$i \cdot K \equiv (Y - X) \pmod N$$

Given that $N$ is small ($N \le 1000$), we do not need to solve this using the Extended Euclidean Algorithm. Instead, we can simply simulate the process. Since the sequence must repeat after at most $N$ steps, we can track visited cities or simply iterate $N$ times. If we encounter $Y$ during this simulation, the answer is "YES"; otherwise, it is "NO".

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we perform at most $N$ jumps.
- **Space Complexity**: $O(N)$ to store the `visited` array, which keeps track of the cities already checked to prevent infinite loops.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The virus starts at X and jumps by K modulo N.
 * The sequence of cities visited is:
 * X, (X+K)%N, (X+2K)%N, (X+3K)%N, ...
 * This is a sequence in a cyclic group of order N.
 * The virus will visit city Y if and only if Y is reachable from X.
 * Since N is small (up to 1000), we can simply simulate the process.
 * The virus will revisit the starting city X after at most N steps.
 * If we haven't reached Y by the time we return to X, we never will.
 */

void solve() {
    int N, K, X, Y;
    if (!(cin >> N >> K >> X >> Y)) return;

    // Use a boolean array to keep track of visited cities to detect cycles
    // or simply limit the number of jumps to N.
    vector<bool> visited(N, false);
    
    int current = X;
    bool found = false;
    
    // We can perform at most N jumps before the sequence repeats.
    for (int i = 0; i < N; ++i) {
        if (current == Y) {
            found = true;
            break;
        }
        
        // If we hit a city we've already visited and it's not Y, 
        // we are in a cycle that doesn't contain Y.
        if (visited[current]) {
            break;
        }
        
        visited[current] = true;
        current = (current + K) % N;
    }
    
    if (found) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O setup
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