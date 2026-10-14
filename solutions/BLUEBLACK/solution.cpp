#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int A, B;
    if (!(cin >> A >> B)) return 0;

    // Option 1: 3 blue pens
    int cost1 = 3 * A;
    
    // Option 2: 1 blue pen and 1 black pen
    int cost2 = A + B;

    // Output the minimum of the two options
    cout << min(cost1, cost2) << endl;

    return 0;
}