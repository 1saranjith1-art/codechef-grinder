# [Careless Chef (LOSTSEQ)](https://www.codechef.com/problems/LOSTSEQ)

- **Difficulty Rating**: 1345
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given a sequence $B$ of $2N$ integers. We need to determine if it is possible to partition these $2N$ integers into $N$ pairs $(x_i, y_i)$ such that for each pair, there exists an integer $A_i$ and a non-negative integer $k$ where $x_i = A_i - k$ and $y_i = A_i + k$.

## Intuition & Mathematical Observation
By analyzing the equations $x_i = A_i - k$ and $y_i = A_i + k$, we can derive a key property:
1. Adding the two equations: $x_i + y_i = (A_i - k) + (A_i + k) = 2A_i$.
2. This implies that the sum of each pair $(x_i + y_i)$ must be an **even number**.

For the sum of two integers to be even, the two numbers must have the same parity:
- **Even + Even = Even**
- **Odd + Odd = Even**
- (Odd + Even = Odd, which is not allowed)

Therefore, to partition $2N$ numbers into $N$ pairs where each pair sums to an even number, we must be able to pair all odd numbers with other odd numbers and all even numbers with other even numbers. This is only possible if the **total count of odd numbers in the sequence $B$ is even**. If the count of odd numbers is odd, there will inevitably be one odd number left over that cannot be paired to form an even sum.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the $2N$ elements exactly once.
- **Space Complexity**: $O(1)$, as we only store the count of odd numbers regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * For each element A_i, we generate two numbers: (A_i - k) and (A_i + k).
 * The sum of these two numbers is 2 * A_i, which is always even.
 * 
 * A sum (x + y) is even if and only if both x and y are even or both are odd.
 * This implies that the total count of odd numbers in the sequence B must be even
 * to allow for valid pairing.
 */

void solve() {
    int N;
    cin >> N;
    int odd_count = 0;
    for (int i = 0; i < 2 * N; ++i) {
        int b;
        cin >> b;
        // Check if the number is odd. 
        // Using (b % 2 != 0) handles both positive and negative odd integers.
        if (b % 2 != 0) {
            odd_count++;
        }
    }

    // If the count of odd numbers is even, we can pair them all up.
    if (odd_count % 2 == 0) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O for performance
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