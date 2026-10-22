# [Mode of Frequencies (MODEFREQ)](https://www.codechef.com/problems/MODEFREQ)

- **Difficulty Rating**: 1234
- **Solved in**: 2 attempt(s)

## Problem Summary
Given an array of $N$ integers where each integer is between 1 and 10,000, we need to find the "mode" of the frequencies of these integers. Specifically:
1. Count how many times each number appears in the array.
2. Count how many numbers share the same frequency.
3. Identify the frequency that occurs most often among the numbers. If there is a tie, choose the smallest frequency.

## Intuition & Mathematical Observation
The problem requires a two-step frequency counting process:
1. **Primary Frequency**: We first count the occurrences of each number $A_i$ using a frequency array (or hash map). Since the values are bounded by 10,000, a fixed-size array `counts[10001]` is efficient.
2. **Secondary Frequency (Frequency of Frequencies)**: We then count how many numbers have a specific frequency $f$. We store this in a second array `freq_of_freq`.
3. **Finding the Mode**: We iterate through the `freq_of_freq` array. The index $f$ that holds the maximum value in `freq_of_freq` is our answer. By iterating from $1$ to $N$, we naturally handle the tie-breaking condition (choosing the smallest frequency) because we only update the result if we find a strictly greater occurrence count.

## Complexity Analysis
- **Time Complexity**: $O(N + M)$, where $N$ is the number of elements in the array and $M$ is the range of the input values (10,000). We iterate through the input once and then through the frequency arrays.
- **Space Complexity**: $O(N + M)$, where $M$ is the range of values (for `counts`) and $N$ is the maximum possible frequency (for `freq_of_freq`).

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Optimized approach:
 * 1. Use a frequency array (or vector) to count occurrences of each number.
 * 2. Since A_i can be up to 10000, an array of size 10001 is sufficient.
 * 3. Count how many numbers have a specific frequency.
 * 4. Find the mode of these frequencies.
 */

void solve() {
    int n;
    if (!(cin >> n)) return;
    
    // Using a vector for frequency counting (A_i <= 10000)
    vector<int> counts(10001, 0);
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        counts[a]++;
    }
    
    // freq_of_freq[f] = how many numbers appear exactly f times
    // The maximum possible frequency is N.
    vector<int> freq_of_freq(n + 1, 0);
    for (int i = 1; i <= 10000; ++i) {
        if (counts[i] > 0) {
            freq_of_freq[counts[i]]++;
        }
    }
    
    int max_occurrence = -1;
    int result_freq = -1;
    
    // Iterate through possible frequencies (1 to N)
    // We want the smallest frequency if there's a tie, 
    // so we iterate in increasing order.
    for (int f = 1; f <= n; ++f) {
        if (freq_of_freq[f] > max_occurrence) {
            max_occurrence = freq_of_freq[f];
            result_freq = f;
        }
    }
    
    cout << result_freq << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}
```