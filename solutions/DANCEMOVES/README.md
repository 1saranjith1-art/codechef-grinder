# [Dance Moves (DANCEMOVES)](https://www.codechef.com/problems/DANCEMOVES)

- **Difficulty Rating**: -1
- **Solved in**: 3 attempt(s)

## Problem Summary
Chef is at position $X$ on a number line and wants to reach position $Y$. He has two types of moves:
1. **Moonwalk**: Move from $P$ to $P+2$.
2. **Slide**: Move from $P$ to $P-1$.

We need to find the minimum number of moves required to reach $Y$ starting from $X$.

## Intuition & Mathematical Observation

The problem can be split into two cases based on the relative values of $X$ and $Y$:

1. **Case $X \ge Y$**:
   Since we can only move forward by $+2$ and backward by $-1$, if we are already ahead of or at the target, the only way to reach $Y$ is by using the slide move ($-1$) repeatedly.
   - **Moves required**: $X - Y$.

2. **Case $X < Y$**:
   Let $D = Y - X$ be the distance we need to cover. We want to reach $D$ using $a$ moonwalks ($+2$) and $b$ slides ($-1$).
   - Equation: $2a - b = D$
   - Total moves: $M = a + b$
   
   Substituting $b = 2a - D$ into the total moves equation:
   $M = a + (2a - D) = 3a - D$
   
   To minimize $M$, we need the smallest $a$ such that $2a \ge D$ (since $b$ cannot be negative).
   - **If $D$ is even**: We can reach the target using only moonwalks. $a = D/2$, $b = 0$.
     - Total moves: $D/2$.
   - **If $D$ is odd**: We need at least one slide to adjust the parity. We take one extra moonwalk to overshoot by 1, then slide back.
     - $a = (D+1)/2$, $b = 1$.
     - Total moves: $(D+1)/2 + 1$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution uses simple arithmetic operations.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and result.

## Solution Code

```cpp
#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * Chef starts at X, target Y.
 * Moves: +2 (Moonwalk), -1 (Slide).
 * 
 * If X >= Y:
 * We only use the slide move (-1).
 * Moves = X - Y.
 * 
 * If X < Y:
 * Let D = Y - X.
 * We need 2a - b = D, where a = moonwalks, b = slides.
 * Total moves = a + b.
 * Substituting b = 2a - D: Total = 3a - D.
 * To minimize, we need the smallest 'a' such that 2a >= D.
 * If D is even: a = D/2, b = 0. Total = D/2.
 * If D is odd: a = (D+1)/2, b = 1. Total = (D+1)/2 + 1.
 */

void solve() {
    long long X, Y;
    if (!(cin >> X >> Y)) return;
    
    if (X >= Y) {
        cout << (X - Y) << "\n";
    } else {
        long long D = Y - X;
        if (D % 2 == 0) {
            cout << (D / 2) << "\n";
        } else {
            // D is odd: use (D+1)/2 moonwalks and 1 slide
            cout << (D + 1) / 2 + 1 << "\n";
        }
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