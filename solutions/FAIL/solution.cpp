#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef takes N tests. We need to check if the average score after every test i
 * (where i ranges from 1 to N) is at least 40.
 * The average after i tests is (sum of A_1 to A_i) / i.
 * The condition (sum / i) >= 40 is equivalent to (sum >= 40 * i).
 * 
 * Time Complexity: O(N) per test case, O(T * N) total.
 * Space Complexity: O(N) to store the array, or O(1) if processed on the fly.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        cin >> n;
        
        long long current_sum = 0;
        bool possible = true;
        
        for (int i = 1; i <= n; ++i) {
            int a;
            cin >> a;
            current_sum += a;
            
            // Check if average is at least 40
            // Average = current_sum / i
            // Condition: current_sum / i >= 40  =>  current_sum >= 40 * i
            if (current_sum < 40LL * i) {
                possible = false;
            }
        }
        
        if (possible) {
            cout << "Yes" << "\n";
        } else {
            cout << "No" << "\n";
        }
    }
    
    return 0;
}