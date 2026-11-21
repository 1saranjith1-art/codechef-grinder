#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We want to find max(A_i % A_j) for all i, j.
 * 
 * Case 1: If A_i < A_j, then A_i % A_j = A_i.
 * Case 2: If A_i > A_j, then A_i % A_j < A_j.
 * 
 * To maximize the remainder, we want the largest possible A_i that is not divisible 
 * by some A_j. Specifically, if we take the two largest distinct values in the array, 
 * say M1 (the largest) and M2 (the second largest), then M2 % M1 = M2.
 * 
 * If we have multiple occurrences of the largest value, they don't help us get a 
 * larger remainder than M2 % M1. Thus, we simply need to find the two largest 
 * distinct values in the array. Let these be M1 and M2 (where M1 > M2).
 * The answer is M2.
 * 
 * Complexity:
 * Time: O(N) to find the two largest distinct elements.
 * Space: O(N) to store the input, or O(1) if processed on the fly.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    // We use a set to store unique elements to easily find the two largest.
    // Given N up to 10^5, O(N log N) or O(N) is perfectly fine.
    set<int> distinct_elements;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        distinct_elements.insert(val);
    }

    // If there are fewer than 2 distinct elements, the max remainder is 0
    // (e.g., 5 % 5 = 0).
    if (distinct_elements.size() < 2) {
        cout << 0 << "\n";
    } else {
        // Get the largest element
        auto it = distinct_elements.end();
        --it; // Points to largest
        int m1 = *it;
        --it; // Points to second largest
        int m2 = *it;
        
        // The result is m2 % m1, which is simply m2 since m2 < m1.
        cout << m2 << "\n";
    }

    return 0;
}