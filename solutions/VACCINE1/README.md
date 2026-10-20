# [Vaccine Production (VACCINE1)](https://www.codechef.com/problems/VACCINE1)

- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given two companies, A and B, that produce vaccines. Company A starts producing $V_1$ vaccines per day starting from day $D_1$. Company B starts producing $V_2$ vaccines per day starting from day $D_2$. We need to determine the earliest day $d$ such that the cumulative number of vaccines produced by both companies reaches or exceeds a target value $P$.

## Intuition & Mathematical Observation
Since the constraints for $D_1, D_2, V_1, V_2$ are small (up to 100) and $P$ is up to 1000, a direct simulation is highly efficient. 

We maintain a counter for the current `day` and a running total of `total_vaccines`. We increment the day one by one, checking if the current day has reached the start date for each company. If `day >= D1`, we add $V_1$ to the total; if `day >= D2`, we add $V_2$ to the total. We stop the loop as soon as `total_vaccines` is greater than or equal to $P$.

Given the constraints, the maximum number of days will be relatively small, ensuring the simulation completes well within the time limit.

## Complexity Analysis
- **Time Complexity**: $O(P / \min(V_1, V_2) + \max(D_1, D_2))$. In the worst case, this is roughly $O(P)$, which is well within the limits for $P \le 1000$.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to track the state.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have two companies A and B.
 * Company A starts producing V1 vaccines per day from day D1.
 * Company B starts producing V2 vaccines per day from day D2.
 * We need to find the smallest day 'd' such that total vaccines >= P.
 * 
 * Since the constraints are small (D, V <= 100, P <= 1000), we can simulate 
 * day by day or use a simple loop. The maximum number of days will not exceed 
 * 1000 + max(D1, D2), which is well within the time limit.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int D1, V1, D2, V2, P;
    if (!(cin >> D1 >> V1 >> D2 >> V2 >> P)) return 0;

    int total_vaccines = 0;
    int day = 0;

    // Simulate day by day until total_vaccines >= P
    while (total_vaccines < P) {
        day++;
        
        // Add production from Company A if day >= D1
        if (day >= D1) {
            total_vaccines += V1;
        }
        
        // Add production from Company B if day >= D2
        if (day >= D2) {
            total_vaccines += V2;
        }
    }

    cout << day << "\n";

    return 0;
}
```