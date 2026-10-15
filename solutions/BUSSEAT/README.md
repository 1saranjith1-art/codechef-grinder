# [Bus Seating (BUSSEAT)](https://www.codechef.com/problems/BUSSEAT)

- **Difficulty Rating**: 640
- **Solved in**: 1 attempt(s)

## Problem Summary
In a bus with $N$ rows, each row has exactly 2 seats. Passengers board the bus one by one. They follow a specific seating preference:
1. They prefer to sit in an empty row (occupying one seat).
2. If no empty rows are available, they will sit in a row that already has one person.

Given $N$ rows and $K$ passengers, calculate the total number of people who end up sitting next to someone.

## Intuition & Mathematical Observation
The seating process can be broken down into two phases:

1. **Phase 1 (Individual Rows):** The first $N$ passengers will each take one seat in an empty row. At this point, every row has exactly one person, and no one is sitting next to anyone.
   - If $K \le N$, every passenger has their own row. The number of people sitting next to someone is **0**.

2. **Phase 2 (Filling Rows):** If $K > N$, the remaining $(K - N)$ passengers must sit in rows that are already occupied. 
   - Each of these $(K - N)$ passengers will sit next to the person who arrived earlier in that row.
   - Consequently, the $(K - N)$ people who were already sitting in those rows now have a neighbor.
   - Therefore, for every passenger who fills a second seat, **two** people end up sitting next to someone (the new arrival and the person already there).
   - The total count is $2 \times (K - N)$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves simple arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * There are N rows, each with 2 seats. Total seats = 2N.
 * Strategy:
 * 1. People prefer to sit in an empty row (1 person per row).
 * 2. If no empty rows are available, they sit next to somebody.
 * 
 * Logic:
 * - If K <= N, everyone gets their own row, so 0 people sit next to someone.
 * - If K > N, the first N people occupy one seat in each row.
 * - The remaining (K - N) people fill the second seat in (K - N) rows.
 * - In each of these rows, both the original person and the new arrival are now sitting next to someone.
 * - Total people = 2 * (K - N).
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, k;
        cin >> n >> k;

        if (k <= n) {
            // Everyone gets their own row, no one sits next to anyone.
            cout << 0 << "\n";
        } else {
            // Remaining (K - N) people fill the second seat in (K - N) rows.
            // Each of these rows now contains 2 people.
            cout << 2 * (k - n) << "\n";
        }
    }

    return 0;
}
```