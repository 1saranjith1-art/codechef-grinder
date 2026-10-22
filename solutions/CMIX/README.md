# [Spell Splice (CMIX)](https://www.codechef.com/problems/CMIX)

- **Difficulty Rating**: 910
- **Solved in**: 3 attempt(s)

## Problem Summary
You are given $N$ spells, each characterized by two values: $V_i$ (base power) and $A_i$ (affinity). When you combine two distinct spells $i$ and $j$, the resulting strength is calculated as:
$$\text{Strength} = (V_i \times A_j) + (V_j \times A_i)$$
The goal is to find the maximum possible strength that can be achieved by choosing any two distinct spells from the given list.

## Intuition & Mathematical Observation
The problem asks us to maximize the expression $(V_i \times A_j) + (V_j \times A_i)$ for all pairs $(i, j)$ where $i \neq j$. 

Given the constraint $N \le 100$, the total number of pairs is $\frac{N(N-1)}{2}$, which is approximately 5,000. Since we have multiple test cases, an $O(N^2)$ approach per test case is perfectly efficient. We can simply iterate through every possible pair of spells, calculate their combined strength, and keep track of the maximum value found so far.

## Complexity Analysis
- **Time Complexity**: $O(T \times N^2)$, where $T$ is the number of test cases and $N$ is the number of spells. With $N \le 100$, this results in roughly $10^6$ operations, well within the 1-second time limit.
- **Space Complexity**: $O(N)$ to store the spell values in a vector.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem: CMIX
 * Complexity: O(T * N^2)
 * The constraints N <= 100 allow for an O(N^2) approach per test case.
 * Total operations ~ 10^6, which is well within the 1-second limit.
 */

struct Spell {
    long long v, a;
};

void solve() {
    int n;
    if (!(cin >> n)) return;
    
    vector<Spell> spells(n);
    for (int i = 0; i < n; ++i) {
        cin >> spells[i].v >> spells[i].a;
    }

    // Initialize with a value smaller than any possible result.
    // Minimum possible strength is 1*1 + 1*1 = 2.
    long long max_strength = -1;

    // Iterate through all unique pairs (i, j) where i < j
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            // Formula: A_i * V_j + V_i * A_j
            long long current_strength = (spells[i].a * spells[j].v) + (spells[i].v * spells[j].a);
            if (current_strength > max_strength) {
                max_strength = current_strength;
            }
        }
    }

    cout << max_strength << "\n";
}

int main() {
    // Optimize I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
```