# [Signal (P2BAR)](https://www.codechef.com/problems/P2BAR)

- **Difficulty Rating**: 657
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a binary string of length $N$ representing a signal, we need to count the number of '1's that appear strictly after the first occurrence of a '0'. If no '0' exists in the string, the count should be 0.

## Intuition & Mathematical Observation
The problem requires us to track the state of the signal. We can think of this as a state machine with two states:
1. **State 0 (Pre-silence)**: We have not encountered a '0' yet. Any '1's seen here do not contribute to our count.
2. **State 1 (Post-silence)**: We have encountered at least one '0'. Any '1's seen from this point onwards should be counted.

By using a boolean flag (`silence_found`), we can transition from State 0 to State 1 the moment we encounter the first '0'. Once in State 1, every '1' we encounter increments our total count.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the length of the string. We perform a single linear scan through the input string.
- **Space Complexity**: $O(N)$ to store the input string $S$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to count the number of '1's that appear after the first occurrence of a '0'.
 * 
 * Approach:
 * 1. Iterate through the string.
 * 2. Maintain a boolean flag `silence_found` initialized to false.
 * 3. If we encounter a '0', set `silence_found` to true.
 * 4. If we encounter a '1' and `silence_found` is true, increment the counter.
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    long long pulse_count = 0;
    bool silence_found = false;

    for (int i = 0; i < N; ++i) {
        if (S[i] == '0') {
            silence_found = true;
        } else if (S[i] == '1') {
            if (silence_found) {
                pulse_count++;
            }
        }
    }

    cout << pulse_count << "\n";
}

int main() {
    // Fast I/O setup for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}
```