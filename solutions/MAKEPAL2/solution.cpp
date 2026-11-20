#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given a binary string S of length N. We can delete at most floor(N/2) characters.
 * We need to obtain a palindrome.
 * 
 * Strategy:
 * Count the number of '0's and '1's in the string.
 * Since we can delete up to half the characters, we can simply keep all characters 
 * of the majority digit. If there are more '0's than '1's, we can form a string 
 * consisting only of '0's. If there are more '1's, we can form a string of '1's.
 * 
 * Let count0 be the number of '0's and count1 be the number of '1's.
 * If count0 >= count1, we can output a string of '0's of length count0.
 * Since we delete count1 characters, and count1 <= floor(N/2) (because count0 + count1 = N),
 * this is always a valid operation.
 * 
 * Example: S = 1011 (N=4). count0 = 1, count1 = 3.
 * Output: 111 (length 3). We deleted one '0'. 1 <= floor(4/2) = 2. Valid.
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    int count0 = 0;
    int count1 = 0;
    for (char c : S) {
        if (c == '0') count0++;
        else count1++;
    }

    if (count0 >= count1) {
        for (int i = 0; i < count0; ++i) {
            cout << '0';
        }
    } else {
        for (int i = 0; i < count1; ++i) {
            cout << '1';
        }
    }
    cout << "\n";
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