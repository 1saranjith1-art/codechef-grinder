# [Chef-Detective (CHEFDETE)](https://www.codechef.com/problems/CHEFDETE)

- **Difficulty Rating**: 1253
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given $N$ members in a reporting hierarchy. Each member $i$ reports to exactly one supervisor $R_i$. A "potential killer" is defined as a member who is not reported to by anyone else. Given the list of reports, we need to identify all such members and output them in ascending order.

## Intuition & Mathematical Observation
The problem asks us to find all indices $j \in \{1, 2, \dots, N\}$ that do not appear in the input array $R$. 

1. **Reporting Structure**: If a member $i$ reports to $R_i$, then $R_i$ is a supervisor. Therefore, $R_i$ cannot be a "potential killer."
2. **Frequency Tracking**: We can use a boolean array (or a frequency array) of size $N+1$ to keep track of which members have been reported to.
3. **Algorithm**:
   - Initialize an array `is_reported` of size $N+1$ with `false`.
   - Iterate through the input list. For every report $R_i$, set `is_reported[R_i] = true`.
   - After processing all inputs, iterate from $1$ to $N$. Any index $i$ where `is_reported[i]` remains `false` is a potential killer.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the number of members. We perform a single pass to read the input and another pass to check the status of each member.
- **Space Complexity**: $O(N)$ to store the `is_reported` status for each of the $N$ members.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given N members. Each member i reports to Ri.
 * A potential killer is someone who nobody reports to.
 * This means we need to find all indices j (1 to N) such that 
 * no member i has Ri == j.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    // is_reported[i] will be true if someone reports to member i
    vector<bool> is_reported(N + 1, false);

    for (int i = 0; i < N; ++i) {
        int r;
        cin >> r;
        // If r > 0, member r is being reported to.
        if (r >= 0 && r <= N) {
            is_reported[r] = true;
        }
    }

    // Collect and print all members who are not reported to
    bool first = true;
    for (int i = 1; i <= N; ++i) {
        if (!is_reported[i]) {
            if (!first) {
                cout << " ";
            }
            cout << i;
            first = false;
        }
    }
    cout << "\n";

    return 0;
}
```