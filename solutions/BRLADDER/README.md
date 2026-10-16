# [Bear and Ladder (BRLADDER)](https://www.codechef.com/problems/BRLADDER)

- **Difficulty Rating**: 999
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine if a direct road exists between two given cities $a$ and $b$. The cities are numbered $1, 2, 3, \dots$ and roads are defined by specific rules:
1. A road exists between $(2i+1)$ and $(2i+2)$ for all $i \ge 0$ (e.g., $(1,2), (3,4), (5,6), \dots$).
2. A road exists between consecutive odd numbers $(2i+1)$ and $(2i+3)$ (e.g., $(1,3), (3,5), \dots$).
3. A road exists between consecutive even numbers $(2i+2)$ and $(2i+4)$ (e.g., $(2,4), (4,6), \dots$).

## Intuition & Mathematical Observation
To solve this efficiently without building a graph, we analyze the relationship between $a$ and $b$ based on their absolute difference:

1. **Case: $|a - b| = 1$**
   - These are adjacent integers. Based on the rules, a road exists only if the smaller number is odd. 
   - Example: $(1,2)$ is valid (1 is odd), but $(2,3)$ is invalid (2 is even).
   - Logic: `min(a, b) % 2 != 0`.

2. **Case: $|a - b| = 2$**
   - These are either two odd numbers or two even numbers.
   - The rules state that all consecutive odd numbers are connected and all consecutive even numbers are connected.
   - Logic: `a % 2 == b % 2`.

3. **Case: All other differences**
   - No roads exist for any other distance between $a$ and $b$.
   - Logic: `NO`.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform basic arithmetic and conditional checks. For $Q$ queries, the total time complexity is $O(Q)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the difference.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * 1. If |a - b| == 1: Connected if the smaller one is odd.
 * 2. If |a - b| == 2: Connected if both are odd or both are even (a % 2 == b % 2).
 * 3. Otherwise: No road exists.
 */

void solve() {
    long long a, b;
    cin >> a >> b;

    long long diff = abs(a - b);

    if (diff == 1) {
        // Case 1: Adjacent numbers. 
        // Connected if the smaller one is odd.
        if (min(a, b) % 2 != 0) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    } else if (diff == 2) {
        // Case 2 & 3: Difference of 2.
        // Connected if both are odd or both are even.
        if (a % 2 == b % 2) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    } else {
        // No other roads exist.
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    if (!(cin >> q)) return 0;
    while (q--) {
        solve();
    }
    return 0;
}
```