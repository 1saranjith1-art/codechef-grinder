# [Carrot Collection (CARRCOL)](https://www.codechef.com/problems/CARRCOL)

- **Difficulty Rating**: 914
- **Solved in**: 1 attempt(s)

## Problem Summary
A forest consists of $N$ clearings, each containing a certain number of carrots. A bear patrols a range of clearings $[L, R]$, making them inaccessible to a rabbit. The rabbit can move freely between any adjacent clearings that are not being patrolled. We need to find the maximum number of carrots the rabbit can collect by choosing to stay in either the segment of clearings before the patrol $[1, L-1]$ or the segment after the patrol $[R+1, N]$.

## Intuition & Mathematical Observation
The patrol range $[L, R]$ acts as a barrier that splits the forest into two independent, disconnected segments:
1. **Left Segment**: Clearings from $1$ to $L-1$. This segment exists only if $L > 1$.
2. **Right Segment**: Clearings from $R+1$ to $N$. This segment exists only if $R < N$.

Since the rabbit cannot cross the patrol zone, it must choose to stay entirely within one of these two segments. To maximize the carrots collected, we calculate the sum of carrots in the left segment and the right segment separately and output the maximum of the two. If a segment does not exist (e.g., $L=1$ or $R=N$), we treat its sum as $0$ (or a sufficiently small value) so that it is not chosen over a valid segment.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the array of $N$ clearings to calculate the sums. Given $T$ test cases, the total time complexity is $O(T \times N)$.
- **Space Complexity**: $O(N)$ to store the number of carrots in each clearing.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The bear patrols clearings [L, R].
 * The rabbit cannot visit any clearing in the range [L, R].
 * This effectively splits the forest into two potential disconnected segments:
 * 1. Clearings [1, L-1] (if L > 1)
 * 2. Clearings [R+1, N] (if R < N)
 * 
 * Since the rabbit can move freely within any connected component of non-patrolled clearings,
 * the rabbit can collect all carrots in any one of these components.
 * The problem asks for the maximum number of carrots the rabbit can collect.
 */

void solve() {
    int N, L, R;
    cin >> N >> L >> R;
    vector<long long> A(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    long long sum_left = 0;
    long long sum_right = 0;

    // Calculate sum of carrots in the left segment [1, L-1]
    if (L > 1) {
        for (int i = 1; i < L; ++i) {
            sum_left += A[i];
        }
    } else {
        // If no left segment exists, set to 0
        sum_left = 0;
    }

    // Calculate sum of carrots in the right segment [R+1, N]
    if (R < N) {
        for (int i = R + 1; i <= N; ++i) {
            sum_right += A[i];
        }
    } else {
        // If no right segment exists, set to 0
        sum_right = 0;
    }

    cout << max(sum_left, sum_right) << "\n";
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