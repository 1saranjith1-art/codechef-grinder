#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * For each recipe:
 * Original price = p
 * Discount percentage = x
 * 
 * Step 1: Increase price by x%
 * New price = p * (1 + x/100)
 * 
 * Step 2: Apply discount of x% on the new price
 * Final price = (p * (1 + x/100)) * (1 - x/100)
 * Final price = p * (1 + x/100) * (1 - x/100)
 * Using difference of squares: (a+b)(a-b) = a^2 - b^2
 * Final price = p * (1 - (x/100)^2)
 * 
 * Loss per unit = Original price - Final price
 * Loss per unit = p - p * (1 - (x/100)^2)
 * Loss per unit = p * (x/100)^2
 * 
 * Total loss for this type = quantity * Loss per unit
 * Total loss = quantity * p * (x/100)^2
 * 
 * Complexity:
 * Time: O(N) per test case, O(T*N) total. With N=10^5 and T=10, this is 10^6 operations, well within 2s.
 * Space: O(1) auxiliary space.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int n;
        cin >> n;
        
        double total_loss = 0.0;
        for (int i = 0; i < n; ++i) {
            double p, q, x;
            cin >> p >> q >> x;
            
            // Loss per unit = p * (x/100)^2
            double loss_per_unit = p * (x / 100.0) * (x / 100.0);
            total_loss += (loss_per_unit * q);
        }
        
        // Output with required precision
        cout << fixed << setprecision(9) << total_loss << "\n";
    }
    
    return 0;
}