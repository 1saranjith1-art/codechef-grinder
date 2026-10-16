# [Seating (SEATING7)](https://www.codechef.com/problems/SEATING7)

- **Difficulty Rating**: 913
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given $N$ total seats, indexed from $1$ to $N$. Initially, $M$ seats are already occupied. Then, $K$ people arrive one by one. Each person follows a simple rule: they always choose the **lowest-numbered available seat**. We need to determine which seat each of the $K$ people will occupy.

## Intuition & Mathematical Observation
Since the constraints on $N$ are small ($N \le 100$), we do not need a complex data structure like a Segment Tree or a Min-Priority Queue. A simple simulation approach is sufficient:

1.  **Tracking State**: We can use a boolean array (or `std::vector<bool>`) of size $N+1$ to keep track of which seats are currently occupied.
2.  **Simulation**: For each of the $K$ people, we perform a linear scan from seat $1$ to $N$. The first index `i` where `occupied[i]` is `false` is the seat the person will take.
3.  **Update**: Once a person takes a seat, we mark that seat as `true` in our boolean array so that subsequent people do not choose it.

This greedy approach works perfectly because the problem explicitly states that people arrive one by one and always pick the smallest available index.

## Complexity Analysis
- **Time Complexity**: $O(T \times (M + K \times N))$, where $T$ is the number of test cases. Given $N, K \le 100$, the total operations per test case are roughly $10^4$, which easily fits within the 1-second time limit.
- **Space Complexity**: $O(N)$ to store the occupancy status of the seats.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N seats, M are occupied. K people arrive one by one.
 * Each person takes the lowest numbered available seat.
 * Since N is small (up to 100), we can use a boolean array to track
 * occupied seats and iterate to find the lowest available seat for each of the K people.
 * 
 * Time Complexity: O(T * (N + K * N)) which is O(T * N^2).
 * Given N=100 and T=100, this is ~10^6 operations, well within the 1s limit.
 */

void solve() {
    int N, M, K;
    if (!(cin >> N >> M >> K)) return;

    vector<bool> occupied(N + 1, false);
    for (int i = 0; i < M; ++i) {
        int seat;
        cin >> seat;
        occupied[seat] = true;
    }

    vector<int> result;
    for (int i = 0; i < K; ++i) {
        for (int seat = 1; seat <= N; ++seat) {
            if (!occupied[seat]) {
                occupied[seat] = true;
                result.push_back(seat);
                break;
            }
        }
    }

    for (int i = 0; i < K; ++i) {
        cout << result[i] << (i == K - 1 ? "" : " ");
    }
    cout << "\n";
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