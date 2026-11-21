#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given a sequence A of N positive integers and an integer K.
 * We want the sum of the elements to be divisible by K.
 * We can change any element to any positive integer.
 * 
 * Let S be the sum of the initial elements.
 * If S % K == 0, we need 0 operations.
 * If S % K != 0, we can change exactly one element.
 * Why? Because if we change one element A_i to A_i', the new sum S' = S - A_i + A_i'.
 * We want S' % K == 0, which means A_i' = K * m - (S - A_i).
 * Since we can choose any positive integer A_i', we can always find a positive 
 * integer A_i' such that the sum becomes divisible by K, provided we have at 
 * least one element to change.
 * 
 * Therefore, if the sum is already divisible by K, the answer is 0.
 * Otherwise, the answer is 1.
 */

void solve() {
    int N;
    long long K;
    cin >> N >> K;
    
    long long sum = 0;
    for (int i = 0; i < N; ++i) {
        long long a;
        cin >> a;
        sum += a;
    }
    
    if (sum % K == 0) {
        cout << 0 << "\n";
    } else {
        cout << 1 << "\n";
    }
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}