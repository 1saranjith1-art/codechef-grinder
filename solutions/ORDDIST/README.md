# [Ordered Distances (ORDDIST)](https://www.codechef.com/problems/ORDDIST)

- **Difficulty Rating**: 1112
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an initial sequence $X$ of $N$ integers and a target sequence $Y$, we need to determine if there exists a "pivot" element $X[i]$ (where $1 \le i \le N$) such that if we create a list of pairs $L = (|X[j] - X[i]|, X[j])$ for all $j \in [0, N-1]$ and sort this list primarily by distance and secondarily by the value itself, the resulting sequence of values matches $Y$. If such an index exists, we output the 1-based index $i+1$; otherwise, we output -1.

## Intuition & Mathematical Observation
The problem constraints are small ($N \le 100$), which suggests that a brute-force approach is feasible. 

1. **Pivot Selection**: Since there are only $N$ possible choices for the pivot index, we can iterate through every index $i$ from $0$ to $N-1$.
2. **Transformation**: For a fixed pivot $P = X[i]$, we calculate the distance of every element $X[j]$ from $P$ as $d_j = |X[j] - P|$.
3. **Sorting**: We store these as pairs $(d_j, X[j])$ and sort them. The problem specifies the sorting criteria:
   - Primary: Ascending order of distance $|X[j] - P|$.
   - Secondary: Ascending order of the value $X[j]$ (to handle ties in distance).
4. **Verification**: After sorting, we extract the sequence of values from the sorted pairs and compare it element-wise with the target sequence $Y$. If they match, we have found our pivot.

## Complexity Analysis
- **Time Complexity**: $O(T \cdot N \cdot N \log N)$, where $T$ is the number of test cases. For each test case, we iterate $N$ times, and inside the loop, we perform a sort operation taking $O(N \log N)$. Given $N=100$, $N^2 \log N \approx 66,000$ operations per test case, which easily fits within the 1-second time limit.
- **Space Complexity**: $O(N)$ to store the input arrays $X, Y$ and the temporary list $L$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We iterate through every possible pivot index i from 0 to N-1.
 * For each pivot, we construct the list L of pairs (|X[j] - P|, X[j]),
 * sort it according to the rules, and compare with Y.
 */

struct Point {
    int dist;
    int val;
};

// Custom comparator for sorting based on distance, then value
bool comparePoints(const Point& a, const Point& b) {
    if (a.dist != b.dist) {
        return a.dist < b.dist;
    }
    return a.val < b.val;
}

void solve() {
    int N;
    cin >> N;
    vector<int> X(N);
    for (int i = 0; i < N; ++i) cin >> X[i];
    vector<int> Y(N);
    for (int i = 0; i < N; ++i) cin >> Y[i];

    // Try every index as the pivot
    for (int i = 0; i < N; ++i) {
        int P = X[i];
        vector<Point> L(N);
        for (int j = 0; j < N; ++j) {
            L[j] = {abs(X[j] - P), X[j]};
        }

        sort(L.begin(), L.end(), comparePoints);

        // Check if the sorted sequence matches Y
        bool match = true;
        for (int k = 0; k < N; ++k) {
            if (L[k].val != Y[k]) {
                match = false;
                break;
            }
        }

        if (match) {
            cout << (i + 1) << "\n";
            return;
        }
    }

    // No valid pivot found
    cout << -1 << "\n";
}

int main() {
    // Optimize I/O operations
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