#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N truth-tellers and M liars (who can lie or tell the truth).
 * We ask X people. We need to be sure of the path regardless of which X people we pick.
 * 
 * Let the two paths be P1 and P2.
 * If we pick a set of X people, some are truth-tellers (T) and some are liars (L).
 * The truth-tellers will always point to the correct path.
 * The liars can point to either path.
 * 
 * To be absolutely sure of the path, we must be able to distinguish the truth.
 * If we pick X people, the worst-case scenario is that we pick some number of truth-tellers
 * and some number of liars.
 * 
 * If we pick X people, we have at most M liars.
 * If X > M, we are guaranteed to have at least (X - M) truth-tellers.
 * However, the liars can mimic the truth-tellers.
 * 
 * The condition to be sure is that the number of truth-tellers must be strictly 
 * greater than the number of liars in the group we picked, OR we must have 
 * enough information to identify the truth.
 * 
 * Actually, the condition is simpler:
 * If we pick X people, we can be sure if and only if the number of truth-tellers 
 * in our selection is guaranteed to be greater than the number of liars 
 * in our selection, regardless of how the liars answer.
 * 
 * Wait, the problem states: "regardless of which X people you end up asking".
 * If we pick X people, we might pick all M liars and only (X-M) truth-tellers.
 * If X-M <= M, the liars can outvote or match the truth-tellers.
 * Thus, we need X-M > M, which means X > 2M.
 * 
 * But we also need to ensure we have enough people to cover all possibilities.
 * The total number of people is N + M.
 * If we ask all N + M people, we have N truth-tellers and M liars.
 * We can be sure if N > M. If N <= M, even asking everyone doesn't guarantee 
 * the truth because the M liars could potentially mimic the N truth-tellers 
 * or vice versa if N <= M.
 * 
 * Correct logic:
 * We need to be sure regardless of who we pick.
 * If we pick X people, the worst case is we pick as many liars as possible.
 * We have M liars. If we pick X people, we could have min(X, M) liars.
 * The number of truth-tellers would be X - min(X, M).
 * We need the number of truth-tellers to be greater than the number of liars 
 * to be sure: (X - min(X, M)) > min(X, M).
 * If X <= M: X - X > X => 0 > X (Impossible).
 * If X > M: X - M > M => X > 2M.
 * Also, we must have enough truth-tellers available: X <= N + M.
 * So if N > M, the answer is 2M + 1. If N <= M, it's impossible (-1).
 */

void solve() {
    int N, M;
    cin >> N >> M;

    if (N > M) {
        cout << 2 * M + 1 << "\n";
    } else {
        cout << -1 << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}