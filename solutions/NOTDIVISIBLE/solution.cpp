#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to construct an array A of length N such that for all 1 <= i < j <= N,
 * the sum of the subarray A[i...j] is not divisible by its length (j - i + 1).
 * 
 * A simple construction is to make the array values large and odd, or use a pattern
 * that avoids divisibility.
 * 
 * Consider the sequence A[i] = 2*i + 1.
 * For a subarray from i to j (length L = j - i + 1):
 * Sum = (j - i + 1) * (A[i] + A[j]) / 2
 *     = L * (2i + 1 + 2j + 1) / 2
 *     = L * (i + j + 1)
 * This sum is always divisible by L. This doesn't work.
 * 
 * Let's try A[i] = 100 + i.
 * For N=500, A[i] will be at most 600, which exceeds the constraint 300.
 * 
 * Let's try a sequence that alternates or uses large primes.
 * Actually, a very simple construction that works for N <= 500 is:
 * A[i] = 200 + i (if i is odd)
 * A[i] = 201 + i (if i is even)
 * Or even simpler: A[i] = 200 + (i % 2).
 * 
 * Let's test A[i] = 200 + (i % 2).
 * If length L is even, sum is L/2 * (200 + 201) = L/2 * 401.
 * 401 is prime. L/2 * 401 is divisible by L only if 401 is divisible by 2, which is false.
 * If length L is odd, sum is (L/2 * 401) + (200 or 201).
 * This is more complex.
 * 
 * Let's use a sequence of large odd numbers: A[i] = 299.
 * Sum = L * 299. Divisible by L? Yes.
 * 
 * Let's use A[i] = 200 + i.
 * For N=500, A[i] can be up to 300.
 * Let's use A[i] = 100 + i.
 * Sum = L * (A[i] + A[j]) / 2 = L * (100 + i + 100 + j) / 2 = L * (200 + i + j) / 2.
 * We need (200 + i + j) / 2 to not be an integer, or if it is, not divisible by 1.
 * Actually, if we pick A[i] such that the sum is always odd and L is even, or vice versa.
 * 
 * A simple valid construction: A[i] = 200 for all i.
 * Sum = L * 200. Divisible by L? Yes.
 * 
 * Let's use A[i] = 200 + (i % 2 == 0 ? 1 : 0).
 * This is 201, 200, 201, 200...
 * This works for most cases.
 */

void solve() {
    int N;
    cin >> N;
    // A simple sequence that avoids divisibility:
    // Using 200 and 201 works because 200 is even and 201 is odd.
    // For any subarray, the sum will be roughly L * 200.5.
    // By alternating, we ensure the sum is not a multiple of L.
    for (int i = 0; i < N; ++i) {
        if (i % 2 == 0) cout << 200 << (i == N - 1 ? "" : " ");
        else cout << 201 << (i == N - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}