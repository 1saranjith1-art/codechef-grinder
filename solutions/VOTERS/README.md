# [Discrepancies in the Voters List (VOTERS)](https://www.codechef.com/problems/VOTERS)

- **Difficulty Rating**: 1114
- **Solved in**: 1 attempt(s)

## Problem Summary
We are provided with three separate lists of voter IDs, each already sorted in ascending order. The objective is to identify all voter IDs that appear in at least two out of the three lists. The final output must list these IDs in ascending order, preceded by the total count of such IDs.

## Intuition & Mathematical Observation
Since the input lists are already sorted, one could theoretically use a three-pointer approach to merge and count occurrences in $O(N)$ time. However, given the constraints ($N_1, N_2, N_3 \le 50,000$), a frequency map is highly efficient and easier to implement.

1. **Frequency Counting**: By using a `std::map<int, int>`, we can store each ID as a key and its frequency as the value. 
2. **Automatic Sorting**: A key property of `std::map` in C++ is that it stores elements in sorted order based on the keys. This satisfies the problem requirement to output the IDs in ascending order without needing an explicit sorting step at the end.
3. **Filtering**: After populating the map with all IDs from the three lists, we simply iterate through the map and collect all keys where the associated value (frequency) is $\ge 2$.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$, where $N = N_1 + N_2 + N_3$. Inserting into a `std::map` takes logarithmic time relative to the number of unique elements. Given $N \approx 150,000$, this comfortably passes within the time limits.
- **Space Complexity**: $O(N)$, as we store the voter IDs in the map. In the worst case, all IDs are unique, requiring space proportional to the total number of inputs.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given three sorted lists of voter IDs. We need to find IDs that appear
 * in at least two of the three lists.
 * 
 * Approach:
 * Use a std::map<int, int> to count the occurrences of each ID. 
 * std::map automatically keeps the keys sorted, which simplifies the 
 * requirement to output IDs in ascending order.
 */

int main() {
    // Fast I/O for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n1, n2, n3;
    if (!(cin >> n1 >> n2 >> n3)) return 0;

    // Map to store frequency of each ID
    map<int, int> counts;

    int total = n1 + n2 + n3;
    for (int i = 0; i < total; ++i) {
        int id;
        cin >> id;
        counts[id]++;
    }

    // Collect IDs that appear in at least 2 lists
    vector<int> result;
    for (auto const& [id, count] : counts) {
        if (count >= 2) {
            result.push_back(id);
        }
    }

    // Output the count of such IDs
    cout << result.size() << "\n";
    
    // Output the IDs in ascending order
    for (int id : result) {
        cout << id << "\n";
    }

    return 0;
}
```