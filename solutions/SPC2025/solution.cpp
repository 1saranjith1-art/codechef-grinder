#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * Ved is a NEWBIE if M >= N / 2.0.
 * To avoid floating point arithmetic, we use the condition:
 * M >= N / 2.0  =>  2 * M >= N
 * 
 * Input Format:
 * The problem specifies a single line containing N and M.
 * There is no mention of multiple test cases (T).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    if (cin >> N >> M) {
        // Check if errors are at least half of the total lines
        // 2 * M >= N correctly implements M >= N / 2.0
        if (2 * M >= N) {
            cout << "NEWBIE" << endl;
        } else {
            cout << "PRO" << endl;
        }
    }

    return 0;
}