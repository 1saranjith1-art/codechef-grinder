# [Hattrick (HATTRICK)](https://www.codechef.com/problems/HATTRICK)

- **Difficulty Rating**: 853
- **Solved in**: 2 attempt(s)

## Problem Summary
In a cricket over consisting of 6 balls, a "hattrick" is defined as taking 3 wickets consecutively. Given the outcomes of 6 balls (where 'W' represents a wicket and any other character represents a non-wicket), determine if a hattrick occurred during the over.

## Intuition & Mathematical Observation
Since the input size is fixed at 6 balls, we can represent the over as an array or vector of strings. A hattrick occurs if there exists any index $i$ such that the balls at positions $i, i+1,$ and $i+2$ are all 'W'.

Given the constraints (6 balls), the possible starting positions for a 3-ball sequence are indices 0, 1, 2, and 3. We can iterate through these indices and check the condition:
`balls[i] == "W" && balls[i+1] == "W" && balls[i+2] == "W"`

If this condition is met at any point, we output "YES"; otherwise, after checking all possibilities, we output "NO".

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case. Since the number of balls is fixed at 6, the loop runs a constant number of times (4 iterations), making the operation time constant regardless of input values.
- **Space Complexity**: $O(1)$. We store exactly 6 strings in a vector, which requires a constant amount of memory.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * Problem: HATTRICK
 * Logic: We are given 6 inputs representing balls in an over.
 * A hattrick occurs if there are 3 consecutive 'W's.
 * We check indices (0,1,2), (1,2,3), (2,3,4), and (3,4,5).
 */

void solve() {
    vector<string> balls(6);
    for (int i = 0; i < 6; ++i) {
        cin >> balls[i];
    }

    bool hattrick = false;
    // Check for 3 consecutive 'W's
    for (int i = 0; i <= 3; ++i) {
        if (balls[i] == "W" && balls[i + 1] == "W" && balls[i + 2] == "W") {
            hattrick = true;
            break;
        }
    }

    if (hattrick) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    // Optimize I/O operations
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