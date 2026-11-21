# [Distance between two nodes (NODESDIST)](https://www.codechef.com/problems/NODESDIST)

- **Difficulty Rating**: 1250
- **Solved in**: 2 attempt(s)

## Problem Summary
Given a tree with $N$ nodes, we are asked to find the shortest distance between two specific nodes, $u$ and $v$. The distance is defined as the number of edges on the unique simple path between the two nodes.

## Intuition & Mathematical Observation
In any tree, the distance between two nodes $u$ and $v$ can be calculated using their depths and their **Lowest Common Ancestor (LCA)**. The formula is:
$$\text{dist}(u, v) = \text{depth}(u) + \text{depth}(v) - 2 \times \text{depth}(\text{LCA}(u, v))$$

To implement this efficiently:
1. **Preprocessing**: We use **Binary Lifting** to find the LCA in $O(\log N)$ time. We precompute an `up[N][LOGN]` table where `up[u][i]` stores the $2^i$-th ancestor of node $u$.
2. **Traversal**: We use an iterative BFS to calculate the `depth` of each node and the immediate parent (`up[u][0]`) to avoid stack overflow issues that might occur with deep recursion in DFS.
3. **LCA Calculation**:
   - Bring both nodes to the same depth.
   - Lift both nodes simultaneously until they are just below the LCA.
   - The parent of the resulting nodes is the LCA.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$
  - BFS traversal takes $O(N)$.
  - Precomputing the binary lifting table takes $O(N \log N)$.
  - Finding the LCA takes $O(\log N)$.
- **Space Complexity**: $O(N \log N)$
  - Required to store the `up` table of size $N \times \log N$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The distance between two nodes u and v in a tree is:
 * dist(u, v) = depth(u) + depth(v) - 2 * depth(LCA(u, v))
 * 
 * To avoid stack overflow on deep trees, we use an iterative BFS 
 * to compute depths and the first ancestor (up[u][0]).
 */

const int MAXN = 100005;
const int LOGN = 18;

vector<int> adj[MAXN];
int up[MAXN][LOGN];
int depth[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, u_target, v_target;
    if (!(cin >> N >> u_target >> v_target)) return 0;

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // BFS to compute depths and immediate parents
    // Initialize up table with root (1)
    for(int i = 0; i < LOGN; i++) up[1][i] = 1;
    
    queue<int> q;
    q.push(1);
    depth[1] = 0;
    vector<bool> visited(N + 1, false);
    visited[1] = true;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int v : adj[u]){
            if(!visited[v]){
                visited[v] = true;
                depth[v] = depth[u] + 1;
                up[v][0] = u;
                q.push(v);
            }
        }
    }

    // Binary Lifting Preprocessing
    for (int i = 1; i < LOGN; i++) {
        for (int u = 1; u <= N; u++) {
            up[u][i] = up[up[u][i - 1]][i - 1];
        }
    }

    auto get_lca = [&](int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);
        for (int i = LOGN - 1; i >= 0; i--) {
            if (depth[u] - (1 << i) >= depth[v]) {
                u = up[u][i];
            }
        }
        if (u == v) return u;
        for (int i = LOGN - 1; i >= 0; i--) {
            if (up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }
        return up[u][0];
    };

    int lca = get_lca(u_target, v_target);
    cout << depth[u_target] + depth[v_target] - 2 * depth[lca] << "\n";

    return 0;
}
```