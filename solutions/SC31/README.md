# [Weapon Value (SC31)](https://www.codechef.com/problems/SC31)

- **Difficulty Rating**: 1204
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given $N$ contestants, each possessing a set of 10 types of weapons, represented as a binary string of length 10. When two contestants fight, they both lose any weapon type that they both possess (i.e., if both have a '1' at the same position, it becomes '0'). If only one has it, they keep it. We need to find the total number of weapons remaining after all $N$ contestants have fought each other.

## Intuition & Mathematical Observation
The interaction described is exactly the definition of the **XOR (exclusive OR)** operation. 
- If two contestants have the same weapon (1 XOR 1), it results in 0 (the weapon is destroyed).
- If one has it and the other doesn't (1 XOR 0 or 0 XOR 1), it results in 1 (the weapon remains).
- If neither has it (0 XOR 0), it results in 0.

Since the XOR operation is both **associative** and **commutative**, the order in which the contestants fight does not matter. The final state of the weapons is simply the XOR sum of all $N$ binary strings. After computing the final XOR sum, we count the number of set bits (1s) to determine the total number of weapons remaining.

## Complexity Analysis
- **Time Complexity**: $O(N \times L)$, where $N$ is the number of contestants and $L$ is the length of the binary string (which is 10). Given the constraints, this is effectively $O(N)$.
- **Space Complexity**: $O(1)$, as we only store the running XOR sum and a few temporary variables, regardless of the input size.

## Solution Code

```cpp
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
```