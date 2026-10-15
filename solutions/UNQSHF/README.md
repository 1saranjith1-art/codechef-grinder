# [Unequal Shuffle (UNQSHF)](https://www.codechef.com/problems/UNQSHF)

- **Difficulty Rating**: 726
- **Solved in**: 1 attempt(s)

## Problem Summary
Given two strings $A$ and $B$ of length $N$ consisting only of characters 'a' and 'b', determine if it is possible to rearrange (shuffle) the characters of $A$ and $B$ independently such that for all indices $i$ ($0 \le i < N$), $A[i] \neq B[i]$.

## Intuition & Mathematical Observation
To satisfy the condition $A[i] \neq B[i]$ for all $i$, we must ensure that:
1. Whenever $A[i] = 'a'$, $B[i]$ must be 'b'.
2. Whenever $A[i] = 'b'$, $B[i]$ must be 'a'.

This implies that every 'a' in string $A$ must be "paired" with a 'b' in string $B$, and every 'b' in string $A$ must be "paired" with an 'a' in string $B$. 

Let:
- $countA_a$ be the number of 'a's in $A$.
- $countA_b$ be the number of 'b's in $A$.
- $countB_a$ be the number of 'a's in $B$.
- $countB_b$ be the number of 'b's in $B$.

For the condition to hold, the number of 'a's in $A$ must exactly match the number of 'b's available in $B$ to cover them. Thus, the necessary and sufficient condition is:
$$countA_a = countB_b$$

Since the total length of both strings is $N$, we know $countA_a + countA_b = N$ and $countB_a + countB_b = N$. If $countA_a = countB_b$, then it mathematically follows that $countA_b = countB_a$, satisfying the requirement for the 'b's in $A$ as well.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the length of the strings. We iterate through each string exactly once to count the characters.
- **Space Complexity**: $O(N)$ to store the input strings (or $O(1)$ if processing character by character).

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * To satisfy A[i] != B[i], every 'a' in A must be paired with a 'b' in B,
 * and every 'b' in A must be paired with an 'a' in B.
 * This is possible if and only if the count of 'a's in A equals the 
 * count of 'b's in B.
 */

void solve() {
    int N;
    cin >> N;
    string A, B;
    cin >> A >> B;

    int countA_a = 0;
    for (char c : A) {
        if (c == 'a') countA_a++;
    }

    int countB_b = 0;
    for (char c : B) {
        if (c == 'b') countB_b++;
    }

    if (countA_a == countB_b) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Optimize I/O operations
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