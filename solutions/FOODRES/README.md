# [Food Resources (FOODRES)](https://www.codechef.com/problems/FOODRES)

- **Difficulty Rating**: 1235
- **Solved in**: 2 attempt(s)

## Problem Summary
Given $N$ food resources with quantities $A_1, A_2, \dots, A_N$ and a requirement to feed $M$ people, we need to find the maximum possible portion size $D$ such that each person receives a portion of size $D$. Specifically, if we choose a portion size $D$, the number of people we can feed is $\sum_{i=1}^{N} \lfloor \frac{A_i}{D} \rfloor$. We must find the largest integer $D$ such that this sum is at least $M$.

## Intuition & Mathematical Observation
1. **Monotonicity**: Let $f(D) = \sum_{i=1}^{N} \lfloor \frac{A_i}{D} \rfloor$. As the portion size $D$ increases, the number of portions we can extract from each resource $A_i$ either stays the same or decreases. Therefore, $f(D)$ is a monotonically non-increasing function.
2. **Binary Search**: Because of this monotonicity, we can binary search for the optimal $D$.
   - The lower bound for $D$ is $1$.
   - The upper bound for $D$ is the maximum value in array $A$ (since $D$ cannot exceed the largest resource).
3. **Check Function**: For a chosen $mid$, we calculate the total number of portions. If the total is $\ge M$, then $mid$ is a potential answer, and we try to find a larger $D$ by moving the lower bound. Otherwise, we decrease the upper bound.

## Complexity Analysis
- **Time Complexity**: $O(N \log(\max(A)))$. We perform a binary search over the range $[1, \max(A)]$, and in each step, we iterate through the array of size $N$ to calculate the total portions.
- **Space Complexity**: $O(N)$ to store the resource quantities.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem Analysis:
 * We need to find the maximum D such that sum(floor(A_i / D)) >= M.
 * The function f(D) = sum(floor(A_i / D)) is monotonically non-increasing.
 * Binary search is the correct approach.
 */

bool check(long long D, int N, long long M, const vector<int>& A) {
    if (D == 0) return true;
    long long total_people = 0;
    for (int i = 0; i < N; ++i) {
        total_people += (A[i] / D);
        // Optimization: early exit if we already met the requirement
        if (total_people >= M) return true;
    }
    return total_people >= M;
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    long long M;
    
    if (!(cin >> N >> M)) return 0;
    
    vector<int> A(N);
    int max_a = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        if (A[i] > max_a) max_a = A[i];
    }

    // Binary search for D in range [1, max_a]
    long long low = 1, high = max_a;
    long long ans = 0;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (mid == 0) {
            low = mid + 1;
            continue;
        }
        if (check(mid, N, M, A)) {
            ans = mid;
            low = mid + 1; // Try to find a larger D
        } else {
            high = mid - 1; // D is too large
        }
    }
    
    cout << ans << endl;

    return 0;
}
```