# [Bus Rows (BUSROW)](https://www.codechef.com/problems/BUSROW)

- **Difficulty Rating**: 727
- **Solved in**: 1 attempt(s)

## Problem Summary
A bus has $N$ rows, each containing $M$ seats. Seats are numbered sequentially from $1$ to $N \times M$. Given a seat number $X$, we need to determine the minimum number of rows one must walk to reach the row containing seat $X$. One can enter the bus either from the front (starting at row 1) or from the back (starting at row $N$).

## Intuition & Mathematical Observation
1.  **Finding the Row ($R$):** Since each row contains $M$ seats, the seats in row $i$ range from $(i-1) \times M + 1$ to $i \times M$. We can find the row number $R$ for seat $X$ using the formula:
    $$R = \lfloor \frac{X - 1}{M} \rfloor + 1$$
2.  **Calculating Distances:**
    *   **From the front:** To reach row $R$ starting from row 1, we must walk through $R$ rows (row 1, 2, ..., $R$).
    *   **From the back:** To reach row $R$ starting from row $N$, we must walk through rows $N, N-1, \dots, R$. The number of rows in this sequence is $N - R + 1$.
3.  **Optimization:** The goal is to find the minimum of these two distances: $\min(R, N - R + 1)$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the calculation involves only basic arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The bus has N rows, each with M seats.
 * Seat X is in row R.
 * To find R:
 * Since row i contains seats (i-1)*M + 1 to i*M,
 * we can calculate R using integer division:
 * R = (X - 1) / M + 1.
 * 
 * If we enter from the front, we walk through rows 1, 2, ..., R.
 * The number of rows walked is R.
 * 
 * If we enter from the back, we walk through rows N, N-1, ..., R.
 * The number of rows walked is (N - R + 1).
 * 
 * We need the minimum of these two values: min(R, N - R + 1).
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, m, x;
        cin >> n >> m >> x;

        // Calculate the row number R (1-indexed)
        // Using long long to prevent any potential overflow, 
        // though constraints N, M <= 100 fit in int.
        long long r = (x - 1) / m + 1;

        // Distance from front: r
        // Distance from back: n - r + 1
        long long dist_front = r;
        long long dist_back = n - r + 1;

        // Output the minimum of the two distances
        cout << min(dist_front, dist_back) << "\n";
    }

    return 0;
}
```