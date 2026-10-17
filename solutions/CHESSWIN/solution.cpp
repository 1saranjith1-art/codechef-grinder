#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Current score is A : B, where A < B.
 * We want to play X more matches such that we can end up with a score (A + X) : B
 * where (A + X) > B.
 * 
 * To minimize X, we assume we win all X remaining matches.
 * The condition is A + X > B.
 * Therefore, X > B - A.
 * Since X must be an integer, the minimum X is (B - A) + 1.
 * 
 * Example 1: 0 1
 * X > 1 - 0 => X > 1. Min X = 2.
 * Example 2: 2 4
 * X > 4 - 2 => X > 2. Min X = 3.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // The problem description implies a single test case per run based on the 
    // input format description, but standard competitive programming practice 
    // often involves multiple test cases. The prompt asks to handle multiple 
    // test cases if provided.
    
    int A, B;
    if (cin >> A >> B) {
        int result = (B - A) + 1;
        cout << result << "\n";
    }

    return 0;
}