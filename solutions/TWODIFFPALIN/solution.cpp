#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to construct two different binary strings that are palindromes, 
 * each containing exactly A zeros and B ones.
 * 
 * A palindrome is determined by its first ceil(length/2) characters.
 * If A is odd and B is odd, we cannot construct two different palindromes.
 * Why?
 * If A and B are both odd, the total length (A+B) is even.
 * In a palindrome of even length, every character must appear an even number of times.
 * But here, A and B are odd, so it's impossible to form even one palindrome.
 * Wait, let's re-check:
 * If A=1, B=1: Length 2. Palindromes: "01" (no), "10" (no). Only "01" is not a palindrome.
 * If A=3, B=3: Length 6. Palindromes: "011110" (no), "001100" (no).
 * Actually, the condition for a palindrome to exist with A zeros and B ones is:
 * At most one of A or B can be odd.
 * 
 * If A is even and B is even:
 * We can always construct at least two. Example: 0...01...11...10...0 and 1...10...00...01...1.
 * If one is odd and one is even:
 * We can always construct at least two.
 * 
 * The only case where we cannot construct two different palindromes is when:
 * 1. A is odd AND B is odd (Total length is even, but we need both A and B to be even for a palindrome).
 *    Actually, if A is odd and B is odd, we can't even form ONE palindrome.
 * 2. If A=1 and B=1, we can't form any palindrome.
 * 
 * General rule:
 * If A is odd and B is odd, it's impossible to form even one palindrome.
 * If A=1 or B=1, we can only form one unique palindrome (e.g., A=1, B=2 -> "101").
 * So, if (A % 2 != 0 && B % 2 != 0) OR (A == 1 || B == 1), the answer is No.
 * Otherwise, Yes.
 */

void solve() {
    int A, B;
    cin >> A >> B;

    // If both are odd, we cannot form a palindrome at all.
    // If either A or B is 1, we can only form one unique palindrome.
    if ((A % 2 != 0 && B % 2 != 0) || (A == 1 || B == 1)) {
        cout << "No" << "\n";
    } else {
        cout << "Yes" << "\n";
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