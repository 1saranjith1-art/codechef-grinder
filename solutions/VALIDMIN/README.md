# [Valid Minimum (VALIDMIN)](https://www.codechef.com/problems/VALIDMIN)

- **Difficulty Rating**: 1132
- **Solved in**: 1 attempt(s)

## Problem Summary
Given three integers $x_{AB} = \min(A, B)$, $x_{BC} = \min(B, C)$, and $x_{AC} = \min(A, C)$, determine if there exist three integers $A, B, C$ that satisfy these conditions simultaneously.

## Intuition & Mathematical Observation
To determine if a valid triplet $(A, B, C)$ exists, let's assume without loss of generality that $A \le B \le C$. 

Given this ordering:
1. $x_{AB} = \min(A, B) = A$
2. $x_{BC} = \min(B, C) = B$
3. $x_{AC} = \min(A, C) = A$

The set of values we are given is $\{A, B, A\}$. If we sort these three values such that $s_1 \le s_2 \le s_3$, we observe that $s_1 = A$ and $s_2 = A$. Therefore, the condition for a valid triplet is that the two smallest values among the given inputs must be equal.

**General Logic:**
1. Read the three input values.
2. Sort them in non-decreasing order.
3. Check if the first two elements are equal. If they are, output "YES"; otherwise, output "NO".

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case. Sorting three elements takes a constant number of operations.
- **Space Complexity**: $O(1)$ as we only store three integers regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let x = min(A, B), y = min(B, C), z = min(C, A).
 * Without loss of generality, assume A <= B <= C.
 * Then:
 * min(A, B) = A = x
 * min(B, C) = B = y
 * min(C, A) = A = z
 * 
 * This implies x = z.
 * If we sort the three given values as s1 <= s2 <= s3:
 * The condition for a valid tuple is that the two smallest values must be equal.
 */

void solve() {
    int arr[3];
    cin >> arr[0] >> arr[1] >> arr[2];
    sort(arr, arr + 3);
    
    // After sorting, the two smallest values are arr[0] and arr[1].
    // They must be equal for a valid tuple (A, B, C) to exist.
    if (arr[0] == arr[1]) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
```