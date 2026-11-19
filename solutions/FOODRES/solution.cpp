#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem Analysis:
 * We need to find the maximum D such that sum(floor(A_i / D)) >= M.
 * The function f(D) = sum(floor(A_i / D)) is monotonically non-increasing.
 * Binary search is the correct approach.
 * 
 * Constraints:
 * N, M <= 10^5
 * A_i <= 10^4
 * Max possible D is 10^4 (since even if M=1, D cannot exceed max(A_i)).
 */

bool check(long long D, int N, long long M, const vector<int>& A) {
    if (D == 0) return true;
    long long total_people = 0;
    for (int i = 0; i < N; ++i) {
        total_people += (A[i] / D);
        if (total_people >= M) return true;
    }
    return total_people >= M;
}

int main() {
    // Optimize I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    long long M;
    
    // The problem description does not explicitly mention T test cases.
    // Reading N and M directly.
    if (!(cin >> N >> M)) return 0;
    
    vector<int> A(N);
    int max_a = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        if (A[i] > max_a) max_a = A[i];
    }

    // Binary search for D in range [0, max_a]
    long long low = 0, high = max_a;
    long long ans = 0;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (mid == 0) {
            low = mid + 1;
            continue;
        }
        if (check(mid, N, M, A)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    cout << ans << endl;

    return 0;
}