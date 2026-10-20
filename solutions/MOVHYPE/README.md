# [Movie Hype (MOVHYPE)](https://www.codechef.com/problems/MOVHYPE)

- **Difficulty Rating**: 921
- **Solved in**: 1 attempt(s)

## Problem Summary
In a theater with $2N+1$ seats, people are sitting in all odd-numbered seats ($1, 3, 5, \dots, 2N+1$). The even-numbered seats ($2, 4, \dots, 2N$) are empty. Each person has a "hype level." The loudness of an empty seat is defined as the maximum hype level of the two people sitting immediately adjacent to it. We need to find the **minimum** loudness among all $N$ empty seats.

## Intuition & Mathematical Observation
- The people are sitting at positions $1, 3, 5, \dots, 2N+1$. Let their hype levels be stored in an array $A$ of size $N+1$, where $A[0]$ is the hype at seat 1, $A[1]$ is the hype at seat 3, and so on.
- An empty seat at position $2i$ (where $i$ ranges from $1$ to $N$) is located between the person at seat $2i-1$ and the person at seat $2i+1$.
- In our 0-indexed array $A$, the empty seat $i$ (1-indexed) is adjacent to the people at $A[i-1]$ and $A[i]$.
- The loudness of the $i$-th empty seat is $\max(A[i-1], A[i])$.
- To find the minimum loudness, we simply iterate through all adjacent pairs in the array $A$, calculate the maximum of each pair, and track the global minimum of these maximums.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we perform a single pass through the array of $N+1$ elements to calculate the loudness of each empty seat.
- **Space Complexity**: $O(N)$ to store the hype levels of the $N+1$ people.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The theater has 2N+1 seats.
 * Occupied seats are 1, 3, 5, ..., 2N+1.
 * Empty seats are 2, 4, 6, ..., 2N.
 * 
 * Let A_0, A_1, ..., A_N be the hype levels of people in seats 1, 3, 5, ..., 2N+1.
 * The i-th empty seat (1-indexed, i from 1 to N) is between A[i-1] and A[i].
 * Loudness = max(A[i-1], A[i]).
 * We need to find the minimum of these values.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    
    vector<long long> A(N + 1);
    for (int i = 0; i <= N; ++i) {
        cin >> A[i];
    }
    
    // Initialize min_loudness with a value larger than any possible A_i
    // Constraints state A_i <= 100, so 200 is a safe upper bound.
    long long min_loudness = 200; 
    
    // There are N empty seats.
    // The i-th empty seat (0-indexed loop) is between A[i] and A[i+1].
    for (int i = 0; i < N; ++i) {
        long long current_loudness = max(A[i], A[i + 1]);
        if (current_loudness < min_loudness) {
            min_loudness = current_loudness;
        }
    }
    
    cout << min_loudness << "\n";
}

int main() {
    // Fast I/O
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