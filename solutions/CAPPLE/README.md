# [Chef and Apple Trees (CAPPLE)](https://www.codechef.com/problems/CAPPLE)

- **Difficulty Rating**: 1301
- **Solved in**: 2 attempt(s)

## Problem Summary
Chef has $N$ apple trees, each with a certain number of apples. In one operation, Chef can choose a subset of trees that have the same number of apples and reduce the number of apples on these trees to any value $X$, where $X$ is the number of apples on some other tree (or $X=0$). The goal is to find the minimum number of operations required to pluck all apples (i.e., reduce all trees to 0 apples).

## Intuition & Mathematical Observation
The key observation is that trees with the same number of apples can be processed together in a single operation. 

1. If we have multiple trees with the same number of apples, we can reduce them all to 0 in one step.
2. If we have trees with different numbers of apples, they must be handled in separate operations because the rule states we can only pick a subset of trees that have the **same** number of apples.
3. Therefore, the problem reduces to finding the number of **distinct** values present in the input array. Each distinct value represents a unique group that requires one operation to clear.

By sorting the array, identical values become adjacent, allowing us to count the number of unique elements in a single linear pass.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ due to the sorting step. The subsequent pass to count distinct elements takes $O(N)$, making the overall complexity dominated by the sort.
- **Space Complexity**: $O(N)$ to store the apple counts in a vector.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem Analysis:
 * Each distinct value in the input array represents a group that must be processed. 
 * The minimum time required is exactly the number of distinct values present 
 * in the input.
 */

void solve() {
    int n;
    if (!(cin >> n)) return;
    
    vector<long long> apples(n);
    for (int i = 0; i < n; ++i) {
        cin >> apples[i];
    }
    
    if (n == 0) {
        cout << 0 << "\n";
        return;
    }
    
    // Sort the array to bring identical values together
    sort(apples.begin(), apples.end());
    
    // Count distinct elements
    int distinct_count = 1;
    for (int i = 1; i < n; ++i) {
        if (apples[i] != apples[i - 1]) {
            distinct_count++;
        }
    }
    
    cout << distinct_count << "\n";
}

int main() {
    // Optimize I/O operations for faster execution
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