#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[105][105];
bool visited[105][105];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int main() {

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    int pre = 0;
    int time = 0;

    while (true) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                visited[i][j] = false;
            }
        }

        int cheese = 0;

        // 치즈 개수 세기
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 1) {
                    cheese++;
                }
            }
        }

        if (cheese == 0) {
            cout << time << '\n' << pre;
            return 0;
        }

        pre = cheese;
        time++;

        queue<pair<int, int>> q;
        q.push({ 0, 0 });
        visited[0][0] = true;

        while (!q.empty()) {
            pair<int, int> cur = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = cur.X + dx[i];
                int ny = cur.Y + dy[i];

                if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny]) {
                    if (board[nx][ny] == 0) {
                        q.push({ nx, ny });
                    }
                    else {
                        board[nx][ny] = 0; // 치즈 녹이기
                    }
                    visited[nx][ny] = true;
                }
            }
        }
    }

    return 0;
}