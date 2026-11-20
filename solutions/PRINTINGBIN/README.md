# [Printing Binary Array (PRINTINGBIN)](https://www.codechef.com/problems/PRINTINGBIN)

- **Difficulty Rating**: 1130
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a binary array $A$ of size $N$, we define the "Score" of the array as the number of indices $i$ (where $1 \le i < N$) such that $A_i \neq A_{i+1}$. We need to construct a different binary array $C$ (where $C \neq A$) such that the Score of $C$ is equal to the Score of $A$.

## Intuition & Mathematical Observation
The "Score" of a binary array is essentially the count of transitions between $0$ and $1$. 

Consider the operation of flipping every bit in the array (i.e., changing every $0$ to $1$ and every $1$ to $0$). Let the new array be $C$, where $C_i = 1 - A_i$.
- **Preservation of Score**: A transition occurs at index $i$ if $A_i \neq A_{i+1}$. In the flipped array, a transition occurs if $(1 - A_i) \neq (1 - A_{i+1})$. This inequality is mathematically equivalent to $A_i \neq A_{i+1}$. Therefore, the number of transitions remains identical.
- **Distinctness**: Since we are flipping every bit, $C$ will always be different from $A$ (as long as $N \ge 1$). 

Thus, simply flipping every bit in the input array provides a valid solution that satisfies both conditions: $C \neq A$ and $\text{Score}(C) = \text{Score}(A)$.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the array exactly once to flip the bits.
- **Space Complexity**: $O(N)$ to store the input array (or $O(1)$ if processing elements on the fly).

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Score(B) is the number of transitions (0 to 1 or 1 to 0) in the array.
 * We need to find an array C such that C != A and Score(C) == Score(A).
 * 
 * By flipping every bit in the array (0 becomes 1, 1 becomes 0), the 
 * transitions remain exactly the same. If A_i != A_{i+1}, then 
 * (1-A_i) != (1-A_{i+1}). Thus, Score(A) == Score(flipped A).
 * Since A != flipped A, flipping all bits is a valid solution.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Flipping all bits: 0 -> 1, 1 -> 0
    for (int i = 0; i < N; ++i) {
        cout << (1 - A[i]) << (i == N - 1 ? "" : " ");
    }
    cout << "\n";
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