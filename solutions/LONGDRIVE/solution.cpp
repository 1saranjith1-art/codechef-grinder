#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Initial distance covered in 10 hours = 10 * X.
 * Let 'n' be the number of additional hours.
 * In these 'n' hours, the maximum distance Chef can cover is 100 * n.
 * The new average speed must be at least Y.
 * (10 * X + distance_in_n_hours) / (10 + n) >= Y
 * 10 * X + distance_in_n_hours >= Y * (10 + n)
 * distance_in_n_hours >= Y * (10 + n) - 10 * X
 * 
 * Since the maximum distance in 'n' hours is 100 * n, we need:
 * 100 * n >= Y * (10 + n) - 10 * X
 * 100 * n >= 10 * Y + n * Y - 10 * X
 * n * (100 - Y) >= 10 * (Y - X)
 * n >= (10 * (Y - X)) / (100 - Y)
 * 
 * Since 'n' must be an integer, we take the ceiling of the division.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long X, Y;
        cin >> X >> Y;

        // We need to find the smallest integer n such that:
        // n * (100 - Y) >= 10 * (Y - X)
        // Let numerator = 10 * (Y - X)
        // Let denominator = 100 - Y
        // n = ceil(numerator / denominator)
        
        long long numerator = 10 * (Y - X);
        long long denominator = 100 - Y;
        
        // Ceiling division for positive integers: (a + b - 1) / b
        long long n = (numerator + denominator - 1) / denominator;
        
        cout << n << "\n";
    }

    return 0;
}