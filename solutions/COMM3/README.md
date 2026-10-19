# [Three Way Communications (COMM3)](https://www.codechef.com/problems/COMM3)

- **Difficulty Rating**: 1083
- **Solved in**: 2 attempt(s)

## Problem Summary
We are given the coordinates of three transceivers (Headquarters, Chef, and Soumyadeep) and a maximum communication range $R$. Two transceivers can communicate if the Euclidean distance between them is less than or equal to $R$. We need to determine if all three transceivers can communicate with each other, either directly or through intermediate transceivers (i.e., the graph of transceivers must be connected).

## Intuition & Mathematical Observation
1. **Distance Calculation**: The Euclidean distance between two points $(x_1, y_1)$ and $(x_2, y_2)$ is $\sqrt{(x_1-x_2)^2 + (y_1-y_2)^2}$. To avoid floating-point precision issues, we compare the squared distance $(x_1-x_2)^2 + (y_1-y_2)^2$ with $R^2$.
2. **Graph Connectivity**: We have 3 nodes. For 3 nodes to be connected in a graph:
   - If we have 0 or 1 edge, the graph is disconnected.
   - If we have 2 edges, the nodes form a path (e.g., A-B-C), which is connected.
   - If we have 3 edges, the nodes form a triangle, which is connected.
3. **Conclusion**: The condition for the three transceivers to be connected is simply that **at least two** of the three possible pairs must have a distance $\le R$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case. We perform a constant number of arithmetic operations (3 distance calculations and comparisons).
- **Space Complexity**: $O(1)$. We only store the coordinates of the three points and a few integer variables.

## Solution Code

```cpp
#include <iostream>
#include <vector>

using namespace std;

/**
 * Problem: COMM3 - Communicating Transceivers
 * Logic: We have 3 points. They can communicate if the graph formed by 
 * edges (where distance <= R) is connected. 
 * For 3 nodes, this is true if at least 2 edges exist.
 */

long long distSq(long long x1, long long y1, long long x2, long long y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

void solve() {
    long long R;
    cin >> R;
    long long R2 = R * R;
    
    long long x[3], y[3];
    for (int i = 0; i < 3; ++i) {
        cin >> x[i] >> y[i];
    }
    
    int edges = 0;
    // Check distance between (0,1), (1,2), and (0,2)
    if (distSq(x[0], y[0], x[1], y[1]) <= R2) edges++;
    if (distSq(x[1], y[1], x[2], y[2]) <= R2) edges++;
    if (distSq(x[0], y[0], x[2], y[2]) <= R2) edges++;
    
    // If 2 or 3 edges exist, they are connected.
    if (edges >= 2) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
}

int main() {
    // Optimize I/O operations
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