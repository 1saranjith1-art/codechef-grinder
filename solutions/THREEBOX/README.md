# [Three Boxes (THREEBOX)](https://www.codechef.com/problems/THREEBOX)

- **Difficulty Rating**: 1183
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given three items with sizes $A, B,$ and $C$, and a bag with capacity $D$. We need to determine the minimum number of bags required to carry all three items, given that each bag can hold items whose total size does not exceed $D$.

## Intuition & Mathematical Observation
The problem asks for the minimum number of bags. Since we only have three items, the answer must be 1, 2, or 3. We can determine the answer by checking the conditions in increasing order of bag count:

1.  **1 Bag**: If the sum of all items $(A + B + C)$ is less than or equal to $D$, all items fit into a single bag.
2.  **2 Bags**: If they don't fit in one bag, we check if they can fit in two. Since we want to minimize bags, we should try to group the smallest items together. Given the constraint $A \le B \le C$, the most efficient way to pack two bags is to check if the two smallest items $(A + B)$ fit into one bag. If $A + B \le D$, then $C$ can go into the second bag, totaling 2 bags.
3.  **3 Bags**: If neither of the above conditions is met, it is impossible to fit the items into fewer than 3 bags. Thus, each item requires its own bag.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we perform a constant number of arithmetic operations and comparisons.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the input.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have three boxes A, B, C and bags of size D.
 * Constraints: A <= B <= C <= D.
 * We want to minimize the number of bags.
 * 
 * Logic:
 * 1. If A + B + C <= D, we can fit all in 1 bag.
 * 2. If not, check if we can fit two boxes in one bag:
 *    - Since A <= B <= C, the smallest sum of two is A + B.
 *    - If A + B <= D, we can put A and B in one bag, and C in another (2 bags).
 * 3. If no pair fits, we need 3 bags.
 */

void solve() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    // Case 1: All three fit in one bag
    if (A + B + C <= D) {
        cout << 1 << "\n";
    }
    // Case 2: Check if two boxes can fit in one bag
    // Since A <= B <= C, the smallest sum of two is A + B.
    // If A + B <= D, we can put A and B in one bag, and C in another.
    else if (A + B <= D) {
        cout << 2 << "\n";
    }
    // Case 3: Otherwise, each box needs its own bag
    else {
        cout << 3 << "\n";
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