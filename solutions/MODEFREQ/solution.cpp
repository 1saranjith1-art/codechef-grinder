#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Optimized approach:
 * 1. Use a frequency array (or vector) to count occurrences of each number.
 * 2. Since A_i can be up to 10000, an array of size 10001 is sufficient.
 * 3. Count how many numbers have a specific frequency.
 * 4. Find the mode of these frequencies.
 */

void solve() {
    int n;
    if (!(cin >> n)) return;
    
    // Using a vector for frequency counting (A_i <= 10000)
    vector<int> counts(10001, 0);
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        counts[a]++;
    }
    
    // freq_of_freq[f] = how many numbers appear exactly f times
    // The maximum possible frequency is N.
    vector<int> freq_of_freq(n + 1, 0);
    for (int i = 1; i <= 10000; ++i) {
        if (counts[i] > 0) {
            freq_of_freq[counts[i]]++;
        }
    }
    
    int max_occurrence = -1;
    int result_freq = -1;
    
    // Iterate through possible frequencies (1 to N)
    // We want the smallest frequency if there's a tie, 
    // so we iterate in increasing order.
    for (int f = 1; f <= n; ++f) {
        if (freq_of_freq[f] > max_occurrence) {
            max_occurrence = freq_of_freq[f];
            result_freq = f;
        }
    }
    
    cout << result_freq << "\n";
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