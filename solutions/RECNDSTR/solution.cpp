#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let S be a string of length n.
 * L(V) = S means V[1...n-1] + V[0] = S[0...n-1].
 * This implies V[i] = S[(i+1) % n].
 * R(V) = S means V[n-1] + V[0...n-2] = S[0...n-1].
 * This implies V[i] = S[(i-1+n) % n].
 * 
 * Combining these, we need to check if the left shift of S is equal to the right shift of S.
 * Let L_S be the left shift of S: L_S = S[1...n-1] + S[0]
 * Let R_S be the right shift of S: R_S = S[n-1] + S[0...n-2]
 * If L_S == R_S, then V exists (specifically V = L_S = R_S).
 */

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    
    if (n <= 2) {
        cout << "YES" << "\n";
        return;
    }
    
    // Left shift: move first char to end
    string l_s = s.substr(1) + s[0];
    
    // Right shift: move last char to beginning
    string r_s = s[n - 1] + s.substr(0, n - 1);
    
    if (l_s == r_s) {
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