#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need a permutation of [1, ..., N] such that P[i] * P[i+1] is not a perfect square.
 * A simple strategy is to output the numbers in reverse order: N, N-1, ..., 1.
 * Let's check if this works for small N.
 * For N=2: 2, 1. 2*1=2 (not square). OK.
 * For N=3: 3, 2, 1. 3*2=6, 2*1=2. OK.
 * For N=4: 4, 3, 2, 1. 4*3=12, 3*2=6, 2*1=2. OK.
 * 
 * Does this always work?
 * If P[i] * P[i+1] = k^2, then P[i] and P[i+1] must share the same "square-free part".
 * For example, if P[i] = a * x^2 and P[i+1] = a * y^2, then P[i] * P[i+1] = a^2 * (xy)^2 = (axy)^2.
 * In the sequence N, N-1, ..., 1, we only fail if two adjacent numbers have the same square-free part.
 * However, for N <= 500, the reverse sequence is a very strong heuristic.
 * If we encounter a case where N, N-1, ..., 1 fails, we can simply shuffle the array or 
 * use a different construction. Given the constraints and the nature of the problem, 
 * the reverse sequence is sufficient for almost all cases.
 */

void solve() {
    int N;
    cin >> N;
    
    // The reverse sequence N, N-1, ..., 1 works for all N <= 500.
    // We can verify this: if N, N-1, ..., 1 fails, we can try a random shuffle.
    vector<int> p(N);
    for (int i = 0; i < N; ++i) {
        p[i] = N - i;
    }
    
    auto is_square = [](long long n) {
        long long root = round(sqrt(n));
        return root * root == n;
    };
    
    bool ok = true;
    for (int i = 0; i < N - 1; ++i) {
        if (is_square((long long)p[i] * p[i + 1])) {
            ok = false;
            break;
        }
    }
    
    // If reverse doesn't work, use a random shuffle
    if (!ok) {
        iota(p.begin(), p.end(), 1);
        mt19937 rng(1337);
        while (true) {
            shuffle(p.begin(), p.end(), rng);
            bool possible = true;
            for (int i = 0; i < N - 1; ++i) {
                if (is_square((long long)p[i] * p[i + 1])) {
                    possible = false;
                    break;
                }
            }
            if (possible) break;
        }
    }
    
    for (int i = 0; i < N; ++i) {
        cout << p[i] << (i == N - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}