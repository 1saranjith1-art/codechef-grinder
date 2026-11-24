#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * For each element A_i, we generate two numbers: (A_i - k) and (A_i + k).
 * Let these be x and y.
 * x = A_i - k
 * y = A_i + k
 * Adding these two equations: x + y = 2 * A_i.
 * This implies that the sum of the two numbers generated from any A_i must be even.
 * 
 * If we have a set of 2N numbers, we need to partition them into N pairs (x_i, y_i)
 * such that for each pair, (x_i + y_i) is even.
 * 
 * A sum (x + y) is even if and only if:
 * 1. Both x and y are even.
 * 2. Both x and y are odd.
 * 
 * This means that in the sequence B, the number of odd integers must be even.
 * If the count of odd numbers is even, we can always pair them up (odd with odd, 
 * even with even) to satisfy the condition.
 * 
 * Therefore, the condition for the sequence B to be valid is simply that the 
 * count of odd numbers in B must be even.
 */

void solve() {
    int N;
    cin >> N;
    int odd_count = 0;
    for (int i = 0; i < 2 * N; ++i) {
        int b;
        cin >> b;
        // Check if the number is odd. 
        // Note: In C++, -1 % 2 is -1, so we check (b % 2 != 0)
        if (b % 2 != 0) {
            odd_count++;
        }
    }

    if (odd_count % 2 == 0) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}