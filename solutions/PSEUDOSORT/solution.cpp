#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem Analysis:
 * An array is pseudo-sorted if it is already sorted or can be sorted by one swap.
 * 1. Find the first index i such that A[i] > A[i+1].
 * 2. If no such index exists, the array is already sorted -> YES.
 * 3. If such an index exists, swap A[i] and A[i+1].
 * 4. Check if the array is now sorted. If yes -> YES, else -> NO.
 */

bool is_sorted_array(const vector<long long>& a) {
    for (size_t i = 0; i + 1 < a.size(); ++i) {
        if (a[i] > a[i + 1]) return false;
    }
    return true;
}

void solve() {
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Find the first inversion
    int first_inversion = -1;
    for (int i = 0; i < N - 1; ++i) {
        if (A[i] > A[i + 1]) {
            first_inversion = i;
            break;
        }
    }

    // If already sorted
    if (first_inversion == -1) {
        cout << "YES" << endl;
        return;
    }

    // Perform the swap at the first inversion
    swap(A[first_inversion], A[first_inversion + 1]);

    // Check if sorted after swap
    if (is_sorted_array(A)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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