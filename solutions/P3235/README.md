# [Balanced Positions in a Permutation (P3235)](https://www.codechef.com/problems/P3235)

- **Difficulty Rating**: 930
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a permutation $P$ of length $N$, we define two values for each index $i$ (0-indexed):
*   $L_i$: The count of elements $P[j]$ such that $j < i$ and $P[j] < P[i]$.
*   $R_i$: The count of elements $P[j]$ such that $j > i$ and $P[j] > P[i]$.

The goal is to find the total number of indices $i$ where $L_i = R_i$.

## Intuition & Mathematical Observation
The problem asks us to evaluate a condition for every position in the array. Since the constraints are small ($N \le 100$), we do not need advanced data structures like Fenwick Trees or Segment Trees. 

For each index $i$, we can simply iterate through the entire array to count the elements that satisfy the conditions for $L_i$ and $R_i$:
1.  **For $L_i$**: Iterate from $0$ to $i-1$ and increment a counter whenever $P[j] < P[i]$.
2.  **For $R_i$**: Iterate from $i+1$ to $N-1$ and increment a counter whenever $P[j] > P[i]$.

After calculating both values, we compare them and increment our total answer if they are equal. Given $T \le 10^4$ and $N \le 100$, the total number of operations is roughly $10^8$, which comfortably fits within the 1-second time limit.

## Complexity Analysis
- **Time Complexity**: $O(T \times N^2)$, where $T$ is the number of test cases and $N$ is the length of the permutation. With $N=100$, $N^2 = 10,000$, and $10^4 \times 10^4 = 10^8$ operations.
- **Space Complexity**: $O(N)$ to store the permutation array.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Given a permutation P of length N.
 * L_i = count of elements P[j] such that j < i and P[j] < P[i].
 * R_i = count of elements P[j] such that j > i and P[j] > P[i].
 * We need to count indices i where L_i == R_i.
 * 
 * Constraints: N <= 100.
 * An O(N^2) approach per test case is perfectly acceptable.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> P(N);
    for (int i = 0; i < N; ++i) {
        cin >> P[i];
    }

    int count = 0;
    for (int i = 0; i < N; ++i) {
        int L_i = 0;
        int R_i = 0;

        // Calculate L_i: elements to the left smaller than P[i]
        for (int j = 0; j < i; ++j) {
            if (P[j] < P[i]) {
                L_i++;
            }
        }

        // Calculate R_i: elements to the right greater than P[i]
        for (int j = i + 1; j < N; ++j) {
            if (P[j] > P[i]) {
                R_i++;
            }
        }

        if (L_i == R_i) {
            count++;
        }
    }
    cout << count << "\n";
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