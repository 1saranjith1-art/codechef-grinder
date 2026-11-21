# [Sed Sequences (SEDARR)](https://www.codechef.com/problems/SEDARR)

- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ of $N$ positive integers and an integer $K$, we want the sum of the elements of the array to be divisible by $K$. We are allowed to change any element of the array to any other positive integer. We need to find the minimum number of operations (changes) required to make the sum of the array divisible by $K$.

## Intuition & Mathematical Observation
Let $S$ be the sum of the initial elements of the array. 

1. **Case 1: $S \pmod K = 0$**
   If the sum is already divisible by $K$, no operations are required. The answer is **0**.

2. **Case 2: $S \pmod K \neq 0$**
   If the sum is not divisible by $K$, we need to change at least one element. Let the initial sum be $S$. If we change one element $A_i$ to $A_i'$, the new sum $S'$ becomes $S - A_i + A_i'$. 
   We want $S' \equiv 0 \pmod K$, which implies:
   $$A_i' \equiv (A_i - S) \pmod K$$
   Since we can choose any positive integer $A_i'$, we can always pick an $A_i'$ that satisfies this congruence (ensuring $A_i' > 0$). Thus, we only ever need **1** operation to fix the sum if it is not already divisible by $K$.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of elements in the array, as we must iterate through the array once to calculate the sum.
- **Space Complexity**: $O(1)$, as we only store the running sum and a few variables regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given a sequence A of N positive integers and an integer K.
 * We want the sum of the elements to be divisible by K.
 * We can change any element to any positive integer.
 * 
 * Let S be the sum of the initial elements.
 * If S % K == 0, we need 0 operations.
 * If S % K != 0, we can change exactly one element.
 * Why? Because if we change one element A_i to A_i', the new sum S' = S - A_i + A_i'.
 * We want S' % K == 0, which means A_i' = K * m - (S - A_i).
 * Since we can choose any positive integer A_i', we can always find a positive 
 * integer A_i' such that the sum becomes divisible by K, provided we have at 
 * least one element to change.
 * 
 * Therefore, if the sum is already divisible by K, the answer is 0.
 * Otherwise, the answer is 1.
 */

void solve() {
    int N;
    long long K;
    cin >> N >> K;
    
    long long sum = 0;
    for (int i = 0; i < N; ++i) {
        long long a;
        cin >> a;
        sum += a;
    }
    
    if (sum % K == 0) {
        cout << 0 << "\n";
    } else {
        cout << 1 << "\n";
    }
}

int main() {
    // Fast I/O setup
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