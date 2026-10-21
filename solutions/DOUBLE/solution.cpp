#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A "double string" is a string of even length where the first half equals the second half.
 * This means a double string is formed by taking some characters and repeating them twice.
 * If we have a string of length N, we want to find the maximum length of a double string
 * that can be formed by rearranging and removing characters.
 * 
 * Let the double string be S + S. The length is 2 * |S|.
 * To form S + S, we need two of every character present in S.
 * If the original string has length N, we can use at most N characters.
 * Since the double string must have an even length (2 * |S|), and we want to maximize 
 * the number of characters used, we look at the parity of N.
 * 
 * If N is even, we can potentially use all N characters to form a double string 
 * (e.g., if N=4, we can form "aabb" -> "abab").
 * If N is odd, we must remove at least one character to make the total length even.
 * Thus, for an odd N, the maximum length is N - 1.
 * 
 * In both cases, the answer is simply the largest even number less than or equal to N.
 * This is equivalent to (N / 2) * 2, or simply N if N is even and N-1 if N is odd.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n;
        cin >> n;
        
        // If N is even, the answer is N.
        // If N is odd, the answer is N - 1.
        if (n % 2 == 0) {
            cout << n << "\n";
        } else {
            cout << n - 1 << "\n";
        }
    }
    return 0;
}