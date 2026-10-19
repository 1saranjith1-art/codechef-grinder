# [Join States (JOINSTATE)](https://www.codechef.com/problems/JOINSTATE)

- **Difficulty Rating**: 1043
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given an array $A$ of $N$ integers and a threshold value $M$. We need to partition the array into the maximum number of contiguous subarrays such that the sum of each subarray is at least $M$.

## Intuition & Mathematical Observation
The problem asks for the maximum number of partitions, which suggests a **Greedy Approach**. 

1. **Greedy Strategy**: We iterate through the array, maintaining a `current_sum`. As soon as `current_sum` reaches or exceeds $M$, we have successfully formed a valid state. We increment our counter and reset the `current_sum` to $0$ to begin forming the next state.
2. **Why this works**: By finalizing a state as soon as it hits the threshold $M$, we leave the maximum number of remaining elements available to form subsequent states. Delaying the formation of a state would only consume more elements than necessary, potentially reducing the total count of states.
3. **Edge Cases**: The problem guarantees that the total sum of the array is at least $M$. Any elements remaining after the last valid state is formed are effectively "absorbed" into the last state, ensuring the condition is met for all partitions.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we perform a single pass through the array of size $N$.
- **Space Complexity**: $O(N)$ to store the input array (though this could be optimized to $O(1)$ by processing elements on the fly).

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given an array A of size N and a threshold M.
 * We need to partition the array into the maximum number of contiguous subarrays
 * such that the sum of each subarray is at least M.
 * 
 * Greedy Strategy:
 * Iterate through the array and maintain a running sum.
 * As soon as the running sum reaches or exceeds M, we have formed a valid state.
 * We increment our count of states and reset the running sum to 0.
 */

void solve() {
    int N;
    long long M;
    cin >> N >> M;
    
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    int state_count = 0;
    long long current_sum = 0;
    
    for (int i = 0; i < N; ++i) {
        current_sum += A[i];
        
        // If the current accumulated sum meets the requirement, 
        // we finalize this state and start a new one.
        if (current_sum >= M) {
            state_count++;
            current_sum = 0;
        }
    }
    
    cout << state_count << "\n";
}

int main() {
    // Fast I/O setup
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