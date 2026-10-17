#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Each weapon type behaves independently. For a specific weapon type j, 
 * if a contestant has it (1) and another contestant has it (1), they destroy each other.
 * This is equivalent to the XOR operation.
 * 
 * If we have two contestants with weapon sets represented as binary strings A and B,
 * after a battle, the new set of weapons is A XOR B.
 * Since XOR is associative and commutative, the final set of weapons held by the 
 * winner is simply the XOR sum of all initial weapon strings.
 * 
 * The number of weapons the winner has is the number of set bits (1s) in the 
 * resulting XOR sum string.
 */

void solve() {
    int N;
    cin >> N;
    
    // We use an integer to store the 10-bit representation of the weapons.
    // Since the string length is 10, an integer is sufficient.
    int result = 0;
    
    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        
        // Convert binary string to integer
        int current_weapons = 0;
        for (int j = 0; j < 10; ++j) {
            if (s[j] == '1') {
                current_weapons |= (1 << (9 - j));
            }
        }
        
        // XOR the current contestant's weapons into the running total
        result ^= current_weapons;
    }
    
    // Count the number of set bits in the final result
    int count = 0;
    for (int i = 0; i < 10; ++i) {
        if ((result >> i) & 1) {
            count++;
        }
    }
    
    cout << count << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}