#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

/**
 * Problem Analysis:
 * The knight's move changes the color of the square it is on.
 * After 100 moves (an even number), the knight must be on a square of the 
 * same color as the starting square.
 * 
 * On an 8x8 board, the knight can reach any square. The only constraint 
 * is the parity of the number of moves. Since 100 is even, the knight 
 * can reach (X2, Y2) from (X1, Y1) in exactly 100 moves if and only if 
 * the minimum number of moves 'd' required to reach (X2, Y2) is even 
 * and d <= 100.
 */

int dist[9][9][9][9];

void precompute() {
    for (int i = 1; i <= 8; ++i) {
        for (int j = 1; j <= 8; ++j) {
            for (int k = 1; k <= 8; ++k) {
                for (int l = 1; l <= 8; ++l) {
                    dist[i][j][k][l] = -1;
                }
            }
        }
    }

    int dx[] = {1, 1, -1, -1, 2, 2, -2, -2};
    int dy[] = {2, -2, 2, -2, 1, -1, 1, -1};

    for (int x1 = 1; x1 <= 8; ++x1) {
        for (int y1 = 1; y1 <= 8; ++y1) {
            queue<pair<int, int>> q;
            q.push({x1, y1});
            dist[x1][y1][x1][y1] = 0;
            while (!q.empty()) {
                pair<int, int> curr = q.front();
                q.pop();
                for (int i = 0; i < 8; ++i) {
                    int nx = curr.first + dx[i];
                    int ny = curr.second + dy[i];
                    if (nx >= 1 && nx <= 8 && ny >= 1 && ny <= 8 && dist[x1][y1][nx][ny] == -1) {
                        dist[x1][y1][nx][ny] = dist[x1][y1][curr.first][curr.second] + 1;
                        q.push({nx, ny});
                    }
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precompute();

    int t;
    cin >> t;
    while (t--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int d = dist[x1][y1][x2][y2];
        if (d <= 100 && (100 - d) % 2 == 0) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    return 0;
}