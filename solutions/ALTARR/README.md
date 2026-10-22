# [Alternating Array (ALTARR)](https://www.codechef.com/problems/ALTARR)

- **Difficulty Rating**: 787
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array of $N$ integers, we want to make the array "alternating." An array is considered alternating if the parity (even or odd) of any two adjacent elements is different. We need to find the minimum number of elements that must be changed to satisfy this condition.

## Intuition & Mathematical Observation
An alternating array must follow one of two possible parity patterns:
1. **Pattern 1**: Starts with an Odd number (Odd, Even, Odd, Even, ...).
2. **Pattern 2**: Starts with an Even number (Even, Odd, Even, Odd, ...).

For any index $i$ (0-indexed):
- In **Pattern 1**, the expected parity is `1` (odd) if $i$ is even, and `0` (even) if $i$ is odd.
- In **Pattern 2**, the expected parity is `0` (even) if $i$ is even, and `1` (odd) if $i$ is odd.

By iterating through the array once, we can calculate the number of mismatches (changes required) for both patterns. The final answer is simply the minimum of these two counts, as any alternating array must conform to one of these two configurations.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the length of the array. We perform a single pass through the array to compare parities.
- **Space Complexity**: $O(N)$ to store the input array. This can be optimized to $O(1)$ if we process the input elements on the fly without storing them.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * An array is alternating if the parity of adjacent elements is different.
 * This means for any index i, parity(A[i]) != parity(A[i+1]).
 * There are only two possible patterns for an alternating array of length N:
 * Pattern 1: Starts with Odd (Odd, Even, Odd, Even, ...)
 * Pattern 2: Starts with Even (Even, Odd, Even, Odd, ...)
 * 
 * We can calculate the number of changes required to match Pattern 1 and Pattern 2,
 * then take the minimum of the two.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // count1: changes needed if we force the pattern starting with Odd (1)
    // count2: changes needed if we force the pattern starting with Even (0)
    int count1 = 0;
    int count2 = 0;

    for (int i = 0; i < N; ++i) {
        int parity = A[i] % 2;
        
        // Pattern 1: Expected parity at index i is (i % 2 == 0 ? 1 : 0)
        int expected1 = (i % 2 == 0) ? 1 : 0;
        if (parity != expected1) {
            count1++;
        }

        // Pattern 2: Expected parity at index i is (i % 2 == 0 ? 0 : 1)
        int expected2 = (i % 2 == 0) ? 0 : 1;
        if (parity != expected2) {
            count2++;
        }
    }

    cout << min(count1, count2) << "\n";
}

int main() {
    // Fast I/O setup
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