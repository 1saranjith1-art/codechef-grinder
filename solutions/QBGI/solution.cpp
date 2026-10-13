#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to iterate through the string S and maintain the count of boys (B) and girls (G).
 * Let 'b' be the number of boys and 'g' be the number of girls currently inside.
 * The condition for closing the gate is: b > 2 * g.
 * We need to count how many people enter before this condition is met.
 * 
 * Logic:
 * Iterate through the string character by character.
 * For each character:
 * 1. Increment the respective count (b or g).
 * 2. Check if b > 2 * g.
 * 3. If true, the current person is the last one allowed to enter (or the one that triggers the closure).
 *    Wait, the problem says "as soon as the number of boys... exceeds twice... the security closes the entrance."
 *    This implies the person who caused the condition b > 2*g to become true is the last person allowed in.
 *    Wait, let's re-read: "The security closes the entrance." This means the person who caused the violation
 *    is the last one to enter.
 * 
 * Example 1: GBGBBBBG
 * 1. G: b=0, g=1. 0 > 2*1 (False)
 * 2. B: b=1, g=1. 1 > 2*1 (False)
 * 3. G: b=1, g=2. 1 > 2*2 (False)
 * 4. B: b=2, g=2. 2 > 2*2 (False)
 * 5. B: b=3, g=2. 3 > 2*2 (False)
 * 6. B: b=4, g=2. 4 > 2*2 (False)
 * 7. B: b=5, g=2. 5 > 2*2 (True). Gate closes. Total 7 people.
 * Correct.
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    int b = 0;
    int g = 0;
    int count = 0;

    for (int i = 0; i < N; ++i) {
        if (S[i] == 'B') {
            b++;
        } else {
            g++;
        }
        count++;
        
        if (b > 2 * g) {
            break;
        }
    }
    cout << count << "\n";
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