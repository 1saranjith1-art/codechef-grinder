# [Akash and Grid (CHEFGRD)](https://www.codechef.com/problems/CHEFGRD)

- **Difficulty Rating**: 1311
- **Solved in**: 2 attempt(s)

## Problem Summary
Given an $N \times N$ grid, we define the center of the grid as $(cx, cy) = (\frac{N+1}{2}, \frac{N+1}{2})$. We start at a given position $(xs, ys)$. We are allowed to move to any adjacent cell (up, down, left, right) or any diagonal cell. The goal is to determine the minimum number of moves required to reach the center $(cx, cy)$.

## Intuition & Mathematical Observation
The key to this problem lies in the parity of the coordinates. 

1. **The Center**: Since $N$ is always odd (as per problem constraints), the center $(cx, cy)$ is always at an integer coordinate where $cx = cy$.
2. **Parity Analysis**:
   - A diagonal move changes both $x$ and $y$ by 1. Consequently, the difference $(x - y)$ remains constant in terms of parity (even or odd).
   - A horizontal or vertical move changes either $x$ or $y$ by 1. This flips the parity of the difference $(x - y)$.
3. **The Logic**:
   - Let $dx = |xs - cx|$ and $dy = |ys - cy|$.
   - If $dx$ and $dy$ have the same parity (both even or both odd), then $(xs - ys)$ has the same parity as $(cx - cy)$. Since $cx = cy$, their difference is $0$ (even). Thus, if $dx \equiv dy \pmod 2$, the target is reachable with $0$ extra moves (using only diagonal steps).
   - If $dx$ and $dy$ have different parities, we are forced to make at least one horizontal or vertical move to align the parities, resulting in a minimum of $1$ move.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves simple arithmetic operations. Total time complexity is $O(T)$, where $T$ is the number of test cases.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and calculated coordinates.

## Solution Code

```cpp
#include <iostream>
#include <cmath>

using namespace std;

/**
 * Problem Analysis:
 * Center is (cx, cy) = ((N+1)/2, (N+1)/2).
 * Diagonal moves: (x, y) -> (x±1, y±1). These moves change both x and y by 1,
 * so (x - y) remains constant modulo 2.
 * Horizontal/Vertical moves: (x, y) -> (x±1, y) or (x, y±1). These change
 * the parity of (x - y).
 * 
 * To reach (cx, cy) from (xs, ys):
 * If (xs - cx) and (ys - cy) have the same parity, then (xs - ys) has the same 
 * parity as (cx - cy). Since cx = cy, (cx - cy) = 0 (even).
 * Therefore, if (xs - ys) is even, cost is 0.
 * If (xs - ys) is odd, we need 1 move to change the parity.
 */

void solve() {
    long long N, xs, ys;
    if (!(cin >> N >> xs >> ys)) return;
    
    long long cx = (N + 1) / 2;
    long long cy = (N + 1) / 2;
    
    // Calculate the absolute differences
    long long dx = abs(xs - cx);
    long long dy = abs(ys - cy);
    
    // If both differences have the same parity, we can reach the center 
    // using only diagonal moves (cost 0). Otherwise, we need 1 move.
    if (dx % 2 == dy % 2) {
        cout << 0 << "\n";
    } else {
        cout << 1 << "\n";
    }
}

int main() {
    // Optimize I/O operations
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