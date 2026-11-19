# [Even Sum Subarray (EVENSUMSUB)](https://www.codechef.com/problems/EVENSUMSUB)

- **Difficulty Rating**: 1079
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ of $N$ integers, the goal is to find the length of the longest contiguous subarray such that the sum of its elements is even.

## Intuition & Mathematical Observation
A subarray sum from index $i$ to $j$ is calculated as the sum of elements $A[i], A[i+1], \dots, A[j]$. 
- A sum is **even** if the count of odd numbers within that subarray is even.
- Since the constraints for $N$ are small ($N \le 50$), we do not need an optimized $O(N)$ approach using prefix sums or parity tracking. We can simply iterate through all possible subarrays using two nested loops.
- For each starting index $i$ and ending index $j$, we maintain a running sum. If `current_sum % 2 == 0`, we calculate the length of the subarray $(j - i + 1)$ and update our global maximum if this length is greater than the previously recorded maximum.

## Complexity Analysis
- **Time Complexity**: $O(N^2)$ per test case, where $N$ is the number of elements in the array. Given $N \le 50$, $N^2 = 2500$, which easily passes within the time limit.
- **Space Complexity**: $O(N)$ to store the input array.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to find the length of the longest subarray with an even sum.
 * Given N is small (up to 50), an O(N^2) approach is perfectly efficient.
 * We can iterate over all possible subarrays [i, j] and check their sum.
 */

void solve() {
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int max_len = 0;

    // Iterate over all possible starting points
    for (int i = 0; i < N; ++i) {
        long long current_sum = 0;
        // Iterate over all possible ending points
        for (int j = i; j < N; ++j) {
            current_sum += A[j];
            // Check if the sum of subarray A[i...j] is even
            if (current_sum % 2 == 0) {
                int current_len = j - i + 1;
                if (current_len > max_len) {
                    max_len = current_len;
                }
            }
        }
    }

    cout << max_len << "\n";
}

int main() {
    // Fast I/O setup
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