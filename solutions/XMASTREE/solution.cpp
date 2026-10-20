#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * Chef bought N trees for A rupees each (Total Cost = N * A).
 * Chef sold M trees for B rupees each (Total Revenue = M * B).
 * Profit = Total Revenue - Total Cost = (M * B) - (N * A).
 * 
 * The input format specifies a single line with 4 integers, 
 * so we do not need a test case loop.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long N, A, M, B;
    
    // Read the single line of input
    if (cin >> N >> A >> M >> B) {
        // Calculate total cost and total revenue
        // Based on the sample explanation:
        // 5 trees at 100 each = 500 cost
        // 2 trees at 1000 each = 2000 revenue
        // Profit = 2000 - 500 = 1500
        long long total_cost = N * A;
        long long total_revenue = M * B;
        
        // Profit = Revenue - Cost
        long long profit = total_revenue - total_cost;
        
        cout << profit << endl;
    }

    return 0;
}