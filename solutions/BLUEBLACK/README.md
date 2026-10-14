# [Blue and Black Pens (BLUEBLACK)](https://www.codechef.com/problems/BLUEBLACK)

- **Difficulty Rating**: -1
- **Solved in**: 3 attempt(s)

## Problem Summary
The goal is to determine the minimum cost to acquire a specific set of pens. You are given the cost of a blue pen ($A$) and a black pen ($B$). You have two ways to satisfy the requirement:
1. Purchase 3 blue pens.
2. Purchase 1 blue pen and 1 black pen.

The objective is to output the minimum cost between these two options.

## Intuition & Mathematical Observation
The problem presents a simple decision-making scenario based on two mutually exclusive options. 

- **Option 1**: The total cost is $3 \times A$.
- **Option 2**: The total cost is $A + B$.

By comparing these two values using the `min()` function, we can determine the most cost-effective strategy. Since the constraints are small and the logic is constant-time, a direct comparison is the most efficient approach.

## Complexity Analysis
- **Time Complexity**: $O(1)$ — The solution performs a constant number of arithmetic operations and a single comparison, regardless of the input values.
- **Space Complexity**: $O(1)$ — We only use a few integer variables to store the costs, requiring constant auxiliary space.

## Solution Code

```cpp
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    // Optimize I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int A, B;
    // Read the costs of blue (A) and black (B) pens
    if (!(cin >> A >> B)) return 0;

    // Option 1: 3 blue pens
    int cost1 = 3 * A;
    
    // Option 2: 1 blue pen and 1 black pen
    int cost2 = A + B;

    // Output the minimum of the two options
    cout << min(cost1, cost2) << endl;

    return 0;
}
```