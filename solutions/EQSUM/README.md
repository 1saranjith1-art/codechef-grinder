# [Equal Difference (EQSUM)](https://www.codechef.com/problems/EQSUM)

- **Difficulty Rating**: 979
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ of size $N$, we need to find the number of pairs $(i, j)$ such that $1 \le i < j \le N$ and the condition $A[i] - A[j] = i - j$ holds true.

## Intuition & Mathematical Observation
The given condition is:
$$A[i] - A[j] = i - j$$

By rearranging the terms to group indices and values together, we get:
$$A[i] - i = A[j] - j$$

Let $B[k] = A[k] - k$ for all $1 \le k \le N$. The problem reduces to finding the number of pairs $(i, j)$ with $i < j$ such that $B[i] = B[j]$. 

If a specific value $x$ appears $C$ times in the transformed array $B$, the number of ways to choose two distinct indices $i$ and $j$ such that $B[i] = B[j] = x$ is given by the combination formula:
$$\binom{C}{2} = \frac{C \times (C - 1)}{2}$$

We can calculate the frequency of each value in $B$ using a hash map (or a frequency array with an offset) and sum up the combinations for all values that appear at least twice.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ per test case due to the use of a `std::map`. Given the constraints $\sum N \le 2 \times 10^5$, this is well within the time limit. If using `std::unordered_map` or a frequency array, this could be optimized to $O(N)$ on average.
- **Space Complexity**: $O(N)$ to store the frequencies of the transformed values in the map.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The condition A[i] - A[j] = i - j is equivalent to A[i] - i = A[j] - j.
 * We transform the array into B[i] = A[i] - (i + 1) and count occurrences.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    
    // Using a map to store frequencies of (A[i] - i)
    map<int, long long> freq;
    
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        // Calculate transformed value
        int val = A[i] - (i + 1);
        freq[val]++;
    }
    
    long long total_pairs = 0;
    // For each value that appeared 'count' times, add countC2 to total
    for (auto const& [val, count] : freq) {
        if (count >= 2) {
            total_pairs += (count * (count - 1)) / 2;
        }
    }
    
    cout << total_pairs << "\n";
}

int main() {
    // Fast I/O for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
```