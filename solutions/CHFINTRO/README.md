# [Chef and Interactive Contests (CHFINTRO)](https://www.codechef.com/problems/CHFINTRO)

- **Difficulty Rating**: 951
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef is organizing a contest and wants to categorize participants based on their current rating. Given a threshold rating $r$, every participant with a rating $R$ greater than or equal to $r$ is considered a "Good boi," while those with a rating strictly less than $r$ are considered "Bad boi." We need to process $N$ participants and output their status accordingly.

## Intuition & Mathematical Observation
The problem is a straightforward implementation task. For each participant, we are given a rating $R$ and a threshold $r$. We simply need to perform a conditional check:
- If $R \ge r$, print "Good boi".
- Otherwise, print "Bad boi".

Since the constraints on $N$ are small ($N \le 1000$) and the ratings are within a standard integer range, a simple loop iterating through the input is sufficient to solve the problem efficiently.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the number of participants. We iterate through the list of ratings exactly once, performing constant-time operations for each.
- **Space Complexity**: $O(1)$, as we only store a few variables ($N, r, R$) regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given N contestants and a threshold rating r.
 * For each contestant with rating R:
 * - If R >= r, they are a "Good boi".
 * - If R < r, they are a "Bad boi".
 * 
 * Constraints:
 * N <= 1000
 * 1300 <= r, R <= 1501
 * Time complexity required: O(N)
 * Space complexity required: O(1)
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    long long r;
    
    // Read N and r
    if (!(cin >> N >> r)) return 0;

    // Process each contestant
    for (int i = 0; i < N; ++i) {
        long long R;
        cin >> R;
        
        if (R >= r) {
            cout << "Good boi" << "\n";
        } else {
            cout << "Bad boi" << "\n";
        }
    }

    return 0;
}
```