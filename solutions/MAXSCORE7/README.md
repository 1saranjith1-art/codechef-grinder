# [Maximum Score (MAXSCORE7)](https://www.codechef.com/problems/MAXSCORE7)

- **Difficulty Rating**: 1202
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given an array $A$ consisting only of $0$s and $1$s. You can perform an operation where you choose two adjacent elements, add $|A_i - A_{i+1}|$ to your total score, and remove both elements from the array. The remaining elements shift to close the gap. The goal is to maximize the total score obtained until no elements remain.

## Intuition & Mathematical Observation
- The value $|A_i - A_{i+1}|$ is equal to $1$ if the pair is $(0, 1)$ or $(1, 0)$, and $0$ if the pair is $(0, 0)$ or $(1, 1)$.
- Each operation removes exactly two elements from the array.
- To maximize the score, we want to maximize the number of $(0, 1)$ or $(1, 0)$ pairs removed.
- Since removing any two adjacent elements allows the remaining elements to become adjacent, we can effectively pair any $0$ with any $1$ as long as we have both available.
- Every time we perform an operation on a $(0, 1)$ or $(1, 0)$ pair, we consume exactly one $0$ and one $1$.
- If we have $c_0$ zeros and $c_1$ ones, the maximum number of such pairs we can form is limited by the count of the minority element. Thus, the maximum score is $\min(c_0, c_1)$.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of elements in the array, as we iterate through the array once to count the zeros and ones.
- **Space Complexity**: $O(1)$, as we only store the counts of zeros and ones regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The array A consists only of 0s and 1s.
 * The operation involves picking two adjacent elements, adding |A_i - A_{i+1}| to the score,
 * and removing them.
 * Note that |A_i - A_{i+1}| is 1 if the elements are (0, 1) or (1, 0), and 0 if they are (0, 0) or (1, 1).
 * 
 * Let c0 be the count of 0s and c1 be the count of 1s in the array.
 * Each operation removes two elements.
 * If we remove (0, 1) or (1, 0), we gain 1 point and remove one 0 and one 1.
 * If we remove (0, 0) or (1, 1), we gain 0 points and remove two 0s or two 1s.
 * 
 * The maximum score is simply the number of pairs of (0, 1) we can form,
 * which is limited by the count of the less frequent digit.
 */

void solve() {
    int N;
    cin >> N;
    int c0 = 0, c1 = 0;
    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val;
        if (val == 0) c0++;
        else c1++;
    }
    
    // The maximum score is min(c0, c1)
    cout << min(c0, c1) << "\n";
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