# [Avoid Squares Please (AVDSQUARPLZ)](https://www.codechef.com/problems/AVDSQUARPLZ)

- **Difficulty Rating**: 960
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an integer $N$, we need to construct a permutation of the numbers from $1$ to $N$ such that for any two adjacent elements $P[i]$ and $P[i+1]$, their product $P[i] \times P[i+1]$ is **not** a perfect square.

## Intuition & Mathematical Observation
The condition $P[i] \times P[i+1] = k^2$ occurs if and only if $P[i]$ and $P[i+1]$ share the same "square-free part." For example, $2$ and $8$ share the square-free part $2$ ($2 = 2 \times 1^2$, $8 = 2 \times 2^2$), and their product $16$ is a perfect square.

**Strategy:**
1. **Heuristic Approach:** A simple descending sequence ($N, N-1, \dots, 1$) is highly effective for small $N$. In most cases, adjacent numbers in this sequence do not share the same square-free part.
2. **Fallback Mechanism:** If the descending sequence happens to contain an adjacent pair whose product is a perfect square, we can use a randomized approach. By shuffling the permutation and checking the condition, we can quickly find a valid arrangement. Given the constraints ($N \le 500$), a randomized search (`std::shuffle`) will find a valid permutation almost instantaneously.

## Complexity Analysis
- **Time Complexity**: $O(T \times N)$, where $T$ is the number of test cases. In the worst case, the shuffle runs a few times, but the check is $O(N)$, making the overall complexity very efficient for $N=500$.
- **Space Complexity**: $O(N)$ to store the permutation array.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need a permutation of [1, ..., N] such that P[i] * P[i+1] is not a perfect square.
 * The reverse sequence N, N-1, ..., 1 works for most cases.
 * If it fails, we use a randomized shuffle to find a valid permutation.
 */

void solve() {
    int N;
    cin >> N;
    
    vector<int> p(N);
    for (int i = 0; i < N; ++i) {
        p[i] = N - i;
    }
    
    auto is_square = [](long long n) {
        long long root = round(sqrt(n));
        return root * root == n;
    };
    
    bool ok = true;
    for (int i = 0; i < N - 1; ++i) {
        if (is_square((long long)p[i] * p[i + 1])) {
            ok = false;
            break;
        }
    }
    
    // If reverse doesn't work, use a random shuffle
    if (!ok) {
        iota(p.begin(), p.end(), 1);
        mt19937 rng(1337);
        while (true) {
            shuffle(p.begin(), p.end(), rng);
            bool possible = true;
            for (int i = 0; i < N - 1; ++i) {
                if (is_square((long long)p[i] * p[i + 1])) {
                    possible = false;
                    break;
                }
            }
            if (possible) break;
        }
    }
    
    for (int i = 0; i < N; ++i) {
        cout << p[i] << (i == N - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
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