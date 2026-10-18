# [Make Subarray (MAKESUB)](https://www.codechef.com/problems/MAKESUB)

- **Difficulty Rating**: 940
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a binary string $S$ of length $N$ consisting of '0's and '1's, we want all the '1's in the string to form a single contiguous subarray. We are allowed to change any '0' to a '1'. The goal is to find the minimum number of operations (flips) required to satisfy the condition.

## Intuition & Mathematical Observation
To make all '1's contiguous, we must ensure that there are no '0's trapped between the leftmost '1' and the rightmost '1'. 

1. **Identify the boundaries**: Find the index of the first occurrence of '1' (`first`) and the last occurrence of '1' (`last`).
2. **Edge Case**: If there are no '1's in the string, the condition is already satisfied (an empty set of '1's is technically contiguous), so the cost is $0$.
3. **The Logic**: If there are '1's, any '0' located at an index $i$ such that `first < i < last` breaks the contiguity. To fix this, we must flip every '0' in the range `[first, last]` to a '1'. 
4. **Calculation**: The minimum number of flips is simply the count of '0's present in the substring $S[first \dots last]$.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the length of the string. We perform a single pass (or two) over the string to find the boundaries and count the zeros.
- **Space Complexity**: $O(N)$ to store the input string, or $O(1)$ auxiliary space if we process the string character by character.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We want all black cells (1s) to form a contiguous subarray.
 * We can only change white (0) to black (1).
 * 
 * Let the first occurrence of '1' be at index 'first' and the last occurrence 
 * of '1' be at index 'last'.
 * If there are no '1's, the cost is 0.
 * If there are '1's, all cells between 'first' and 'last' must be '1'.
 * Any '0' in the range [first, last] must be flipped to '1'.
 * 
 * The number of flips required is simply the count of '0's between the 
 * first '1' and the last '1'.
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    int first = -1;
    int last = -1;

    // Find the first and last index of '1'
    for (int i = 0; i < N; ++i) {
        if (S[i] == '1') {
            if (first == -1) {
                first = i;
            }
            last = i;
        }
    }

    // If no 1s are present, condition is already satisfied.
    if (first == -1) {
        cout << 0 << "\n";
        return;
    }

    // Count zeros between first and last index
    int flips = 0;
    for (int i = first; i <= last; ++i) {
        if (S[i] == '0') {
            flips++;
        }
    }

    cout << flips << "\n";
}

int main() {
    // Fast I/O
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