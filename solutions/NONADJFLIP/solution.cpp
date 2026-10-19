#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We want to turn all '1's into '0's.
 * 1. If the string is already all '0's, 0 operations are needed.
 * 2. If there are no adjacent '1's, we can flip all '1's in a single operation 
 *    because no two '1's are adjacent (the set of indices of '1's is valid).
 * 3. If there are adjacent '1's, we cannot flip them all in one operation.
 *    - Can we do it in 2 operations? Yes.
 *      In the first operation, we can pick a set of indices such that we break 
 *      the adjacency of '1's. For example, if we have "11", we can flip the first 
 *      '1' to get "01", then flip the remaining '1's in the second operation.
 *      More generally, any string can be cleared in at most 2 operations.
 *      We just need to check if any two '1's are adjacent. If they are, we check 
 *      if they are "odd-distanced" or "even-distanced" to see if 2 operations 
 *      are sufficient. Actually, for this problem, 2 is always sufficient if 
 *      there are adjacent '1's.
 * 
 * Logic:
 * - If string is all '0's: return 0.
 * - If no two '1's are adjacent: return 1.
 * - If there are adjacent '1's:
 *   - Check if we can do it in 2 operations.
 *   - If we have "11", we can flip index 0 (making it 01), then flip index 1.
 *   - The only constraint is the adjacency. 2 operations are always enough 
 *     because we can pick all odd indices in one op and all even in another.
 *   - Wait, is there a case where 2 is not enough? No.
 *   - Is there a case where 1 is enough even with adjacent '1's? No, by definition.
 *   - So: 0 if no '1's, 1 if no adjacent '1's, 2 if there exists at least one pair of adjacent '1's.
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    bool has_one = false;
    bool has_adjacent_ones = false;

    for (int i = 0; i < N; ++i) {
        if (S[i] == '1') {
            has_one = true;
            if (i > 0 && S[i - 1] == '1') {
                has_adjacent_ones = true;
            }
        }
    }

    if (!has_one) {
        cout << 0 << "\n";
    } else if (has_adjacent_ones) {
        // Check if we can do it in 2 operations.
        // If there are adjacent 1s, we need to see if we can split them.
        // Actually, for any string with adjacent 1s, 2 operations are always sufficient.
        // We just need to check if there's a parity issue.
        // If there's an adjacent pair at indices (i, i+1), they have different parities.
        // This allows us to split them.
        bool odd_adjacent = false;
        for (int i = 0; i < N - 1; ++i) {
            if (S[i] == '1' && S[i + 1] == '1') {
                if (i % 2 != (i + 1) % 2) {
                    // This is always true for adjacent indices
                    odd_adjacent = true;
                    break;
                }
            }
        }
        
        if (odd_adjacent) {
            cout << 2 << "\n";
        } else {
            // This case is actually covered by the logic above.
            // If we have "11", we can flip index i, then index i+1.
            cout << 2 << "\n";
        }
    } else {
        cout << 1 << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}