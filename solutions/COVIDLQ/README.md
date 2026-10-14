# [COVID Pandemic and Long Queue (COVIDLQ)](https://www.codechef.com/problems/COVIDLQ)

- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given a queue of length $N$ represented by an array $A$, where $1$ denotes a person standing at a spot and $0$ denotes an empty spot. The rule for social distancing is that every pair of people must be at least 6 feet apart. In terms of array indices, if two people are at indices $i$ and $j$ (where $i < j$), the condition $j - i \ge 6$ must hold for all consecutive pairs of people in the queue. We need to determine if the given arrangement follows this rule.

## Intuition & Mathematical Observation
The problem requires checking the distance between every consecutive pair of people. 
1. We can maintain a variable `last_pos` to store the index of the most recently encountered person.
2. Initialize `last_pos` to a value small enough (e.g., $-10$) so that the first person encountered does not trigger a false violation.
3. As we iterate through the array, whenever we encounter a $1$ at index $i$:
   - We check the distance from the previous person: `i - last_pos`.
   - If `i - last_pos < 6`, the social distancing rule is violated, and we can immediately conclude the answer is "NO".
   - Otherwise, we update `last_pos = i` and continue.
4. If the loop completes without finding any violations, the arrangement is valid ("YES").

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we perform a single linear scan through the array of size $N$.
- **Space Complexity**: $O(1)$ auxiliary space, as we only store a few integer variables regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given an array A of size N representing spots. 1 means occupied, 0 means empty.
 * Social distancing is followed if every pair of people is at least 6 feet apart.
 * This means if there is a person at index i and another person at index j (i < j),
 * then j - i must be >= 6.
 * 
 * Algorithm:
 * Keep track of the index of the last person seen.
 * Iterate through the array. If we encounter a person (A[i] == 1):
 * 1. If this is not the first person seen, check if (current_index - last_index) < 6.
 * 2. If it is < 6, social distancing is violated (return "NO").
 * 3. Update last_index to current_index.
 * If we finish the loop without violations, return "YES".
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Initialize with a value such that the first person found 
    // will always result in a distance >= 6.
    int last_pos = -10; 
    bool possible = true;

    for (int i = 0; i < N; ++i) {
        if (A[i] == 1) {
            if (i - last_pos < 6) {
                possible = false;
                break;
            }
            last_pos = i;
        }
    }

    if (possible) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
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