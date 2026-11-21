#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The operation allows us to flip the signs of any two elements simultaneously.
 * This means the parity of the number of negative signs in the array remains invariant.
 * 
 * If the number of negative elements is even, we can flip all of them to positive
 * using the operation repeatedly (flip two negatives at a time).
 * If the number of negative elements is odd, we will always be left with at least
 * one negative element after performing the operations. To maximize the sum,
 * we should ensure that the element with the smallest absolute value is the one
 * that remains negative.
 * 
 * Algorithm:
 * 1. Count the number of negative elements.
 * 2. Keep track of the minimum absolute value among all elements in the array.
 * 3. Calculate the sum of absolute values of all elements.
 * 4. If the count of negative elements is even, the answer is the sum of absolute values.
 * 5. If the count of negative elements is odd, the answer is (sum of absolute values) - 2 * (minimum absolute value).
 *    (Subtracting 2 * min_abs effectively turns the positive min_abs into negative).
 */

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    int negative_count = 0;
    long long min_abs = 200000; // Larger than any possible |A_i|
    long long sum_abs = 0;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] < 0) {
            negative_count++;
        }
        long long abs_val = abs(a[i]);
        sum_abs += abs_val;
        if (abs_val < min_abs) {
            min_abs = abs_val;
        }
    }

    if (negative_count % 2 == 0) {
        cout << sum_abs << "\n";
    } else {
        cout << sum_abs - 2 * min_abs << "\n";
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