# [Christmas Gifts (WRAPGIFTS)](https://www.codechef.com/problems/WRAPGIFTS)

- **Difficulty Rating**: 574
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has a rectangular gift box with dimensions $H$, $L$, and $W$. He has a fixed amount of wrapping paper, specifically $1000$ square centimeters. The goal is to determine the maximum number of complete gift boxes Chef can wrap given these dimensions.

## Intuition & Mathematical Observation
1.  **Surface Area Calculation**: The surface area of a rectangular prism (box) is calculated using the formula:
    $$\text{Surface Area} = 2 \times (H \times L + L \times W + W \times H)$$
2.  **Constraint Handling**: We are given $1000$ units of paper. Since we need to find the number of *complete* gifts, we perform integer division of the total paper by the surface area of a single box:
    $$\text{Max Gifts} = \lfloor \frac{1000}{\text{Surface Area}} \rfloor$$
3.  **Data Types**: Given the constraints ($1 \le H, L, W \le 10$), the surface area will range between $6$ and $600$. Standard `long long` (or even `int`) is sufficient to store these values without overflow.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the dimensions and the calculated area.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The surface area of a rectangular box with dimensions H, L, and W is given by:
 * Surface Area = 2 * (H*L + L*W + W*H)
 * 
 * Chef has a total of 1000 square centimeters of wrapping paper.
 * To find the maximum number of complete gifts, we divide the total area (1000)
 * by the surface area of one gift and take the floor of the result.
 */

int main() {
    // Optimize I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long h, l, w;
        cin >> h >> l >> w;
        
        // Calculate surface area of one gift box
        long long surface_area = 2 * (h * l + l * w + w * h);
        
        // Total available paper is 1000
        long long total_paper = 1000;
        
        // Calculate maximum number of complete gifts using integer division
        long long max_gifts = total_paper / surface_area;
        
        cout << max_gifts << "\n";
    }
    
    return 0;
}
```