# [Exun Handshake (EXSHAKE)](https://www.codechef.com/problems/EXSHAKE)

- **Difficulty Rating**: 815
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given $N$ groups, each with a specific number of people $A_i$. We want to invite a subset of these groups such that the total number of handshakes among all invited people does not exceed $M$. The number of handshakes for $P$ people is calculated by the formula $\frac{P(P-1)}{2}$. The goal is to maximize the total number of groups invited.

## Intuition & Mathematical Observation
To maximize the number of groups invited, we should prioritize adding groups with the smallest number of people first. This is a classic **Greedy Approach**:
1. By sorting the group sizes in non-decreasing order, we ensure that we add the smallest possible increments to our total population $P$.
2. Keeping $P$ as small as possible for as long as possible allows us to include more groups before the handshake count $\frac{P(P-1)}{2}$ exceeds the limit $M$.
3. We maintain a running sum of people and check the handshake condition at each step. If adding the next smallest group causes the handshake count to exceed $M$, we stop, as adding any larger group would also violate the condition.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ due to the sorting step. The subsequent iteration through the array takes $O(N)$, making the overall complexity dominated by the sort.
- **Space Complexity**: $O(N)$ to store the group sizes in a vector.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N groups with sizes A_i.
 * If we invite a set of groups with total people P, the number of handshakes is P*(P-1)/2.
 * We want to maximize the number of groups invited such that P*(P-1)/2 <= M.
 * 
 * Since we want to maximize the number of groups, we should always pick the groups 
 * with the smallest number of people first. This is a greedy approach.
 */

void solve() {
    int N;
    long long M;
    cin >> N >> M;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Sort to pick smallest groups first to maximize the count
    sort(A.begin(), A.end());

    long long current_people = 0;
    int groups_invited = 0;

    for (int i = 0; i < N; ++i) {
        long long next_people = current_people + A[i];
        long long handshakes = (next_people * (next_people - 1)) / 2;

        if (handshakes <= M) {
            current_people = next_people;
            groups_invited++;
        } else {
            // Cannot add more groups
            break;
        }
    }

    cout << groups_invited << "\n";
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