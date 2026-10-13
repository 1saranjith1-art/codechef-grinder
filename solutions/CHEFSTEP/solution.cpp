#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef can only walk in steps of length K.
 * A distance D_i is traversable if and only if D_i is divisible by K.
 * Mathematically, D_i % K == 0.
 * 
 * Constraints:
 * T <= 1000, N <= 1000
 * K, D_i <= 10^9
 * Since K and D_i can be up to 10^9, we should use long long to prevent 
 * any potential overflow issues, although standard int is sufficient for 
 * 10^9, long long is safer practice in competitive programming.
 * 
 * Time Complexity: O(T * N)
 * Space Complexity: O(1) (excluding input storage)
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int n;
        long long k;
        cin >> n >> k;
        
        string result = "";
        for (int i = 0; i < n; ++i) {
            long long d;
            cin >> d;
            
            // Check if distance is divisible by step length K
            if (d % k == 0) {
                result += '1';
            } else {
                result += '0';
            }
        }
        
        cout << result << "\n";
    }
    
    return 0;
}