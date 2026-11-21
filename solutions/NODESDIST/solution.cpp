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