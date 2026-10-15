#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have two strings A and B of length N, consisting of 'a's and 'b's.
 * We can shuffle A and B independently. We want to know if we can arrange them
 * such that A[i] != B[i] for all i.
 * 
 * Let countA_a be the number of 'a's in A, countA_b be the number of 'b's in A.
 * Let countB_a be the number of 'a's in B, countB_b be the number of 'b's in B.
 * 
 * To satisfy A[i] != B[i], at every index i:
 * If A[i] = 'a', then B[i] must be 'b'.
 * If A[i] = 'b', then B[i] must be 'a'.
 * 
 * This implies that for every 'a' in A, we must have a corresponding 'b' in B.
 * For every 'b' in A, we must have a corresponding 'a' in B.
 * 
 * Therefore, the number of 'a's in A must equal the number of 'b's in B,
 * and the number of 'b's in A must equal the number of 'a's in B.
 * 
 * Let's check:
 * countA_a = countB_b
 * countA_b = countB_a
 * 
 * Since countA_a + countA_b = N and countB_a + countB_b = N,
 * these two conditions are actually equivalent. If countA_a == countB_b,
 * then N - countA_a = N - countB_b => countA_b = countB_a.
 * 
 * So the condition is simply: countA_a == countB_b.
 */

void solve() {
    int N;
    cin >> N;
    string A, B;
    cin >> A >> B;

    int countA_a = 0;
    for (char c : A) {
        if (c == 'a') countA_a++;
    }

    int countB_b = 0;
    for (char c : B) {
        if (c == 'b') countB_b++;
    }

    if (countA_a == countB_b) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}