# [Election (ELECTION1)](https://www.codechef.com/problems/ELECTION1)

- **Difficulty Rating**: 241
- **Solved in**: 2 attempt(s)

## Problem Summary
In an election with $N$ total seats, a political party needs a strict majority to form the government. A strict majority is defined as having more than half of the total seats. Given that the party currently holds $K$ seats, calculate the minimum number of additional seats they need to secure a majority.

## Intuition & Mathematical Observation
To form a government, the party needs more than $N/2$ seats. 
- Mathematically, the threshold $T$ is defined as $\lfloor N/2 \rfloor + 1$.
- If the current number of seats $K$ is already greater than or equal to $T$, the party has already achieved a majority, so the answer is $0$.
- If $K < T$, the party needs exactly $T - K$ more seats to reach the threshold.

**Example:**
If $N = 10$, the threshold is $\lfloor 10/2 \rfloor + 1 = 6$.
- If $K = 4$, the party needs $6 - 4 = 2$ more seats.
- If $K = 7$, the party already has a majority, so they need $0$ more seats.

## Complexity Analysis
- **Time Complexity**: $O(1)$, as the solution involves a simple arithmetic calculation regardless of the input size.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the input and the result.

## Solution Code

```cpp
#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * A party needs a strict majority to form the government.
 * The threshold for a strict majority is floor(N / 2) + 1.
 * Let T = floor(N / 2) + 1.
 * If K >= T, the party already has a majority, so 0 additional seats are needed.
 * If K < T, the party needs (T - K) additional seats.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    if (cin >> N >> K) {
        // Calculate the threshold for a strict majority
        int threshold = (N / 2) + 1;

        if (K >= threshold) {
            cout << 0 << endl;
        } else {
            cout << (threshold - K) << endl;
        }
    }

    return 0;
}
```