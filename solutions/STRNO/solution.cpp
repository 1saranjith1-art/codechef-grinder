#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let the prime factorization of A be p1^a1 * p2^a2 * ... * pk^ak.
 * The number of divisors X is given by (a1 + 1) * (a2 + 1) * ... * (ak + 1).
 * The number of prime factors K is the number of distinct primes, which is k.
 * 
 * We are given X and K. We need to check if there exists an integer A such that:
 * 1. The number of prime factors (distinct) is exactly K.
 * 2. The total number of divisors is exactly X.
 * 
 * Since we want to check if it's possible to have exactly K prime factors, 
 * the smallest number with K prime factors is the product of the first K primes.
 * However, the constraint is on the number of divisors.
 * 
 * If we choose A = p1 * p2 * ... * pK (where pi are distinct primes), 
 * the number of divisors is 2^K.
 * To increase the number of divisors while keeping K prime factors, we can increase 
 * the exponents of these primes.
 * 
 * The condition is:
 * 1. K must not exceed the total number of prime factors (counting multiplicity).
 *    Even with the smallest exponents (all 1), the number of divisors is 2^K.
 *    So, 2^K <= X must hold.
 * 2. The maximum number of prime factors (with multiplicity) for a given X is 
 *    found by factoring X into the maximum number of factors > 1.
 *    Actually, the condition is simpler:
 *    We need to find if there exist a1, a2, ..., aK >= 1 such that 
 *    (a1+1)*(a2+1)*...*(aK+1) = X.
 *    This is possible if and only if the number of prime factors of X (counting multiplicity)
 *    is at least K.
 */

int countPrimeFactors(int n) {
    int count = 0;
    for (int i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            count++;
            n /= i;
        }
    }
    if (n > 1) count++;
    return count;
}

void solve() {
    long long X, K;
    cin >> X >> K;

    // If K is greater than the number of prime factors of X, 
    // it's impossible to have K distinct prime factors.
    // Also, if K is very large, 2^K might exceed X.
    // For K > 30, 2^K > 10^9, so K cannot be larger than ~30.
    if (K > 30) {
        cout << 0 << "\n";
        return;
    }

    // The number of prime factors (counting multiplicity) of A must be at least K.
    // Let X = (a1+1)(a2+1)...(ak+1). Since ai >= 1, each (ai+1) >= 2.
    // The number of prime factors of X (counting multiplicity) is the maximum 
    // number of factors we can split X into.
    if (countPrimeFactors(X) >= K) {
        cout << 1 << "\n";
    } else {
        cout << 0 << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}