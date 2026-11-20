#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let S be the sum of all banknotes.
 * The maximum number of sweets the customer can buy is K = floor(S / X).
 * 
 * The condition for an "adequate" customer is:
 * If you remove any single banknote A_i, the remaining sum (S - A_i) 
 * must be less than K * X.
 * 
 * If (S - A_i) < K * X for all i, then the customer is adequate.
 * Since K = floor(S / X), we know S = K * X + R, where 0 <= R < X.
 * The condition (S - A_i) < K * X is equivalent to:
 * (K * X + R - A_i) < K * X
 * R - A_i < 0
 * R < A_i
 * 
 * This must hold for all banknotes A_i. 
 * Specifically, it must hold for the smallest banknote, min(A_i).
 * If R < min(A_i), then the customer is adequate and the answer is K.
 * If R >= min(A_i), then removing the smallest banknote still leaves 
 * enough money to buy K sweets, meaning the customer is inadequate.
 */

void solve() {
    int N, X;
    cin >> N >> X;
    
    vector<int> A(N);
    long long sum = 0;
    int min_val = 101;
    
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        sum += A[i];
        if (A[i] < min_val) {
            min_val = A[i];
        }
    }
    
    long long K = sum / X;
    long long remainder = sum % X;
    
    // If the remainder is greater than or equal to the smallest banknote,
    // we can remove that banknote and still afford K sweets.
    if (remainder >= min_val) {
        cout << -1 << "\n";
    } else {
        cout << K << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}