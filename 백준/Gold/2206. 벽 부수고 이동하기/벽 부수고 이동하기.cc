#include <bits/stdc++.h>
using namespace std;

int board[1005][1005];
int dist[1005][1005][2];  // [x][y][z] -> (x, y) 위치에 벽을 z번 부쉈을 때의 최단 거리

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d", &board[i][j]);  // 벽 정보를 1개씩 읽어옴
        }
    }

    memset(dist, -1, sizeof(dist));

    queue<tuple<int, int, int>> q;
    q.push({0, 0, 0});
    dist[0][0][0] = 1;  // 시작 위치 초기화

    while (!q.empty()) {
        auto [x, y, z] = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

            if (board[nx][ny] == 0 && dist[nx][ny][z] == -1) {  // 빈 칸일 경우
                dist[nx][ny][z] = dist[x][y][z] + 1;
                q.push({nx, ny, z});
            } else if (z == 0 && board[nx][ny] == 1 && dist[nx][ny][1] == -1) {  // 벽이고 아직 벽을 안 부쉈을 경우
                dist[nx][ny][1] = dist[x][y][z] + 1;
                q.push({nx, ny, 1});
            }
        }
    }

    if (dist[n - 1][m - 1][0] == -1 && dist[n - 1][m - 1][1] == -1) {
        cout << -1;
    } else if (dist[n - 1][m - 1][0] == -1) {
        cout << dist[n - 1][m - 1][1];
    } else if (dist[n - 1][m - 1][1] == -1) {
        cout << dist[n - 1][m - 1][0];
    } else {
        cout << min(dist[n - 1][m - 1][0], dist[n - 1][m - 1][1]);
    }

    return 0;
}
