# [Odd Even (ODDEVEN7)](https://www.codechef.com/problems/ODDEVEN7)

- **Difficulty Rating**: 877
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array of $N$ integers, we want to find the size of the largest subset that can be rearranged such that the parities (odd/even) of the elements alternate. An alternating sequence follows the pattern: `Odd, Even, Odd, Even...` or `Even, Odd, Even, Odd...`.

## Intuition & Mathematical Observation
To form an alternating sequence, we need to pair each odd number with an even number. 

1. **Counting**: First, count the total number of odd integers (`cntOdd`) and even integers (`cntEven`) in the given array.
2. **Pairing**: We can form pairs of `(Odd, Even)`. The number of such pairs we can form is limited by the smaller of the two counts: `min(cntOdd, cntEven)`.
3. **Constructing the Sequence**:
   - If `cntOdd == cntEven`, we can use all numbers to form a sequence of length `cntOdd + cntEven`.
   - If `cntOdd != cntEven`, we can use all numbers from the smaller group and match them with an equal number from the larger group. We can then add one extra element from the larger group to the start or end of the sequence.
   - Mathematically, the maximum length is `2 * min(cntOdd, cntEven) + 1`.

This logic covers both cases efficiently.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of elements in the array. We iterate through the array exactly once to count the parities.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the counts regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * An array is "good" if parities alternate (Odd, Even, Odd, Even... or Even, Odd, Even, Odd...).
 * To maximize the size of a subset that can be rearranged into a good array,
 * we need to count how many odd numbers (cntOdd) and how many even numbers (cntEven)
 * we have in the original array.
 * 
 * In an alternating sequence:
 * - If we have equal numbers of odds and evens (cntOdd == cntEven), 
 *   we can use all of them: size = cntOdd + cntEven.
 * - If they are not equal, the maximum difference between the count of odds and 
 *   evens in an alternating sequence is 1.
 *   For example, if we have 5 odds and 2 evens, we can pick 3 odds and 2 evens 
 *   to form a sequence of length 5 (O, E, O, E, O).
 *   The formula is: 2 * min(cntOdd, cntEven) + (cntOdd != cntEven ? 1 : 0).
 */

void solve() {
    int N;
    cin >> N;
    int cntOdd = 0;
    int cntEven = 0;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        if (a % 2 == 0) {
            cntEven++;
        } else {
            cntOdd++;
        }
    }

    if (cntOdd == cntEven) {
        cout << cntOdd + cntEven << "\n";
    } else {
        // We take the smaller count and match it with the larger count.
        // The maximum length is 2 * min + 1.
        cout << 2 * min(cntOdd, cntEven) + 1 << "\n";
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