# [Equal Card Game (EQCARDGAME)](https://www.codechef.com/problems/EQCARDGAME)

- **Difficulty Rating**: 1058
- **Solved in**: 1 attempt(s)

## Problem Summary
Alice has a standard deck of 52 cards. She wants to distribute the cards equally among $K$ people. If the cards cannot be distributed equally, she must discard some cards until the remaining number of cards is divisible by $K$. The goal is to find the minimum number of cards Alice needs to discard.

## Intuition & Mathematical Observation
To distribute the cards equally among $K$ people, the number of cards remaining ($R$) must be a multiple of $K$ such that $R \le 52$. 

To minimize the number of discarded cards ($52 - R$), we need to maximize $R$. The largest multiple of $K$ that is less than or equal to 52 is given by $52 - (52 \pmod K)$.

Therefore, the number of cards to discard is:
$$\text{Discarded} = 52 - (52 - (52 \pmod K)) = 52 \pmod K$$

This simple modulo operation directly gives the minimum number of cards that must be removed so that the remainder is perfectly divisible by $K$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the modulo operation is performed in constant time. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few integer variables regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Alice has 52 cards. There are K people in total.
 * She needs to distribute the remaining cards equally among K people.
 * Let R be the number of cards remaining after discarding some cards.
 * R must be a multiple of K, and R <= 52.
 * To minimize the number of discarded cards (52 - R), we need to maximize R.
 * R = 52 - (52 % K).
 * The number of discarded cards is 52 % K.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int k;
        cin >> k;
        
        // The number of cards to discard is simply 52 modulo K.
        // If 52 is divisible by K, 52 % K is 0, which is correct.
        int discarded = 52 % k;
        
        cout << discarded << "\n";
    }
    
    return 0;
}
```