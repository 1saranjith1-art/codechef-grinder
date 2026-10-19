# [Failing Grades (FAIL)](https://www.codechef.com/problems/FAIL)

- **Difficulty Rating**: 697
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef takes $N$ tests. We are given the scores for each test. We need to determine if the average score remains at least 40 after every single test from the 1st to the $N$-th. If the average is $\ge 40$ at every step, output "Yes"; otherwise, output "No".

## Intuition & Mathematical Observation
The average score after $i$ tests is defined as:
$$\text{Average}_i = \frac{\sum_{j=1}^{i} A_j}{i}$$

We are required to check if $\text{Average}_i \ge 40$ for all $1 \le i \le N$. To avoid floating-point precision issues, we can rewrite the inequality:
$$\frac{\sum_{j=1}^{i} A_j}{i} \ge 40 \implies \sum_{j=1}^{i} A_j \ge 40 \times i$$

By maintaining a running sum of the scores as we iterate through the input, we can check this condition in constant time for each test. If at any point the running sum is less than $40 \times i$, the condition is violated, and we can conclude the answer is "No".

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of tests. We iterate through the list of scores exactly once.
- **Space Complexity**: $O(1)$, as we only store the running sum and the current score, rather than storing the entire array.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef takes N tests. We need to check if the average score after every test i
 * (where i ranges from 1 to N) is at least 40.
 * The average after i tests is (sum of A_1 to A_i) / i.
 * The condition (sum / i) >= 40 is equivalent to (sum >= 40 * i).
 * 
 * Time Complexity: O(N) per test case, O(T * N) total.
 * Space Complexity: O(1) as we process scores on the fly.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        cin >> n;
        
        long long current_sum = 0;
        bool possible = true;
        
        for (int i = 1; i <= n; ++i) {
            int a;
            cin >> a;
            current_sum += a;
            
            // Check if average is at least 40
            // Average = current_sum / i
            // Condition: current_sum / i >= 40  =>  current_sum >= 40 * i
            if (current_sum < 40LL * i) {
                possible = false;
            }
        }
        
        if (possible) {
            cout << "Yes" << "\n";
        } else {
            cout << "No" << "\n";
        }
    }
    
    return 0;
}
```