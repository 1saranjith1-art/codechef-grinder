# [Fair Elections (FAIRELCT)](https://www.codechef.com/problems/FAIRELCT)

- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary
John Jackson and Jack Johnson are competing in an election. John has $N$ packs of votes, and Jack has $M$ packs of votes. John wants to win the election, which means he must have a strictly greater sum of votes than Jack. You are allowed to swap any pack of votes from John with any pack of votes from Jack. The goal is to find the minimum number of swaps required to make John's total votes greater than Jack's, or determine if it is impossible.

## Intuition & Mathematical Observation
To maximize John's total votes while minimizing the number of swaps, we should always aim to replace the smallest values in John's collection with the largest values available in Jack's collection.

1. **Initial Check**: If John's total votes are already greater than Jack's, the answer is 0.
2. **Greedy Strategy**: 
   - Sort John's vote packs in **ascending order** (to identify the smallest packs to give away).
   - Sort Jack's vote packs in **descending order** (to identify the largest packs to take).
   - Iteratively swap the smallest pack from John with the largest pack from Jack.
   - A swap is only beneficial if the pack John gives away is smaller than the pack he receives. If at any point the smallest pack John has is greater than or equal to the largest pack Jack has, no further swaps will increase John's total relative to Jack's.
3. **Termination**: If John's sum becomes greater than Jack's, we output the number of swaps performed. If we exhaust all possible beneficial swaps and John still does not have more votes, it is impossible, and we output -1.

## Complexity Analysis
- **Time Complexity**: $O(N \log N + M \log M)$ due to the sorting of both arrays. The subsequent iteration runs in $O(\min(N, M))$, which is dominated by the sorting step.
- **Space Complexity**: $O(N + M)$ to store the vote packs for both candidates.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * John Jackson (A) wants to have strictly more votes than Jack Johnson (B).
 * To maximize John's total votes with the minimum number of swaps, we should 
 * always swap the smallest pack from A with the largest pack from B, 
 * provided the smallest pack from A is indeed smaller than the largest pack from B.
 */

void solve() {
    int N, M;
    cin >> N >> M;
    vector<long long> A(N), B(M);
    long long sumA = 0, sumB = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        sumA += A[i];
    }
    for (int i = 0; i < M; ++i) {
        cin >> B[i];
        sumB += B[i];
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<long long>());

    int swaps = 0;
    int i = 0;
    while (sumA <= sumB) {
        // If we run out of packs to swap or the smallest A is not smaller than largest B
        if (i >= N || i >= M || A[i] >= B[i]) {
            cout << -1 << "\n";
            return;
        }
        
        // Perform swap
        sumA = sumA - A[i] + B[i];
        sumB = sumB - B[i] + A[i];
        swaps++;
        i++;
    }

    cout << swaps << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
```