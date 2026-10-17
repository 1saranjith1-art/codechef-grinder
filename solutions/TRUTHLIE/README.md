# [Truth Teller And Liars 101 (TRUTHLIE)](https://www.codechef.com/problems/TRUTHLIE)

- **Difficulty Rating**: 1097
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given $N$ truth-tellers and $M$ liars. Truth-tellers always provide the correct path, while liars can provide either the correct or incorrect path. You need to determine the minimum number of people $X$ you must ask to be absolutely certain of the correct path, regardless of which $X$ people you choose and regardless of what the liars say. If it is impossible to be certain, output -1.

## Intuition & Mathematical Observation
To be absolutely certain of the correct path, the number of truth-tellers in your chosen group of $X$ people must be strictly greater than the number of liars in that same group. This is because, in the worst-case scenario, all liars could collude to point toward the wrong path, while truth-tellers point toward the correct one.

1.  **Worst-Case Selection**: If you pick $X$ people, the worst-case scenario is that you pick as many liars as possible. If $X \le M$, you could potentially pick $X$ liars and $0$ truth-tellers, making it impossible to distinguish the truth.
2.  **Condition for Certainty**: If $X > M$, you are guaranteed to have at least $X - M$ truth-tellers. For the truth-tellers to outvote the liars, we need:
    $$\text{Truth-tellers} > \text{Liars}$$
    $$(X - M) > M$$
    $$X > 2M$$
    The smallest integer $X$ satisfying this is $2M + 1$.
3.  **Feasibility**: This strategy is only possible if the total number of people available ($N + M$) is at least $2M + 1$.
    $$N + M \ge 2M + 1 \implies N > M$$
    If $N \le M$, even if you ask everyone, the liars could equal or outnumber the truth-tellers, meaning you can never be certain. Thus, if $N \le M$, the answer is $-1$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves a simple comparison and arithmetic operation. The total time complexity is $O(T)$, where $T$ is the number of test cases.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the input and output.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * To be certain of the path, the number of truth-tellers must strictly exceed 
 * the number of liars in any group of size X we choose.
 * 
 * If N <= M, the liars can always outvote or match the truth-tellers, 
 * making it impossible to be certain.
 * 
 * If N > M, we need to pick enough people such that even in the worst-case 
 * (picking all M liars), the remaining people are all truth-tellers and 
 * they outnumber the liars.
 * X - M > M  =>  X > 2M  =>  X = 2M + 1.
 */

void solve() {
    int N, M;
    cin >> N >> M;

    // If truth-tellers are not strictly more than liars, 
    // we cannot guarantee the truth.
    if (N > M) {
        cout << 2 * M + 1 << "\n";
    } else {
        cout << -1 << "\n";
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