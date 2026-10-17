#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given three sorted lists of voter IDs. We need to find IDs that appear
 * in at least two of the three lists.
 * 
 * Constraints:
 * N1, N2, N3 <= 50,000.
 * Total IDs <= 150,000.
 * 
 * Approach:
 * Since the lists are already sorted, we can use a frequency map (or a hash map)
 * to count the occurrences of each ID. Since IDs are positive integers, a 
 * std::map<int, int> or std::unordered_map<int, int> will work efficiently.
 * Given the constraints and the need for sorted output, std::map is ideal as it
 * keeps keys in ascending order automatically.
 * 
 * Time Complexity: O(N log N) where N = N1 + N2 + N3.
 * Space Complexity: O(N) to store the IDs in the map.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n1, n2, n3;
    if (!(cin >> n1 >> n2 >> n3)) return 0;

    // Map to store frequency of each ID
    // map keeps keys sorted, which is required for the output
    map<int, int> counts;

    int total = n1 + n2 + n3;
    for (int i = 0; i < total; ++i) {
        int id;
        cin >> id;
        counts[id]++;
    }

    // Collect IDs that appear in at least 2 lists
    vector<int> result;
    for (auto const& [id, count] : counts) {
        if (count >= 2) {
            result.push_back(id);
        }
    }

    // Output the count of such IDs
    cout << result.size() << "\n";
    
    // Output the IDs in ascending order
    for (int id : result) {
        cout << id << "\n";
    }

    return 0;
}