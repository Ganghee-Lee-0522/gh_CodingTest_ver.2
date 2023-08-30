#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[205][205];
int isvisit[205][205][35];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int h_dx[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int h_dy[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int k, w, h;
	memset(isvisit, -1, sizeof(isvisit));
	cin >> k >> w >> h;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> board[i][j];
		}
	}

	queue<tuple<pair<int, int>, int>> q; // {좌표x, 좌표y}, 말횟수
	q.push({ { 0, 0 }, 0 });
	isvisit[0][0][0] = 0;

	while (!q.empty()) {
		pair<int, int> cur;
		int h_cnt;
		tie(cur, h_cnt) = q.front();
		q.pop();

		if (cur.X == h - 1 && cur.Y == w - 1) {
			cout << isvisit[cur.X][cur.Y][h_cnt];
			return 0;
		}

		if (h_cnt < k) {
			for (int dir = 0; dir < 8; dir++) {
				int nx = cur.X + h_dx[dir];
				int ny = cur.Y + h_dy[dir];

				if (nx < 0 || ny < 0 || nx >= h || ny >= w) {
					continue;
				}
				if (isvisit[nx][ny][h_cnt + 1] != -1) {
					continue;
				}
				if (board[nx][ny] == 1) {
					continue;
				}

				q.push({ { nx, ny }, h_cnt + 1 });
				isvisit[nx][ny][h_cnt + 1] = isvisit[cur.X][cur.Y][h_cnt] + 1;
			}
		}

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || ny < 0 || nx >= h || ny >= w) {
				continue;
			}
			if (isvisit[nx][ny][h_cnt] != -1) {
				continue;
			}
			if (board[nx][ny] == 1) {
				continue;
			}

			q.push({ { nx, ny }, h_cnt });
			isvisit[nx][ny][h_cnt] = isvisit[cur.X][cur.Y][h_cnt] + 1;
		}
	}

	cout << -1;

	return 0;
}