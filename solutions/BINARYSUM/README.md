# [Binary Sum (BINARYSUM)](https://www.codechef.com/problems/BINARYSUM)

- **Difficulty Rating**: 1015
- **Solved in**: 2 attempt(s)

## Problem Summary
Given two integers $N$ and $K$, determine if it is possible to construct a binary string of length $N$ such that no two adjacent characters are equal (i.e., the string must be alternating) and the total number of ones in the string is exactly $K$.

## Intuition & Mathematical Observation
For a binary string of length $N$ to have no two adjacent digits equal, it must follow one of two alternating patterns:
1. **Pattern 1**: Starts with '0' ($0, 1, 0, 1, \dots$)
2. **Pattern 2**: Starts with '1' ($1, 0, 1, 0, \dots$)

Let's analyze the number of ones ($K$) in these patterns based on $N$:

*   **If $N$ is even:**
    *   Pattern 1 ($0101...01$): Contains exactly $N/2$ ones.
    *   Pattern 2 ($1010...10$): Contains exactly $N/2$ ones.
    *   **Conclusion**: Only $K = N/2$ is possible.

*   **If $N$ is odd:**
    *   Pattern 1 ($0101...0$): Contains $N/2$ ones (integer division).
    *   Pattern 2 ($1010...1$): Contains $(N+1)/2$ ones.
    *   **Conclusion**: Both $K = N/2$ and $K = (N+1)/2$ are possible.

By checking these conditions, we can determine if a valid string exists for any given $N$ and $K$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform basic arithmetic comparisons. Total time complexity is $O(T)$, where $T$ is the number of test cases.
- **Space Complexity**: $O(1)$, as we use a constant amount of extra space.

## Solution Code

```cpp
#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * A binary string of length N with no two adjacent digits equal must be alternating.
 * Pattern 1: 010101...
 * Pattern 2: 101010...
 * 
 * If N is even:
 * Pattern 1 (01...01): N/2 ones.
 * Pattern 2 (10...10): N/2 ones.
 * Possible K: N/2.
 * 
 * If N is odd:
 * Pattern 1 (01...0): N/2 ones.
 * Pattern 2 (10...1): (N+1)/2 ones.
 * Possible K: N/2 or (N+1)/2.
 */

void solve() {
    int N, K;
    if (!(cin >> N >> K)) return;

    if (N % 2 == 0) {
        if (K == N / 2) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    } else {
        // For odd N, K can be floor(N/2) or ceil(N/2)
        if (K == N / 2 || K == (N + 1) / 2) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}

int main() {
    // Optimize I/O operations
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