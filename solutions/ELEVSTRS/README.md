# [From heaven to earth (ELEVSTRS)](https://www.codechef.com/problems/ELEVSTRS)

- **Difficulty Rating**: 1066
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef lives on the $N$-th floor of a building. He needs to reach the ground floor. He has two options:
1. **Stairs**: The distance he travels is the diagonal of the staircase. Since the height of each floor is 1 unit and the base is 1 unit, the diagonal distance for one floor is $\sqrt{1^2 + 1^2} = \sqrt{2}$. For $N$ floors, the total distance is $N \times \sqrt{2}$.
2. **Elevator**: The elevator starts at the ground floor, travels to the $N$-th floor to pick up Chef, and then returns to the ground floor. The total distance traveled by the elevator is $N + N = 2N$.

Given the velocities $V_1$ (stairs) and $V_2$ (elevator), determine which option is faster.

## Intuition & Mathematical Observation
To determine the faster option, we calculate the time taken for each:
*   **Time for Stairs ($T_s$):** $\frac{\text{Distance}}{\text{Velocity}} = \frac{N \sqrt{2}}{V_1}$
*   **Time for Elevator ($T_e$):** $\frac{\text{Distance}}{\text{Velocity}} = \frac{2N}{V_2}$

We compare $T_s$ and $T_e$. If $T_s < T_e$, the stairs are faster; otherwise, the elevator is faster. Since the constraints for $N, V_1, V_2$ are small (up to 100), we can perform this comparison using `double` precision floating-point arithmetic without worrying about precision errors.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. Each test case involves a constant number of arithmetic operations.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and calculated times.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * 1. Stairs:
 *    - Distance = N * sqrt(2)
 *    - Velocity = V1
 *    - Time_stairs = (N * sqrt(2)) / V1
 * 
 * 2. Elevator:
 *    - The elevator starts at ground, goes to N (distance N), then back to ground (distance N).
 *    - Total distance = 2 * N
 *    - Velocity = V2
 *    - Time_elevator = (2 * N) / V2
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        double n, v1, v2;
        cin >> n >> v1 >> v2;

        // Time taken for stairs: distance / velocity
        double time_stairs = (n * sqrt(2.0)) / v1;
        
        // Time taken for elevator: 
        // Elevator travels N meters up (to get Chef) and N meters down (to ground)
        double time_elevator = (2.0 * n) / v2;

        if (time_stairs < time_elevator) {
            cout << "Stairs" << "\n";
        } else {
            cout << "Elevator" << "\n";
        }
    }

    return 0;
}
```