#include <iostream>
#include <cmath>

using namespace std;

/**
 * Problem: INTMTCH
 * The problem asks to determine if the absolute difference between two integers X and Y
 * is at most 2.
 * 
 * Input Format: The input contains two space-separated integers X and Y.
 * There is no mention of a test case count T.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x, y;
    // Read the two integers directly as per the problem description
    if (cin >> x >> y) {
        // Calculate absolute difference
        int diff = abs(x - y);

        // Check if the difference is at most 2
        if (diff <= 2) {
            cout << "Interesting" << endl;
        } else {
            cout << "Boring" << endl;
        }
    }

    return 0;
}