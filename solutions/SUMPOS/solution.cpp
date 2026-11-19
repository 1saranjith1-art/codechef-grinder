#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Given three integers x, y, and z, we need to check if:
 * x = y + z OR y = x + z OR z = x + y.
 * 
 * Since the constraints are small (1 <= x, y, z <= 1000), 
 * standard integer types are sufficient, but using long long 
 * is a safe practice in competitive programming to prevent overflow.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long x, y, z;
        cin >> x >> y >> z;
        
        // Check the three possible conditions
        if ((x == y + z) || (y == x + z) || (z == x + y)) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}