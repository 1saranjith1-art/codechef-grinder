# [Pseudo Sorted Array (PSEUDOSORT)](https://www.codechef.com/problems/PSEUDOSORT)

- **Difficulty Rating**: 1067
- **Solved in**: 2 attempt(s)

## Problem Summary
The task is to determine if an array can be sorted in non-decreasing order by performing **at most one** swap of adjacent elements. An array that is already sorted is considered "pseudo-sorted."

## Intuition & Mathematical Observation
1. **Sorted Check**: First, we check if the array is already sorted. If it is, the condition is satisfied immediately.
2. **Identifying the Inversion**: If the array is not sorted, there must exist at least one index $i$ such that $A[i] > A[i+1]$. 
3. **The Swap Strategy**: Since we are allowed only one swap of adjacent elements, if such an inversion exists, the only possible swap that could fix the array is swapping the first pair $(A[i], A[i+1])$ that violates the non-decreasing order.
4. **Verification**: After performing this single swap, we perform a final check to see if the entire array is sorted. If it is, the answer is "YES"; otherwise, it is "NO".

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the size of the array. We iterate through the array once to find the inversion and once more to verify the sorted property after the swap.
- **Space Complexity**: $O(N)$ to store the array elements.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem Analysis:
 * An array is pseudo-sorted if it is already sorted or can be sorted by one swap.
 * 1. Find the first index i such that A[i] > A[i+1].
 * 2. If no such index exists, the array is already sorted -> YES.
 * 3. If such an index exists, swap A[i] and A[i+1].
 * 4. Check if the array is now sorted. If yes -> YES, else -> NO.
 */

bool is_sorted_array(const vector<long long>& a) {
    for (size_t i = 0; i + 1 < a.size(); ++i) {
        if (a[i] > a[i + 1]) return false;
    }
    return true;
}

void solve() {
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Find the first inversion
    int first_inversion = -1;
    for (int i = 0; i < N - 1; ++i) {
        if (A[i] > A[i + 1]) {
            first_inversion = i;
            break;
        }
    }

    // If already sorted
    if (first_inversion == -1) {
        cout << "YES" << endl;
        return;
    }

    // Perform the swap at the first inversion
    swap(A[first_inversion], A[first_inversion + 1]);

    // Check if sorted after swap
    if (is_sorted_array(A)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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