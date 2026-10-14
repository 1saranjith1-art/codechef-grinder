# [The Tom and Jerry Game! (EOEO)](https://www.codechef.com/problems/EOEO)

- **Difficulty Rating**: 1337
- **Solved in**: 1 attempt(s)

## Problem Summary
Tom and Jerry are playing a game with a number $TS$ (Tom's strength). Jerry chooses a number $JS$ such that $1 \le JS \le TS$. The game proceeds in turns: if both numbers are even, both are divided by 2. This continues until at least one of them becomes odd. If $TS$ becomes odd and $JS$ is even, Jerry wins. If $TS$ is even and $JS$ is odd, Tom wins. If both become odd, it is a draw. We need to find the number of possible values for $JS$ such that Jerry wins.

## Intuition & Mathematical Observation
Let $TS = 2^k \cdot m$, where $m$ is an odd integer. 
The game effectively removes all factors of 2 from both numbers. Let $JS = 2^p \cdot n$, where $n$ is an odd integer.

After the division process:
1. Tom's strength becomes $m$ (which is odd).
2. Jerry's strength becomes $n$ (which is odd).

For Jerry to win, the rules state that after the division process, $TS$ must be odd and $JS$ must be even. However, the problem defines Jerry winning when $TS$ becomes odd and $JS$ is even *at the point the game stops*. 

By analyzing the powers of 2:
- If we divide both $TS$ and $JS$ by $2^{\min(k, p)}$, one of them will become odd.
- For Jerry to win, he needs $JS$ to have a higher power of 2 than $TS$ does. Specifically, if $TS = 2^k \cdot m$, Jerry wins if $JS$ is a multiple of $2^{k+1}$.
- Since $1 \le JS \le TS$, we are looking for the count of multiples of $2^{k+1}$ in the range $[1, TS]$.
- The number of such multiples is simply $\lfloor \frac{TS}{2^{k+1}} \rfloor$.

## Complexity Analysis
- **Time Complexity**: $O(\log(TS))$ per test case, as we perform a loop to find the highest power of 2 dividing $TS$. Given $TS \le 10^{18}$, this is approximately 60 iterations, which is well within the time limit.
- **Space Complexity**: $O(1)$, as we only use a few variables for calculation.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let TS = 2^k * m, where m is odd.
 * Jerry wins if the power of 2 dividing JS (let's call it 2^p) 
 * is strictly greater than the power of 2 dividing TS (2^k).
 * 
 * We need to count JS in [1, TS] such that JS is a multiple of 2^(k+1).
 * The number of multiples of 2^(k+1) in the range [1, TS] is floor(TS / 2^(k+1)).
 */

void solve() {
    long long ts;
    cin >> ts;

    // Find the power of 2 that divides ts
    long long temp_ts = ts;
    long long power_of_2 = 1;
    while (temp_ts % 2 == 0) {
        power_of_2 *= 2;
        temp_ts /= 2;
    }

    // We need JS to be a multiple of (power_of_2 * 2)
    // such that JS <= TS.
    // The number of such multiples is TS / (power_of_2 * 2)
    long long divisor = power_of_2 * 2;
    cout << ts / divisor << "\n";
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