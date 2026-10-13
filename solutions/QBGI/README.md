# [Bar Queue (QBGI)](https://www.codechef.com/problems/QBGI)

- **Difficulty Rating**: 821
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to simulate a queue of people entering a bar. The queue is represented by a string $S$ consisting of 'B' (boys) and 'G' (girls). The security guard closes the entrance as soon as the number of boys ($b$) inside the bar exceeds twice the number of girls ($g$), i.e., $b > 2 \times g$. We need to determine the total number of people who successfully enter the bar before the gate is closed.

## Intuition & Mathematical Observation
The problem is a direct simulation task. Since the constraint on the string length is manageable, we can iterate through the string character by character and maintain two counters: one for boys and one for girls.

1. **Initialization**: Start with $b = 0$, $g = 0$, and a counter `count = 0`.
2. **Iteration**: For each character in the string:
   - Increment the corresponding counter ($b$ or $g$).
   - Increment the total `count` of people who have entered.
   - Check the condition $b > 2 \times g$.
   - If the condition is met, the current person is the last one allowed in; we stop the process immediately and output the current `count`.
3. **Edge Case**: If the loop finishes without the condition ever being met, the answer is simply the total length of the string $N$.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the length of the string $S$. We traverse the string at most once.
- **Space Complexity**: $O(N)$ to store the input string $S$. If we processed the input character-by-character without storing the string, this could be reduced to $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We iterate through the string S and maintain the count of boys (b) and girls (g).
 * The condition for closing the gate is: b > 2 * g.
 * We increment the count for each person and break as soon as the condition is met.
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    int b = 0;
    int g = 0;
    int count = 0;

    for (int i = 0; i < N; ++i) {
        if (S[i] == 'B') {
            b++;
        } else {
            g++;
        }
        count++;
        
        // Check if the current person triggers the gate closure
        if (b > 2 * g) {
            break;
        }
    }
    cout << count << "\n";
}

int main() {
    // Optimize I/O operations
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