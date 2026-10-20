# [Laddu (LADDU)](https://www.codechef.com/problems/LADDU)

- **Difficulty Rating**: 1241
- **Solved in**: 1 attempt(s)

## Problem Summary
The goal is to calculate the maximum number of months a user can redeem their "Laddus" based on their activity history. Different activities yield different amounts of Laddus:
- **CONTEST_WON**: 300 points + bonus (if rank < 20, bonus = 20 - rank).
- **TOP_CONTRIBUTOR**: 300 points.
- **BUG_FOUND**: Points equal to the severity of the bug.
- **CONTEST_HOSTED**: 50 points.

After calculating the total points, we divide by a threshold determined by the user's origin:
- **INDIAN**: 200 points per month.
- **NON_INDIAN**: 400 points per month.

## Intuition & Mathematical Observation
The problem is a straightforward simulation. The key is to correctly parse the input strings and handle the conditional logic for each activity type. 
- For `CONTEST_WON`, we must be careful to read the `rank` integer only when that specific activity occurs.
- For `BUG_FOUND`, we must read the `severity` integer.
- The final result is simply the integer division of `total_laddus` by the `threshold`. Since we are looking for the number of months, integer division (`/`) naturally floors the result, which is the desired behavior.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the total number of activities across all test cases. We iterate through each activity exactly once.
- **Space Complexity**: $O(1)$, as we only store a few variables (`total_laddus`, `threshold`, etc.) regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * 1. Calculate total laddus based on activity types:
 *    - CONTEST_WON: 300 + max(0, 20 - rank)
 *    - TOP_CONTRIBUTOR: 300
 *    - BUG_FOUND: severity
 *    - CONTEST_HOSTED: 50
 * 2. Determine redemption threshold based on origin:
 *    - INDIAN: 200
 *    - NON_INDIAN: 400
 * 3. Calculate max months: total_laddus / threshold
 */

void solve() {
    int activities;
    string origin;
    cin >> activities >> origin;

    long long total_laddus = 0;

    for (int i = 0; i < activities; ++i) {
        string type;
        cin >> type;
        if (type == "CONTEST_WON") {
            int rank;
            cin >> rank;
            total_laddus += 300;
            if (rank < 20) {
                total_laddus += (20 - rank);
            }
        } else if (type == "TOP_CONTRIBUTOR") {
            total_laddus += 300;
        } else if (type == "BUG_FOUND") {
            int severity;
            cin >> severity;
            total_laddus += severity;
        } else if (type == "CONTEST_HOSTED") {
            total_laddus += 50;
        }
    }

    int threshold = (origin == "INDIAN") ? 200 : 400;
    cout << total_laddus / threshold << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}
```