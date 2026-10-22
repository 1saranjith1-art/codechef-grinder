# [Minimum Maximum (MNMX)](https://www.codechef.com/problems/MNMX)

- **Difficulty Rating**: 1392
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array of $N$ distinct integers, we perform an operation where we choose two adjacent elements, remove the larger one, and add the smaller one to our total cost. We repeat this process until only one element remains. The goal is to minimize the total cost incurred.

## Intuition & Mathematical Observation
To minimize the total cost, we need to consider the nature of the operation. In each step, we remove one element and add the smaller of the two to the cost. Since we must perform exactly $N-1$ operations to reduce the array to a single element, we want to ensure that the value added to the cost in each operation is as small as possible.

The smallest possible value we can add to the cost in any operation is the global minimum of the array, let's call it `min_val`. 

If we can arrange our operations such that the minimum element is involved in every single operation, the total cost will be:
$$\text{Total Cost} = (N - 1) \times \text{min\_val}$$

Since the minimum element is always smaller than any other element in the array, whenever it is paired with another element, the minimum element will always be the one kept, and its value will be added to the cost. Because we can always manipulate the order of operations to ensure the minimum element "consumes" all other elements, this strategy is optimal.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we only need to iterate through the array once to find the minimum element.
- **Space Complexity**: $O(1)$, as we only store the minimum value and the current input value, requiring constant extra space.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have an array of N distinct integers.
 * In each operation, we pick two adjacent elements, remove the larger one,
 * and add the smaller one to the cost.
 * 
 * Strategy:
 * To minimize the total cost, we use the minimum element of the array 
 * to eliminate all other N-1 elements. Since the minimum element is 
 * smaller than any other element, it will always be the one kept, 
 * and its value will be added to the cost in every operation.
 * 
 * Total cost = (N - 1) * min_val.
 */

void solve() {
    int n;
    if (!(cin >> n)) return;
    
    long long min_val = -1;
    for (int i = 0; i < n; ++i) {
        long long val;
        cin >> val;
        // Find the minimum element in the array
        if (i == 0 || val < min_val) {
            min_val = val;
        }
    }
    
    // The minimum cost is (N-1) * min_val
    long long result = (long long)(n - 1) * min_val;
    cout << result << "\n";
}

int main() {
    // Fast I/O for performance
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