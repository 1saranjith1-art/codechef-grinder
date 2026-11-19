# [Deputy Chef (DEPCHEF)](https://www.codechef.com/problems/DEPCHEF)

- **Difficulty Rating**: 1397
- **Solved in**: 1 attempt(s)

## Problem Summary
There are $N$ soldiers arranged in a circle. Each soldier $i$ has an attack value $a_i$ and a defense value $d_i$. A soldier $i$ is attacked by their immediate neighbors (soldier $i-1$ and soldier $i+1$, with indices wrapping around). A soldier $i$ survives if their defense value $d_i$ is strictly greater than the sum of the attack values of the neighbors that choose to attack them. We need to find the maximum defense value $d_i$ among all soldiers who are guaranteed to survive, regardless of which neighbors choose to attack. If no such soldier exists, output -1.

## Intuition & Mathematical Observation
To guarantee survival, a soldier $i$ must be able to withstand the **worst-case scenario**. The worst-case scenario occurs when both neighbors ($i-1$ and $i+1$) choose to attack. 

1.  **Circular Indices**: Since the soldiers are in a circle, the neighbors of soldier $i$ are $(i-1+N) \pmod N$ and $(i+1) \pmod N$.
2.  **Survival Condition**: Soldier $i$ is guaranteed to survive if:
    $$d_i > a_{i-1} + a_{i+1}$$
3.  **Optimization**: We iterate through every soldier $i$ from $0$ to $N-1$, calculate the sum of their neighbors' attack values, and check the survival condition. We maintain a variable `max_defense` to track the highest $d_i$ that satisfies the condition.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the list of soldiers exactly once.
- **Space Complexity**: $O(N)$ to store the attack and defense values of the $N$ soldiers.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A soldier i is attacked by their neighbors (i-1) and (i+1).
 * Let the neighbors be L = (i-1) and R = (i+1).
 * Note: Indices are circular, so for i=0, L=N-1, R=1.
 * The soldier i survives if their defense d[i] is strictly greater than 
 * the sum of attack values of any combination of neighbors that choose to attack.
 * 
 * The worst-case scenario for soldier i is that BOTH neighbors choose to attack.
 * If d[i] > (a[L] + a[R]), then soldier i is guaranteed to survive regardless 
 * of whether the neighbors choose to attack or not.
 * 
 * We need to find the maximum d[i] among all soldiers who satisfy this condition.
 * If no soldier satisfies this, output -1.
 */

void solve() {
    int N;
    cin >> N;
    vector<long long> a(N), d(N);
    for (int i = 0; i < N; ++i) cin >> a[i];
    for (int i = 0; i < N; ++i) cin >> d[i];

    long long max_defense = -1;

    for (int i = 0; i < N; ++i) {
        // Identify neighbors in circular array
        int left = (i - 1 + N) % N;
        int right = (i + 1) % N;

        // The maximum possible attack power on soldier i is a[left] + a[right]
        long long max_attack = a[left] + a[right];

        // Check if the soldier is guaranteed to survive
        if (d[i] > max_attack) {
            if (d[i] > max_defense) {
                max_defense = d[i];
            }
        }
    }

    cout << max_defense << "\n";
}

int main() {
    // Fast I/O
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