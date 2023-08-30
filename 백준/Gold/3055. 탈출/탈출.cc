#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

string board[52];
int hedge[52][52];
int flood[52][52];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int r, c, bx, by;
	queue<pair<int, int>> hog_q, flo_q;
	cin >> r >> c;

	memset(hedge, -1, sizeof(hedge));
	memset(flood, -1, sizeof(flood));

	for (int i = 0; i < r; i++) {
		cin >> board[i];
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (board[i][j] == 'D') {
				bx = i;
				by = j;
			}
			else if (board[i][j] == 'S') {
				hog_q.push({ i, j });
				hedge[i][j] = 0;
			}
			else if (board[i][j] == '*') {
				flo_q.push({ i, j });
				flood[i][j] = 0;
			}
		}
	}

	while (!flo_q.empty()) {
		pair<int, int> cur = flo_q.front();
		flo_q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || ny < 0 || nx >= r || ny >= c) {
				continue;
			}
			if (flood[nx][ny] >= 0 || board[nx][ny] != '.') {
				continue;
			}

			flood[nx][ny] = flood[cur.X][cur.Y] + 1;
			flo_q.push({ nx, ny });
		}
	}

	while (!hog_q.empty()) {
		pair<int, int> cur = hog_q.front();
		hog_q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || ny < 0 || nx >= r || ny >= c) {
				continue;
			}
			if (hedge[nx][ny] >= 0 || board[nx][ny] == '*' || board[nx][ny] == 'X') {
				continue;
			}
			if (flood[nx][ny] != -1 && hedge[cur.X][cur.Y] + 1 >= flood[nx][ny]) {
				continue;
			}

			hedge[nx][ny] = hedge[cur.X][cur.Y] + 1;
			hog_q.push({ nx, ny });

			if (nx == bx && ny == by) {
				cout << hedge[nx][ny];
				return 0;
			}
		}
	}

	cout << "KAKTUS";
	
	return 0;
}