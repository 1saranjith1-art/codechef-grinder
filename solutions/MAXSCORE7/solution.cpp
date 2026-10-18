#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The array A consists only of 0s and 1s.
 * The operation involves picking two adjacent elements, adding |A_i - A_{i+1}| to the score,
 * and removing them.
 * Note that |A_i - A_{i+1}| is 1 if the elements are (0, 1) or (1, 0), and 0 if they are (0, 0) or (1, 1).
 * 
 * Let c0 be the count of 0s and c1 be the count of 1s in the array.
 * Each operation removes two elements.
 * If we remove (0, 1) or (1, 0), we gain 1 point and remove one 0 and one 1.
 * If we remove (0, 0) or (1, 1), we gain 0 points and remove two 0s or two 1s.
 * 
 * We want to maximize the number of (0, 1) or (1, 0) pairs we can form.
 * Since we can delete any adjacent pair and the remaining elements concatenate,
 * we can effectively bring any two elements together as long as we have enough 
 * "filler" operations to remove elements between them.
 * 
 * Actually, it is simpler: we have c0 zeros and c1 ones.
 * Each operation of type (0, 1) consumes one 0 and one 1.
 * We can perform at most min(c0, c1) such operations.
 * Can we always achieve min(c0, c1)? Yes.
 * Because we can always pick an adjacent pair (0, 1) or (1, 0) if one exists.
 * If no such pair exists, all elements are the same, and the score is 0.
 * If such a pair exists, we take it, and the remaining array still allows 
 * us to pair up the remaining 0s and 1s.
 */

void solve() {
    int N;
    cin >> N;
    int c0 = 0, c1 = 0;
    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val;
        if (val == 0) c0++;
        else c1++;
    }
    
    // The maximum score is simply the number of pairs of (0, 1) we can form.
    // Each pair (0, 1) contributes 1 to the score.
    cout << min(c0, c1) << "\n";
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