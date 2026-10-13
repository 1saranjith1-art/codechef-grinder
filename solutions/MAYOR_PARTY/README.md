# [Peaceful Party (MAYOR_PARTY)](https://www.codechef.com/problems/MAYOR_PARTY)

- **Difficulty Rating**: 898
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given the populations of three regions: $P_A$, $P_B$, and $P_C$. We need to invite people from these regions to a party such that no two conflicting regions are invited together. The conflict rules are:
- Region $B$ cannot be invited with Region $A$.
- Region $B$ cannot be invited with Region $C$.

We need to determine the maximum number of people we can invite while adhering to these constraints.

## Intuition & Mathematical Observation
The constraints imply that Region $B$ is "incompatible" with both $A$ and $C$. However, there is no stated conflict between Region $A$ and Region $C$. 

This leaves us with two mutually exclusive valid strategies:
1. **Invite from $A$ and $C$**: Since there is no conflict between $A$ and $C$, we can invite both. The total number of people is $P_A + P_C$.
2. **Invite from $B$**: Since $B$ conflicts with both $A$ and $C$, if we invite people from $B$, we cannot invite anyone from $A$ or $C$. The total number of people is $P_B$.

To maximize the total attendance, we simply compare these two scenarios and take the maximum:
$$\text{Result} = \max(P_A + P_C, P_B)$$

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case. Since there are $T$ test cases, the total time complexity is $O(T)$. Given $T \le 1000$, this easily passes within the time limit.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the populations and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have three regions A, B, and C with populations P_A, P_B, and P_C.
 * Conflict rules:
 * - Region B cannot be with A.
 * - Region B cannot be with C.
 * 
 * Possible valid combinations:
 * 1. Invite people from A and C: Total = P_A + P_C
 * 2. Invite people from B: Total = P_B
 * 
 * We want to maximize the number of people invited.
 * Therefore, the answer is max(P_A + P_C, P_B).
 */

int main() {
    // Fast I/O for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int pa, pb, pc;
        cin >> pa >> pb >> pc;
        
        // Calculate the two possible scenarios
        int option1 = pa + pc;
        int option2 = pb;
        
        // Output the maximum of the two
        cout << max(option1, option2) << "\n";
    }
    
    return 0;
}
```