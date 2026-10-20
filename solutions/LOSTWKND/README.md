# [Lost Weekends (LOSTWKND)](https://www.codechef.com/problems/LOSTWKND)

- **Difficulty Rating**: 1063
- **Solved in**: 2 attempt(s)

## Problem Summary
Chef has a work schedule for 5 days of the week (Monday to Friday). For each day $i$, he spends $A_i$ hours working on a specific task. Each task requires $P$ hours of effort per unit of work. We need to determine if the total time required to complete all tasks exceeds the total available working hours in a standard 5-day work week (120 hours). If the total time exceeds 120 hours, Chef must work on the weekends.

## Intuition & Mathematical Observation
1. **Calculate Total Workload**: The total number of units of work across 5 days is the sum of the hours spent each day: $S = A_1 + A_2 + A_3 + A_4 + A_5$.
2. **Convert to Time**: Since each unit takes $P$ hours, the total time required is $T = S \times P$.
3. **Compare with Capacity**: A standard work week consists of 5 days, each with 24 hours, totaling $5 \times 24 = 120$ hours.
4. **Decision Logic**:
   - If $T > 120$, Chef cannot finish within the standard week, so output `Yes`.
   - Otherwise, output `No`.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case. We perform a constant number of additions and one multiplication regardless of the input values.
- **Space Complexity**: $O(1)$. We only use a fixed-size array and a few integer variables to store the input.

## Solution Code

```cpp
#include <iostream>
#include <vector>

using namespace std;

/**
 * Problem Analysis:
 * Total work in home-hours = (A1 + A2 + A3 + A4 + A5) * P
 * Total available hours in a week = 5 days * 24 hours/day = 120 hours.
 * If total work > 120, Chef must work on weekends.
 */

void solve() {
    int A[5];
    int P;
    int sum_A = 0;
    for (int i = 0; i < 5; ++i) {
        cin >> A[i];
        sum_A += A[i];
    }
    cin >> P;

    // Check if the total required hours exceed the 120-hour limit
    if (sum_A * P > 120) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

int main() {
    // Optimize I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}
```