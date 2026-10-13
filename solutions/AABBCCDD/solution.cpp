#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * 1. Operation 1: Convert any uppercase letter to its lowercase equivalent.
 *    This means we can effectively treat every uppercase letter 'X' as its lowercase 'x'.
 *    After applying Operation 1 to all uppercase letters, the string consists only of lowercase letters.
 * 2. Operation 2: Choose one lowercase letter and convert ALL its occurrences to another lowercase letter.
 *    This means we can merge the counts of two different lowercase letters into one.
 * 
 * Strategy:
 * 1. Count the frequency of each character in the string, treating uppercase as lowercase.
 *    Let count[c] be the number of occurrences of character 'c' (where 'c' is 'a'...'z').
 * 2. We want to maximize the count of a single character.
 *    We can pick one character 'i' and merge it with another character 'j' (i != j).
 *    The new count for 'j' would be count[i] + count[j].
 *    We want to maximize this over all pairs (i, j).
 * 3. If we don't perform the merge (or merge a character with itself, which is effectively doing nothing),
 *    the score is simply the maximum frequency of any character.
 *    If we do perform the merge, we pick the two most frequent characters and add their counts.
 * 
 * Complexity:
 * Time: O(N) per test case to count frequencies, O(1) to find max (since alphabet size is 26).
 * Space: O(1) to store frequency array of size 26.
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    vector<int> freq(26, 0);
    for (char c : S) {
        if (c >= 'A' && c <= 'Z') {
            freq[c - 'A']++;
        } else {
            freq[c - 'a']++;
        }
    }

    // Find the two largest frequencies
    int max1 = 0, max2 = 0;
    for (int i = 0; i < 26; ++i) {
        if (freq[i] > max1) {
            max2 = max1;
            max1 = freq[i];
        } else if (freq[i] > max2) {
            max2 = freq[i];
        }
    }

    // The result is the sum of the two largest frequencies.
    // Even if there's only one character type, max2 will be 0, 
    // which is correct as we can't merge with a non-existent character.
    cout << max1 + max2 << "\n";
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