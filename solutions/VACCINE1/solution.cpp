#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have two companies A and B.
 * Company A starts producing V1 vaccines per day from day D1.
 * Company B starts producing V2 vaccines per day from day D2.
 * We need to find the smallest day 'd' such that total vaccines >= P.
 * 
 * Since the constraints are small (D, V <= 100, P <= 1000), we can simulate 
 * day by day or use a simple loop. The maximum number of days will not exceed 
 * 1000 + max(D1, D2), which is well within the time limit.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int D1, V1, D2, V2, P;
    if (!(cin >> D1 >> V1 >> D2 >> V2 >> P)) return 0;

    int total_vaccines = 0;
    int day = 0;

    // Simulate day by day until total_vaccines >= P
    while (total_vaccines < P) {
        day++;
        
        // Add production from Company A if day >= D1
        if (day >= D1) {
            total_vaccines += V1;
        }
        
        // Add production from Company B if day >= D2
        if (day >= D2) {
            total_vaccines += V2;
        }
    }

    cout << day << "\n";

    return 0;
}