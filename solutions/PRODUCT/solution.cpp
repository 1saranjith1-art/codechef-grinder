#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given B and C. We need to find the minimum positive integer A such that:
 * (A * B) % C == 0
 * 
 * This is equivalent to:
 * A * B = k * C for some integer k.
 * A = (k * C) / B
 * 
 * To minimize A, we need to find the smallest k such that (k * C) is divisible by B.
 * Let g = gcd(B, C).
 * Then B = g * b' and C = g * c', where gcd(b', c') = 1.
 * The condition (A * g * b') % (g * c') == 0 simplifies to:
 * (A * b') % c' == 0
 * 
 * Since gcd(b', c') = 1, for (A * b') to be divisible by c', A must be divisible by c'.
 * The smallest positive integer A is therefore c'.
 * 
 * c' = C / gcd(B, C).
 * 
 * Time Complexity: O(log(min(B, C))) per test case due to GCD calculation.
 * Space Complexity: O(1).
 */

long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long b, c;
        cin >> b >> c;
        
        // Calculate gcd of B and C
        long long common = gcd(b, c);
        
        // The result is C / gcd(B, C)
        long long result = c / common;
        
        cout << result << "\n";
    }
    
    return 0;
}