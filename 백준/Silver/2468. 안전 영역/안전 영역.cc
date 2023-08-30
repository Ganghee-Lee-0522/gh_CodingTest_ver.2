#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int board[105][105];
int check[105][105];

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    pair<int, int> minPoint = { 0, 0 };
    pair<int, int> maxPoint = { 0, 0 };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if (board[i][j] > board[maxPoint.X][maxPoint.Y]) {
                maxPoint.X = i;
                maxPoint.Y = j;
            }
            if (board[i][j] < board[minPoint.X][minPoint.Y]) {
                minPoint.X = i;
                minPoint.Y = j;
            }
        }
    }

    int safe = 1;

    for (int rain = board[minPoint.X][minPoint.Y]; rain <= board[maxPoint.X][maxPoint.Y]; rain++) {
        memset(check, 0, sizeof(check));

        int tmp = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] > rain && check[i][j] == 0) {
                    tmp++;
                    queue<pair<int, int>> q;
                    q.push({ i, j });
                    check[i][j] = 1;

                    while (!q.empty()) {
                        pair<int, int> cur = q.front();
                        q.pop();

                        for (int dir = 0; dir < 4; dir++) {
                            int nx = cur.X + dx[dir];
                            int ny = cur.Y + dy[dir];

                            if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                                continue;

                            if (board[nx][ny] <= rain || check[nx][ny] == 1)
                                continue;

                            check[nx][ny] = 1;
                            q.push({ nx, ny });
                        }
                    }
                }
            }
        }

        safe = safe > tmp ? safe : tmp;
    }

    cout << safe;

    return 0;
}
