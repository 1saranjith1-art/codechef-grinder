# [Selling Donuts (DONUTSELL)](https://www.codechef.com/problems/DONUTSELL)

- **Difficulty Rating**: 754
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given $N$ types of donuts, each with an initial stock count. A sequence of $M$ customers arrives, each requesting a specific type of donut. If the requested donut is in stock (count > 0), we decrement its count and satisfy the customer. If the stock is 0, the customer remains "sad." The goal is to calculate the total number of sad customers after all $M$ requests are processed.

## Intuition & Mathematical Observation
The problem is a direct simulation task. Since the constraints are small ($N, M \le 100$), we do not need complex data structures or optimization algorithms. 

1. **Storage**: We can store the donut counts in an array or vector of size $N+1$ to accommodate 1-based indexing.
2. **Simulation**: For each customer request $B_i$:
   - Check if `A[B_i] > 0`.
   - If true, decrement `A[B_i]` (the donut is sold).
   - If false, increment a counter for `sad_customers`.
3. **Efficiency**: Since we process each customer exactly once and perform constant-time lookups and updates, the simulation is highly efficient.

## Complexity Analysis
- **Time Complexity**: $O(T \times M)$, where $T$ is the number of test cases and $M$ is the number of customers. Given $T, M \le 100$, the total operations are roughly $10^4$, which easily fits within the 1-second time limit.
- **Space Complexity**: $O(N)$, where $N$ is the number of donut types, as we need to store the initial counts of each donut type.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given N types of donuts with initial counts A_1, A_2, ..., A_N.
 * M customers arrive sequentially, each wanting a specific type B_i.
 * If the count of type B_i is > 0, we decrement the count and the customer is satisfied.
 * If the count is 0, the customer is sad.
 * We need to count the total number of sad customers.
 */

void solve() {
    int N, M;
    if (!(cin >> N >> M)) return;

    // Use a vector to store donut counts. 
    // Since types are 1-indexed, we use size N+1.
    vector<int> A(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    int sad_customers = 0;
    for (int i = 0; i < M; ++i) {
        int type;
        cin >> type;
        
        // Check if the requested donut type is available
        if (A[type] > 0) {
            A[type]--;
        } else {
            // No donuts left of this type, customer is sad
            sad_customers++;
        }
    }

    cout << sad_customers << "\n";
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