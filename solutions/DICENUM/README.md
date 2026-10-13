# [Dice Number (DICENUM)](https://www.codechef.com/problems/DICENUM)

- **Difficulty Rating**: 994
- **Solved in**: 1 attempt(s)

## Problem Summary
Alice and Bob each roll a standard 6-sided die three times. Given the three results for Alice and the three results for Bob, we need to determine who can form a larger 3-digit number using their respective rolls. If Alice's maximum possible number is greater, Alice wins; if Bob's is greater, Bob wins; otherwise, it is a tie.

## Intuition & Mathematical Observation
To form the largest possible 3-digit number from a set of three digits, the digits must be arranged in **descending order**. 

For example, if the rolls are $\{3, 2, 5\}$, the possible numbers are $235, 253, 325, 352, 523, 532$. The largest is $532$, which is achieved by placing the largest digit in the hundreds place, the second largest in the tens place, and the smallest in the units place.

**Algorithm:**
1. Read the three rolls for Alice and store them in a list.
2. Read the three rolls for Bob and store them in a list.
3. Sort both lists in descending order.
4. Convert the sorted digits into a 3-digit integer (e.g., $d_1 \times 100 + d_2 \times 10 + d_3$).
5. Compare the two resulting integers and print "Alice", "Bob", or "Tie" accordingly.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case. Since we are always sorting a fixed array of size 3, the sorting operation takes constant time ($3 \log 3$). With $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a fixed amount of extra space to store the three digits for each player.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * To form the maximum number from three digits, we should sort the digits 
 * in descending order and concatenate them.
 * For example, if rolls are 3, 2, 5, the maximum number is 532.
 * We compare Alice's maximum number with Bob's maximum number.
 */

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        vector<int> a(3), b(3);
        for (int i = 0; i < 3; ++i) cin >> a[i];
        for (int i = 0; i < 3; ++i) cin >> b[i];

        // Sort both arrays in descending order to form the largest possible number
        sort(a.begin(), a.end(), greater<int>());
        sort(b.begin(), b.end(), greater<int>());

        // Construct the numbers
        // Since the digits are 1-6, the max number is 666, which fits in int.
        int alice_score = a[0] * 100 + a[1] * 10 + a[2];
        int bob_score = b[0] * 100 + b[1] * 10 + b[2];

        if (alice_score > bob_score) {
            cout << "Alice" << "\n";
        } else if (bob_score > alice_score) {
            cout << "Bob" << "\n";
        } else {
            cout << "Tie" << "\n";
        }
    }

    return 0;
}
```