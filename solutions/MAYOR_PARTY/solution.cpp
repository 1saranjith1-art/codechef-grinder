#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have three regions A, B, and C with populations P_A, P_B, and P_C.
 * Conflict rules:
 * - Region B cannot be with A.
 * - Region B cannot be with C.
 * 
 * Possible valid combinations:
 * 1. Invite people from A and C: Total = P_A + P_C
 * 2. Invite people from B: Total = P_B
 * 
 * We want to maximize the number of people invited.
 * Therefore, the answer is max(P_A + P_C, P_B).
 * 
 * Constraints:
 * T <= 1000
 * P_A, P_B, P_C <= 1000
 * The sum will not exceed 2000, so 'int' is sufficient.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int pa, pb, pc;
        cin >> pa >> pb >> pc;
        
        // Calculate the two possible scenarios
        int option1 = pa + pc;
        int option2 = pb;
        
        // Output the maximum of the two
        cout << max(option1, option2) << "\n";
    }
    
    return 0;
}