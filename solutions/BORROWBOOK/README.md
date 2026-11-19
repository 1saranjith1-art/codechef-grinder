# [Chefland Library (BORROWBOOK)](https://www.codechef.com/problems/BORROWBOOK)

- **Difficulty Rating**: 1058
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has $N$ books, where the $i$-th book (indexed from 1 to $N$) is returned $i$ days late. Each book is returned on a specific day $A_i$. If multiple books are returned on the same day, the library only charges the penalty corresponding to the book that was the most days late (i.e., the maximum $i$ among all books returned on that day). We need to calculate the total penalty Chef has to pay.

## Intuition & Mathematical Observation
1. **Penalty Mapping**: Each book $i$ has a penalty value equal to its index $i$.
2. **Grouping by Day**: Since multiple books can be returned on the same day $A_i$, we are only interested in the maximum penalty value for each unique day.
3. **Data Structure**: We can use an array (or a frequency-like map) of size $10^5 + 1$ to store the maximum penalty encountered for each day.
4. **Aggregation**: After processing all $N$ books, the total penalty is simply the sum of the maximum penalties stored for every day that had at least one book returned.
5. **Data Type**: The maximum possible sum of penalties is $\sum_{i=1}^{10^5} i \approx 5 \times 10^9$. Since this exceeds the capacity of a standard 32-bit `int` (which goes up to $\approx 2 \times 10^9$), we must use `long long` to store the total penalty.

## Complexity Analysis
- **Time Complexity**: $O(N + M)$, where $N$ is the number of books and $M$ is the maximum day value ($10^5$). We iterate through the books once and then iterate through the penalty array once.
- **Space Complexity**: $O(M)$, where $M$ is the maximum day value, used to store the `max_penalty` array.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N books. The i-th book (1-indexed) was returned i days late.
 * The i-th book was returned on day A_i.
 * Rule: If multiple books are returned on the same day, only the maximum 
 * penalty (number of days late) among them is counted for that day.
 */

void solve() {
    int N;
    cin >> N;
    
    // Using a vector to store the maximum penalty for each day.
    // Constraints: A_i <= 10^5.
    vector<int> max_penalty(100001, 0);
    
    for (int i = 1; i <= N; ++i) {
        int day;
        cin >> day;
        // The penalty for the i-th book is i.
        // Update the day's penalty if the current book is later than previous ones.
        if (i > max_penalty[day]) {
            max_penalty[day] = i;
        }
    }
    
    // Calculate the total penalty by summing up the max values for each day.
    long long total_penalty = 0;
    for (int i = 1; i <= 100000; ++i) {
        total_penalty += max_penalty[i];
    }
    
    cout << total_penalty << "\n";
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