#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Total family members = 5.
 * Daily bun requirement = 5 * X.
 * Number of days the buns last = floor(N / (5 * X)).
 * Total survival days = (days buns last) + D.
 * 
 * Constraints:
 * N < 500, X <= 10, D < 20.
 * The values are small, so standard integer types are sufficient.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, x, d;
        cin >> n >> x >> d;

        // Total buns required per day for the family of 5
        long long daily_requirement = 5 * x;

        // Calculate how many full days the buns can feed the family
        // If N < daily_requirement, the result is 0 days of food.
        long long days_with_food = n / daily_requirement;

        // Total survival time is the days with food plus the extra D days
        long long total_survival_days = days_with_food + d;

        cout << total_survival_days << "\n";
    }

    return 0;
}