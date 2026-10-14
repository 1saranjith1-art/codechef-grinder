# [Digit Sum Parities (DIGSMPAR)](https://www.codechef.com/problems/DIGSMPAR)

- **Difficulty Rating**: 1077
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an integer $N$, we need to find the smallest integer $X > N$ such that the parity of the sum of digits of $X$ is different from the parity of the sum of digits of $N$.

## Intuition & Mathematical Observation
The parity of the sum of digits of an integer $N$ is defined as `digitSum(N) % 2`. 
- When we increment an integer $N$ to $N+1$, the digit sum usually increases by 1 (unless there is a carry, e.g., $19 \to 20$, where the sum changes from $10 \to 2$).
- Because the digit sum changes frequently as we increment the number, the parity will flip very quickly. 
- In the worst case, we only need to check a very small number of integers greater than $N$ to find one with a different parity. Since $N$ is up to $10^9$, a simple linear search starting from $N+1$ is highly efficient and will terminate almost immediately.

## Complexity Analysis
- **Time Complexity**: $O(T \cdot K \cdot \log_{10}(N))$, where $T$ is the number of test cases, $K$ is the number of iterations required to find the next parity (which is very small, typically $\le 2$), and $\log_{10}(N)$ is the cost of calculating the digit sum.
- **Space Complexity**: $O(1)$, as we only use a few variables for storage.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given N and need to find the smallest X > N such that
 * parity(digitSum(N)) != parity(digitSum(X)).
 * 
 * Since N < 10^9, the digit sum is at most 9 * 9 = 81.
 * The parity of the digit sum changes very frequently as we increment N.
 * In the worst case, we only need to check a few consecutive integers
 * to find one with a different digit sum parity.
 */

int getDigitSum(long long n) {
    int sum = 0;
    while (n > 0) {
        sum += (n % 10);
        n /= 10;
    }
    return sum;
}

void solve() {
    long long n;
    cin >> n;
    
    int targetParity = getDigitSum(n) % 2;
    long long x = n + 1;
    
    // Increment x until the parity of its digit sum differs from n's parity
    while (true) {
        if ((getDigitSum(x) % 2) != targetParity) {
            cout << x << "\n";
            break;
        }
        x++;
    }
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