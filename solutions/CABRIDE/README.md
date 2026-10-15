# [Cab Rides (CABRIDE)](https://www.codechef.com/problems/CABRIDE)

- **Difficulty Rating**: 945
- **Solved in**: 1 attempt(s)

## Problem Summary
We need to transport $N$ people using cabs, where each cab can hold a maximum of 4 people. The cost for a single cab carrying $X$ people is defined as $\max(200, 100 \times X)$. Our goal is to find the minimum total cost to transport all $N$ people.

## Intuition & Mathematical Observation
The cost function for a single cab is:
- 1 person: $\max(200, 100) = 200$
- 2 people: $\max(200, 200) = 200$
- 3 people: $\max(200, 300) = 300$
- 4 people: $\max(200, 400) = 400$

Notice that the cost per person is minimized when we put 2 people in a cab ($200/2 = 100$ per person) or 4 people in a cab ($400/4 = 100$ per person). Putting 1 or 3 people in a cab is less efficient.

Since $N$ is small ($N \le 50$), we can use **Dynamic Programming** to find the optimal combination of cab capacities. We define `dp[i]` as the minimum cost to transport `i` people. For each state `i`, we can transition by adding a cab containing $j$ people (where $1 \le j \le 4$):
$$dp[i] = \min_{1 \le j \le 4} (dp[i-j] + \text{cost}(j))$$

## Complexity Analysis
- **Time Complexity**: $O(N \times K)$, where $N$ is the number of people and $K=4$ is the maximum capacity per cab. Given $N \le 50$, this is effectively $O(N)$.
- **Space Complexity**: $O(N)$ to store the DP array.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A cab can hold at most 4 people.
 * Cost for X people in one cab = max(200, 100 * X).
 * 
 * We use Dynamic Programming to find the minimum cost for N people.
 */

void solve() {
    int N;
    cin >> N;
    
    // dp[i] = minimum cost to transport i people
    // Initialize with a large value
    vector<long long> dp(N + 1, 1e18);
    dp[0] = 0;
    
    for (int i = 1; i <= N; ++i) {
        // Try putting j people in the last cab (1 <= j <= 4)
        for (int j = 1; j <= 4 && i - j >= 0; ++j) {
            long long cost = max(200, 100 * j);
            dp[i] = min(dp[i], dp[i - j] + cost);
        }
    }
    
    cout << dp[N] << "\n";
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