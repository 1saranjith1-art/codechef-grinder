# [Andrew and the Meatballs (AMMEAT)](https://www.codechef.com/problems/AMMEAT)

- **Difficulty Rating**: 1275
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given $N$ plates, each containing a specific number of meatballs. We need to collect at least $M$ meatballs. The goal is to find the minimum number of plates required to reach this target. If it is impossible to collect $M$ meatballs even by taking all plates, we should output -1.

## Intuition & Mathematical Observation
To minimize the number of plates used, we must prioritize plates that contain the highest number of meatballs. This is a classic **Greedy** problem:

1. **Feasibility Check**: First, calculate the sum of all meatballs across all $N$ plates. If the total sum is less than $M$, it is impossible to satisfy the requirement, so we output -1.
2. **Greedy Strategy**: Sort the plates in descending order based on the number of meatballs they contain.
3. **Selection**: Iterate through the sorted list, adding the number of meatballs from each plate to a running total. Keep track of how many plates have been used. As soon as the running total is greater than or equal to $M$, the current count of plates is our answer.

Since $M$ and the number of meatballs per plate can be as large as $10^{18}$, it is crucial to use the `long long` data type in C++ to prevent integer overflow.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ per test case, primarily due to the sorting step. The subsequent linear scan takes $O(N)$. Given the constraints, this is well within the time limits.
- **Space Complexity**: $O(N)$ to store the number of meatballs for each plate.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N plates with P_i meatballs. We need at least M meatballs.
 * To minimize the number of plates, we should always pick the plates with the 
 * largest number of meatballs first (Greedy approach).
 */

void solve() {
    int n;
    long long m;
    cin >> n >> m;
    
    vector<long long> p(n);
    long long total_sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        total_sum += p[i];
    }
    
    // If total meatballs available are less than required, impossible.
    if (total_sum < m) {
        cout << -1 << "\n";
        return;
    }
    
    // Sort in descending order to pick largest plates first
    sort(p.rbegin(), p.rend());
    
    long long current_sum = 0;
    int count = 0;
    for (int i = 0; i < n; ++i) {
        current_sum += p[i];
        count++;
        if (current_sum >= m) {
            cout << count << "\n";
            return;
        }
    }
}

int main() {
    // Fast I/O
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