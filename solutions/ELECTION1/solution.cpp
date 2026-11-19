#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * A party needs a strict majority to form the government.
 * The threshold for a strict majority is floor(N / 2) + 1.
 * Let T = floor(N / 2) + 1.
 * If K >= T, the party already has a majority, so 0 additional seats are needed.
 * If K < T, the party needs (T - K) additional seats.
 * 
 * Note: The problem input format specifies N and K directly without a test case count.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    if (cin >> N >> K) {
        int threshold = (N / 2) + 1;

        if (K >= threshold) {
            cout << 0 << endl;
        } else {
            cout << (threshold - K) << endl;
        }
    }

    return 0;
}