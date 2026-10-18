#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let x = min(A, B), y = min(B, C), z = min(C, A).
 * Without loss of generality, assume A <= B <= C.
 * Then:
 * min(A, B) = A = x
 * min(B, C) = B = y
 * min(C, A) = A = z
 * 
 * This implies x = z.
 * If we sort the three given values as s1 <= s2 <= s3:
 * The condition for a valid tuple is that the two smallest values must be equal.
 * 
 * Proof:
 * If A <= B <= C:
 * min(A, B) = A
 * min(B, C) = B
 * min(C, A) = A
 * The set of values is {A, B, A}.
 * The two smallest values are A and A, which are equal.
 * 
 * If we have values {v1, v2, v3} sorted such that v1 <= v2 <= v3:
 * We need v1 == v2.
 */

void solve() {
    int arr[3];
    cin >> arr[0] >> arr[1] >> arr[2];
    sort(arr, arr + 3);
    
    // After sorting, the two smallest values are arr[0] and arr[1].
    // They must be equal for a valid tuple (A, B, C) to exist.
    if (arr[0] == arr[1]) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
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