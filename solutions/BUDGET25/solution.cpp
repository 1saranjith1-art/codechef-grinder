#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N sectors with initial budgets A_i. We want to maximize the number of sectors
 * that have at least X.
 * 
 * Strategy:
 * 1. Identify sectors that already have >= X. These sectors contribute to our count.
 * 2. Any sector with A_i > X has a surplus of (A_i - X). This surplus can be used
 *    to help sectors that have A_i < X.
 * 3. To maximize the number of sectors that reach X, we should greedily use the 
 *    surplus from the largest available budgets to fill the deficits of the 
 *    sectors that are closest to X (or simply any sectors that are < X).
 * 4. Sort the array A.
 * 5. Count how many sectors already have >= X.
 * 6. For the remaining sectors (those < X), try to fill them using the surplus 
 *    from the sectors that have > X, starting from the largest surplus.
 */

void solve() {
    int N;
    long long X;
    cin >> N >> X;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    int count = 0;
    int left = 0;
    int right = N - 1;

    // First, count all sectors that already meet the requirement
    // and move the 'right' pointer to the largest elements.
    while (right >= 0 && A[right] >= X) {
        count++;
        right--;
    }

    // Now, 'right' points to the largest element < X (if any),
    // and 'left' points to the smallest element.
    // We use the surplus from the sectors we already counted (those > X)
    // to fill the deficits of the sectors < X.
    // Actually, it's simpler:
    // We have 'count' sectors that are >= X.
    // We have 'right + 1' sectors that are < X.
    // We can use the surplus from the 'count' sectors to fill the 'right + 1' sectors.
    
    long long surplus = 0;
    for (int i = right + 1; i < N; ++i) {
        surplus += (A[i] - X);
    }

    int filled = 0;
    for (int i = right; i >= 0; --i) {
        if (surplus >= (X - A[i])) {
            surplus -= (X - A[i]);
            filled++;
        } else {
            break;
        }
    }

    cout << count + filled << "\n";
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