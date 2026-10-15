# [New-Pro Coder (SPC2025)](https://www.codechef.com/problems/SPC2025)

- **Difficulty Rating**: 467
- **Solved in**: 2 attempt(s)

## Problem Summary
The task is to classify a coder as either a "NEWBIE" or a "PRO" based on their performance. Given $N$ (the total number of lines of code) and $M$ (the number of lines with errors), the coder is classified as a "NEWBIE" if the number of errors $M$ is at least half of the total lines $N$. Otherwise, the coder is classified as a "PRO".

## Intuition & Mathematical Observation
The condition provided is $M \ge \frac{N}{2}$. 

To avoid potential precision issues or the need for floating-point arithmetic (which can be slower or lead to rounding errors), we can multiply both sides of the inequality by 2:
$$2 \times M \ge N$$

This integer-based comparison is robust and efficient. If this condition holds true, we output "NEWBIE"; otherwise, we output "PRO".

## Complexity Analysis
- **Time Complexity**: $O(1)$ — The solution performs a single arithmetic comparison and a constant number of I/O operations, regardless of the input size.
- **Space Complexity**: $O(1)$ — We only use a fixed amount of memory to store the two integer variables $N$ and $M$.

## Solution Code

```cpp
#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * Ved is a NEWBIE if M >= N / 2.0.
 * To avoid floating point arithmetic, we use the condition:
 * M >= N / 2.0  =>  2 * M >= N
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    if (cin >> N >> M) {
        // Check if errors are at least half of the total lines
        // 2 * M >= N correctly implements M >= N / 2.0
        if (2 * M >= N) {
            cout << "NEWBIE" << endl;
        } else {
            cout << "PRO" << endl;
        }
    }

    return 0;
}
```