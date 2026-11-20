# [Make Palindrome 2 (MAKEPAL2)](https://www.codechef.com/problems/MAKEPAL2)

- **Difficulty Rating**: 1393
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a binary string $S$ of length $N$, we are allowed to delete at most $\lfloor N/2 \rfloor$ characters. The goal is to obtain a resulting string that is a palindrome. Since the string consists only of '0's and '1's, any string consisting entirely of a single character (e.g., "000" or "11") is inherently a palindrome.

## Intuition & Mathematical Observation
The problem allows us to delete up to half the characters of the string. This is a very generous constraint. 

1. **Observation**: A string consisting of only one type of character (all '0's or all '1's) is always a palindrome.
2. **Strategy**: Count the occurrences of '0's and '1's in the input string.
   - Let $count_0$ be the number of '0's and $count_1$ be the number of '1's.
   - We know that $count_0 + count_1 = N$.
   - If we choose to keep all '0's, we must delete all $count_1$ characters. Since $count_1 \le N/2$ is not guaranteed, we look at the majority character.
   - If $count_0 \ge count_1$, then $count_1 \le N/2$. Thus, we can delete all $count_1$ characters and keep all $count_0$ characters. The resulting string of '0's will have length $count_0 \ge N/2$, which is a valid palindrome.
   - Conversely, if $count_1 > count_0$, then $count_0 < N/2$. We can delete all $count_0$ characters and keep all $count_1$ characters. The resulting string of '1's will be a valid palindrome.

By simply outputting the majority character repeated $count_{majority}$ times, we satisfy the condition of deleting at most $\lfloor N/2 \rfloor$ characters while ensuring the result is a palindrome.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the length of the string. We iterate through the string once to count the characters and then iterate once more to print the result.
- **Space Complexity**: $O(N)$ to store the input string. If we processed the string character by character, this could be reduced to $O(1)$ auxiliary space.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given a binary string S of length N. We can delete at most floor(N/2) characters.
 * We need to obtain a palindrome.
 * 
 * Strategy:
 * Count the number of '0's and '1's in the string.
 * Since we can delete up to half the characters, we can simply keep all characters 
 * of the majority digit. If there are more '0's than '1's, we can form a string 
 * consisting only of '0's. If there are more '1's, we can form a string of '1's.
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    int count0 = 0;
    int count1 = 0;
    for (char c : S) {
        if (c == '0') count0++;
        else count1++;
    }

    // Output the majority character as many times as it appears
    if (count0 >= count1) {
        for (int i = 0; i < count0; ++i) {
            cout << '0';
        }
    } else {
        for (int i = 0; i < count1; ++i) {
            cout << '1';
        }
    }
    cout << "\n";
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