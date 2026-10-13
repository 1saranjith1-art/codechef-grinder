# [Chef and Steps (CHEFSTEP)](https://www.codechef.com/problems/CHEFSTEP)

- **Difficulty Rating**: 1110
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has $N$ distances $D_1, D_2, \dots, D_N$ that he wants to traverse. He can only take steps of exactly length $K$. For each distance $D_i$, determine if it is possible for Chef to traverse it exactly using steps of length $K$. If the distance is divisible by $K$, output '1'; otherwise, output '0'.

## Intuition & Mathematical Observation
The problem asks whether a distance $D_i$ can be covered by taking an integer number of steps of length $K$. 
- If $D_i$ is a multiple of $K$, then $D_i = m \times K$ for some integer $m$. This means Chef can reach the destination by taking exactly $m$ steps.
- Mathematically, this is equivalent to checking if the remainder of $D_i$ divided by $K$ is zero:
  $$D_i \pmod K = 0$$
- Since $D_i$ and $K$ can be as large as $10^9$, we use `long long` in C++ to ensure no overflow occurs during calculations, although `int` would technically suffice for $10^9$.

## Complexity Analysis
- **Time Complexity**: $O(T \times N)$, where $T$ is the number of test cases and $N$ is the number of distances per test case. We iterate through each distance exactly once.
- **Space Complexity**: $O(1)$ auxiliary space (excluding the string used to store the output for each test case).

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef can only walk in steps of length K.
 * A distance D_i is traversable if and only if D_i is divisible by K.
 * Mathematically, D_i % K == 0.
 * 
 * Constraints:
 * T <= 1000, N <= 1000
 * K, D_i <= 10^9
 * Since K and D_i can be up to 10^9, we use long long to prevent 
 * any potential overflow issues.
 * 
 * Time Complexity: O(T * N)
 * Space Complexity: O(1) (excluding input storage)
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int n;
        long long k;
        cin >> n >> k;
        
        string result = "";
        for (int i = 0; i < n; ++i) {
            long long d;
            cin >> d;
            
            // Check if distance is divisible by step length K
            if (d % k == 0) {
                result += '1';
            } else {
                result += '0';
            }
        }
        
        cout << result << "\n";
    }
    
    return 0;
}
```