#include <iostream>

/**
 * Problem Analysis:
 * Let the difference be D = a - b.
 * Operation 1: a' = a + d, b' = b + d - 1 => (a' - b') = (a - b) + 1
 * Operation 2: a' = a + d - 1, b' = b + d => (a' - b') = (a - b) - 1
 * 
 * In each step, we can change the difference (a - b) by exactly 1.
 * Since we can perform this operation any number of times, we can 
 * always bridge any initial difference to reach 0.
 * 
 * Thus, the answer is always "YES" for any positive integers a and b.
 */

using namespace std;

int main() {
    // Optimize I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long a, b;
        cin >> a >> b;
        // As derived, it is always possible to make a equal to b.
        cout << "YES" << "\n";
    }

    return 0;
}