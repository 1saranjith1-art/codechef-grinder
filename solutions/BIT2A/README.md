# [A - Books (BIT2A)](https://www.codechef.com/problems/BIT2A)

- **Difficulty Rating**: 1175
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a sorted array $A$ of $N$ integers, for each element $A[i]$, determine how many elements in the array are strictly greater than $A[i]$.

## Intuition & Mathematical Observation
Since the input array $A$ is already sorted in non-decreasing order, the elements strictly greater than $A[i]$ will always form a suffix of the array starting immediately after the last occurrence of $A[i]$.

1. **Binary Search Approach**: For any element $A[i]$, we can use the `std::upper_bound` function. This function returns an iterator to the first element that is strictly greater than $A[i]$.
2. **Calculating the Count**: Once we have the iterator to the first element strictly greater than $A[i]$, the number of elements from that position to the end of the array is simply the total number of elements ($N$) minus the index of that element.
3. **Efficiency**: Because the array is sorted, `upper_bound` performs a binary search in $O(\log N)$ time. Doing this for all $N$ elements results in an overall complexity of $O(N \log N)$, which is highly efficient for the given constraints.

## Complexity Analysis
- **Time Complexity**: $O(T \times N \log N)$, where $T$ is the number of test cases and $N$ is the size of the array. Given $N \le 100$ and $T \le 100$, this performs well within the time limit.
- **Space Complexity**: $O(N)$ to store the array elements.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given a sorted list A of size N.
 * For each A[i], we need to find the count of elements strictly greater than A[i].
 * Since the array is sorted, all elements strictly greater than A[i] will appear
 * after the last occurrence of A[i] in the array.
 * 
 * Approach:
 * 1. For each element A[i], we can use the upper_bound function to find the 
 *    first element that is strictly greater than A[i].
 * 2. The number of elements strictly greater than A[i] is then (N - index of that element).
 * 3. Time Complexity: O(N log N) per test case, which is well within the 0.5s limit 
 *    for N=100 and T=100.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    for (int i = 0; i < N; ++i) {
        // upper_bound returns an iterator to the first element strictly greater than A[i]
        auto it = upper_bound(A.begin(), A.end(), A[i]);
        
        // The number of elements strictly greater is the distance from the iterator to the end
        long long count = distance(it, A.end());
        
        cout << count << (i == N - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}
```