# [Chef and IPC Certificates (IPCCERT)](https://www.codechef.com/problems/IPCCERT)

- **Difficulty Rating**: 922
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef is organizing an IPC certification program. There are $N$ students, and each student has attended $K$ lectures. For each student, we are given the duration of each of the $K$ lectures they attended and the number of questions they asked during the program. A student is eligible for a certificate if and only if:
1. The total duration of all lectures they watched is at least $M$.
2. The number of questions they asked is at most 10.

We need to count how many students satisfy both conditions.

## Intuition & Mathematical Observation
The problem requires us to process each student individually. For every student:
1. We calculate the sum of the durations of the $K$ lectures.
2. We compare this sum against the threshold $M$.
3. We compare the number of questions asked against the threshold of 10.

Since the constraints are $N, K \le 1000$, a simple nested loop approach will perform at most $10^6$ operations, which is well within the typical time limit of 1 second (the problem allows 3 seconds). Using `long long` for the total time is a safe practice to prevent potential overflow, although with the given constraints ($1000 \times 1000 = 10^6$), a standard `int` would technically suffice.

## Complexity Analysis
- **Time Complexity**: $O(N \times K)$, where $N$ is the number of students and $K$ is the number of lectures per student. We iterate through every lecture duration once.
- **Space Complexity**: $O(1)$, as we only store the running sum and current lecture duration, requiring constant extra space regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given N students, each watched K lectures.
 * For each student, we have the duration of K lectures and the number of questions asked (Q_i).
 * Criteria for certificate:
 * 1. Total time watched >= M
 * 2. Questions asked <= 10
 * 
 * Constraints:
 * N, K <= 1000
 * M <= 10^6
 * T_{i,j} <= 1000
 * Q_i <= 10^6
 * 
 * Total time per student can be up to 1000 * 1000 = 1,000,000.
 * This fits within a standard 32-bit integer, but using long long is safer 
 * and good practice in competitive programming to avoid overflow.
 * Time complexity: O(N * K), which is 10^6 operations, well within the 3s limit.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    long long M;
    int K;

    if (!(cin >> N >> M >> K)) return 0;

    int eligible_count = 0;

    for (int i = 0; i < N; ++i) {
        long long total_time = 0;
        for (int j = 0; j < K; ++j) {
            int time_watched;
            cin >> time_watched;
            total_time += time_watched;
        }
        
        int questions;
        cin >> questions;

        // Check criteria
        if (total_time >= M && questions <= 10) {
            eligible_count++;
        }
    }

    cout << eligible_count << "\n";

    return 0;
}
```