#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * You pay 100 dollars. The cost is X.
 * The change owed to you is (100 - X).
 * The driver only has 10 dollar bills.
 * The driver can only return multiples of 10 that are less than or equal to (100 - X).
 * 
 * Let R = 100 - X be the amount owed.
 * We need to find the largest multiple of 10 such that 10 * k <= R.
 * This is equivalent to floor(R / 10) * 10.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int x;
        cin >> x;
        
        // Calculate the amount the driver owes back
        int change_owed = 100 - x;
        
        // The driver can only return multiples of 10.
        // We use integer division to find how many 10-dollar bills fit.
        int bills = change_owed / 10;
        
        // The total amount returned is bills * 10
        int result = bills * 10;
        
        cout << result << "\n";
    }
    
    return 0;
}