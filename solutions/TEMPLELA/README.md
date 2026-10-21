# [Temple Land (TEMPLELA)](https://www.codechef.com/problems/TEMPLELA)

- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary
The task is to determine if a given sequence of temple strip heights represents a valid "Temple Land" structure. A valid structure must satisfy the following criteria:
1. The total number of strips ($N$) must be odd.
2. The first and last strips must have a height of 1.
3. The heights must increase by 1 for each subsequent strip until the middle element.
4. After the middle element, the heights must decrease by 1 for each subsequent strip until the end.

## Intuition & Mathematical Observation
To validate the sequence, we can break down the requirements into logical checks:
- **Parity Check**: If $N$ is even, it is impossible to have a single peak element with an equal number of elements on both sides.
- **Boundary Check**: The sequence must start and end with 1.
- **Pattern Check**: 
    - For the first half (including the middle), the height at index $i$ must be $i + 1$.
    - For the second half, the height at index $i$ must follow the pattern $N - i$.
    
By iterating through the array once, we can verify these conditions. If any element fails to match the expected value based on its index, the sequence is invalid.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of strips. We perform a single pass over the array to validate the heights.
- **Space Complexity**: $O(N)$ to store the input array of heights.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * 1. The length Ni must be odd for a unique center to exist.
 * 2. The first element H[0] must be 1.
 * 3. The last element H[Ni-1] must be 1.
 * 4. The sequence must increase by 1 until the middle element (index Ni/2).
 * 5. The sequence must decrease by 1 from the middle element to the end.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }

    // Condition 1: Length must be odd
    if (N % 2 == 0) {
        cout << "no" << "\n";
        return;
    }

    // Condition 2: Start and end must be 1
    if (H[0] != 1 || H[N - 1] != 1) {
        cout << "no" << "\n";
        return;
    }

    int mid = N / 2;

    // Condition 3 & 4: Check increasing and decreasing pattern
    // Left side: H[i] should be i + 1
    for (int i = 0; i <= mid; ++i) {
        if (H[i] != i + 1) {
            cout << "no" << "\n";
            return;
        }
    }

    // Right side: H[i] should be N - i
    for (int i = mid + 1; i < N; ++i) {
        if (H[i] != N - i) {
            cout << "no" << "\n";
            return;
        }
    }

    cout << "yes" << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int S;
    if (!(cin >> S)) return 0;
    while (S--) {
        solve();
    }
    return 0;
}
```