# [Tekken (TEKKEN)](https://www.codechef.com/problems/TEKKEN)

- **Difficulty Rating**: 947
- **Solved in**: 1 attempt(s)

## Problem Summary
Anna, Bob, and Claudio are participating in a Tekken tournament. The tournament consists of two fights:
1. Bob and Claudio fight each other.
2. The winner of the first fight then fights Anna.

In each fight, both players' health values are reduced by the minimum of the two health values. This effectively means the player with lower health is eliminated (health becomes 0), and the player with higher health has their health reduced by the amount of the opponent's health. We need to determine if Anna can win the tournament (i.e., have health $> 0$ after her fight).

## Intuition & Mathematical Observation
The mechanics of the fight state that if two players with health $X$ and $Y$ fight, the survivor will have $|X - Y|$ health. 

1. **First Fight (Bob vs. Claudio):** Regardless of who wins, the survivor will have exactly $|B - C|$ health, and the loser will have $0$ health.
2. **Second Fight (Anna vs. Survivor):** Anna now fights the survivor of the first match. Anna has health $A$ and the survivor has health $|B - C|$.
3. **Winning Condition:** Anna wins if her health remains strictly greater than $0$ after the fight. Based on the rules, Anna's health after the fight will be $A - \min(A, |B - C|)$. For this to be greater than $0$, we must have $A > |B - C|$.

Thus, the problem simplifies to checking if $A > |B - C|$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform basic arithmetic operations and comparisons.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the health values.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The fight between Bob and Claudio results in a survivor with health |B - C|.
 * Anna then fights this survivor. Anna wins if her health A is greater than 
 * the survivor's health |B - C|.
 */

void solve() {
    long long A, B, C;
    if (!(cin >> A >> B >> C)) return;

    // The survivor of the first fight (B vs C) has health |B - C|.
    // Anna wins if her health A is strictly greater than the survivor's health.
    long long survivor_BC = abs(B - C);
    
    if (A > survivor_BC) {
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
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}
```