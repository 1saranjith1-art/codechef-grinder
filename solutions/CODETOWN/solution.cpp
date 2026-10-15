#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The rule states we can transition from T1 to T2 if:
 * 1. A consonant is replaced by a consonant.
 * 2. A vowel is replaced by a vowel.
 * 
 * This implies that the "vowel-ness" or "consonant-ness" of each position 
 * in the string must be identical between the starting string S and the 
 * target string "CODETOWN".
 * 
 * Target: "CODETOWN"
 * Positions:
 * 0: C (Consonant)
 * 1: O (Vowel)
 * 2: D (Consonant)
 * 3: E (Vowel)
 * 4: T (Consonant)
 * 5: O (Vowel)
 * 6: W (Consonant)
 * 7: N (Consonant)
 * 
 * Pattern: C V C V C V C C
 * 
 * We simply need to check if the input string S follows this exact pattern.
 */

bool isVowel(char c) {
    return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

void solve() {
    string s;
    cin >> s;
    string target = "CODETOWN";
    
    bool possible = true;
    for (int i = 0; i < 8; ++i) {
        // Check if the type (vowel/consonant) matches at each position
        if (isVowel(s[i]) != isVowel(target[i])) {
            possible = false;
            break;
        }
    }
    
    if (possible) {
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