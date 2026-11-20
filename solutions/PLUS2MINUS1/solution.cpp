#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let Y be the number of moves.
 * We start at X = 0.
 * Moves: +2 or -1.
 * 
 * Let 'a' be the number of +2 moves and 'b' be the number of -1 moves.
 * Total moves: a + b <= Y.
 * Final value: X = 2a - b.
 * 
 * For a fixed number of moves k (where 0 <= k <= Y):
 * We want to find the range of possible values of X.
 * If we perform exactly k moves, let 'a' moves be +2 and 'k-a' moves be -1.
 * X = 2a - (k - a) = 3a - k, where 0 <= a <= k.
 * The possible values for a fixed k are:
 * a = 0: X = -k
 * a = 1: X = -k + 3
 * a = 2: X = -k + 6
 * ...
 * a = k: X = 2k
 * 
 * The set of values for a fixed k is {-k, -k+3, -k+6, ..., 2k}.
 * The number of distinct values for a fixed k is (k + 1).
 * 
 * Let S_k be the set of reachable values using exactly k moves.
 * We want the size of the union of S_0, S_1, ..., S_Y.
 * 
 * Observing the pattern:
 * Y=0: {0} -> size 1
 * Y=1: {0} U {-1, 2} = {-1, 0, 2} -> size 3
 * Y=2: {-1, 0, 2} U {-2, 1, 4} = {-2, -1, 0, 1, 2, 4} -> size 6
 * Y=3: {-2, -1, 0, 1, 2, 4} U {-3, 0, 3, 6} = {-3, -2, -1, 0, 1, 2, 3, 4, 6} -> size 9
 * 
 * The number of distinct values for Y is 3*Y if Y > 0, and 1 if Y = 0.
 * Let's verify:
 * Y=0: 1
 * Y=1: 3*1 = 3
 * Y=2: 3*2 = 6
 * Y=3: 3*3 = 9
 * 
 * The pattern is 3*Y for Y > 0, and 1 for Y = 0.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long y;
        cin >> y;
        if (y == 0) {
            cout << 1 << "\n";
        } else {
            cout << 3 * y << "\n";
        }
    }
    return 0;
}