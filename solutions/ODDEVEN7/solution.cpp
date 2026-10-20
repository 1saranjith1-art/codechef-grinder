#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * An array is "good" if parities alternate (Odd, Even, Odd, Even... or Even, Odd, Even, Odd...).
 * To maximize the size of a subset that can be rearranged into a good array,
 * we need to count how many odd numbers (cntOdd) and how many even numbers (cntEven)
 * we have in the original array.
 * 
 * In an alternating sequence:
 * - If we have equal numbers of odds and evens (cntOdd == cntEven), 
 *   we can use all of them: size = cntOdd + cntEven.
 * - If they are not equal, the maximum difference between the count of odds and 
 *   evens in an alternating sequence is 1.
 *   For example, if we have 5 odds and 2 evens, we can pick 3 odds and 2 evens 
 *   to form a sequence of length 5 (O, E, O, E, O).
 *   The formula is: 2 * min(cntOdd, cntEven) + (cntOdd != cntEven ? 1 : 0).
 */

void solve() {
    int N;
    cin >> N;
    int cntOdd = 0;
    int cntEven = 0;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        if (a % 2 == 0) {
            cntEven++;
        } else {
            cntOdd++;
        }
    }

    if (cntOdd == cntEven) {
        cout << cntOdd + cntEven << "\n";
    } else {
        // We take the smaller count and match it with the larger count.
        // The maximum length is 2 * min + 1.
        cout << 2 * min(cntOdd, cntEven) + 1 << "\n";
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