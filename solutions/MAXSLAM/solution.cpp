#include <iostream>

/**
 * Problem Analysis:
 * Chef needs at least 25 Grand Slams.
 * Chef currently has X Grand Slams.
 * Chef wins 4 Grand Slams per year.
 * Let Y be the number of years.
 * We need: X + 4 * Y >= 25
 * 4 * Y >= 25 - X
 * Y >= (25 - X) / 4
 * Since Y must be an integer, Y = ceil((25 - X) / 4.0)
 * Using integer arithmetic, this is equivalent to (25 - X + 3) / 4.
 */

int main() {
    // Fast I/O setup
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int X;
    // The problem specifies the input is a single integer X.
    // There is no test case count T.
    if (std::cin >> X) {
        int needed = 25 - X;
        if (needed <= 0) {
            std::cout << 0 << "\n";
        } else {
            // Ceiling division of needed / 4
            int years = (needed + 3) / 4;
            std::cout << years << "\n";
        }
    }

    return 0;
}