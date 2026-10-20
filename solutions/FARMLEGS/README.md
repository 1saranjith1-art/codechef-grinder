# [Legs on a Farm (FARMLEGS)](https://www.codechef.com/problems/FARMLEGS)

- **Difficulty Rating**: 709
- **Solved in**: 1 attempt(s)

## Problem Summary
Given the total number of legs $N$ on a farm containing only cows (4 legs each) and chickens (2 legs each), find the minimum number of animals required to account for exactly $N$ legs.

## Intuition & Mathematical Observation
To minimize the total number of animals ($C + H$), we should prioritize the animal with the most legs. Since a cow has 4 legs and a chicken has 2, replacing two chickens (4 legs total) with one cow (4 legs total) reduces the total animal count by 1. Therefore, to minimize the total count, we must maximize the number of cows.

1. **Maximize Cows**: Since each cow contributes 4 legs, the maximum number of cows we can have is $C = \lfloor N / 4 \rfloor$.
2. **Account for Remaining Legs**: After placing the maximum number of cows, the remaining legs must be covered by chickens. The remaining legs are $N - (C \times 4)$. Since each chicken has 2 legs, the number of chickens is $H = (N - 4C) / 2$.
3. **Total Animals**: The result is simply $C + H$.

This greedy approach ensures that we use the largest "leg-capacity" animals first, resulting in the fewest number of animals overall.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves only basic arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and results.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * To minimize the total number of animals (C + H) for a fixed number of legs N,
 * we should maximize the number of cows (4 legs) because they contribute 
 * more legs per animal than chickens (2 legs).
 */

int main() {
    // Fast I/O for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        
        // Step 1: Maximize cows to minimize total animal count
        long long max_cows = n / 4;
        
        // Step 2: Calculate remaining legs and assign to chickens
        long long remaining_legs = n - (max_cows * 4);
        long long chickens = remaining_legs / 2;
        
        // Step 3: Output the total number of animals
        cout << (max_cows + chickens) << "\n";
    }

    return 0;
}
```