# [The Minimum Number Of Moves (SALARY)](https://www.codechef.com/problems/SALARY)

- **Difficulty Rating**: 1286
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given $N$ workers, each with a specific salary $W_i$. In one operation, we can choose any one worker and increase the salaries of all *other* $N-1$ workers by 1. The goal is to find the minimum number of operations required to make all workers' salaries equal.

## Intuition & Mathematical Observation
The key insight is to realize that increasing $N-1$ workers by 1 is mathematically equivalent to decreasing the one worker who was *not* chosen by 1, relative to the others. 

If we want to equalize all salaries, we must eventually bring every worker's salary to the same level. Since we can only increase salaries, the target salary for everyone must be at least the current maximum salary. However, because the relative difference between any two workers remains the same if we increase everyone, the only way to reduce the gap between the maximum and minimum salary is to perform the operation on the worker with the maximum salary.

By repeatedly applying the operation to the worker with the maximum salary, we effectively reduce the difference between the maximum and the minimum. 

Mathematically, if the minimum salary in the array is $min\_w$, every worker $i$ with salary $W_i$ must be "reduced" to $min\_w$ relative to the others. The number of operations required for a specific worker $i$ to reach the minimum level is exactly $(W_i - min\_w)$. Summing these differences for all workers gives the total number of operations:
$$\text{Total Operations} = \sum_{i=1}^{N} (W_i - min\_w)$$

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the array twice (once to find the minimum and sum, and once to calculate the total operations).
- **Space Complexity**: $O(N)$ to store the salaries, though this could be optimized to $O(1)$ by calculating the sum and minimum on the fly.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Increasing everyone except worker i by 1 is equivalent to decreasing worker i 
 * by 1 relative to the others. To equalize all to the minimum value, we need 
 * to perform (W_i - min_w) operations for each worker i.
 * Total operations = sum(W_i - min_w) for all i.
 */

void solve() {
    int n;
    cin >> n;
    vector<long long> w(n);
    long long min_w = 20000; // Larger than max constraint 10000
    
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
        if (w[i] < min_w) {
            min_w = w[i];
        }
    }
    
    // The total number of operations is the sum of differences between 
    // each salary and the minimum salary.
    long long total_ops = 0;
    for (int i = 0; i < n; ++i) {
        total_ops += (w[i] - min_w);
    }
    
    cout << total_ops << "\n";
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