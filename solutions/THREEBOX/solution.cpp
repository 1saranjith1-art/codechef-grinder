#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have three boxes A, B, C and bags of size D.
 * Constraints: A <= B <= C <= D.
 * We want to minimize the number of bags.
 * 
 * Logic:
 * 1. If A + B + C <= D, we can fit all in 1 bag.
 * 2. If not, check if we can fit two boxes in one bag:
 *    - Can we fit (A + B) <= D and C <= D? Yes, 2 bags.
 *    - Can we fit (A + C) <= D and B <= D? Yes, 2 bags.
 *    - Can we fit (B + C) <= D and A <= D? Yes, 2 bags.
 *    Since A <= B <= C, if any pair fits, it will be A+B <= D.
 * 3. If no pair fits, we need 3 bags.
 */

void solve() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    // Case 1: All three fit in one bag
    if (A + B + C <= D) {
        cout << 1 << "\n";
    }
    // Case 2: Check if two boxes can fit in one bag
    // Since A <= B <= C, the smallest sum of two is A + B.
    // If A + B <= D, we can put A and B in one bag, and C in another.
    else if (A + B <= D) {
        cout << 2 << "\n";
    }
    // Case 3: Otherwise, each box needs its own bag
    else {
        cout << 3 << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}