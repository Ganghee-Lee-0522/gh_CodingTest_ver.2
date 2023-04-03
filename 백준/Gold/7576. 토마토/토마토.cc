#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int N, M;

int box[1005][1005];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int main() {

	queue<pair<int, int>> q;
	int day = -1;
	int cnt = 0;

	cin >> M >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> box[i][j];

			if (box[i][j] == 1) {
				q.push({ i, j });
			}

			if (box[i][j] == 0)
				cnt++;
		}
	}

	if (cnt == 0) {
		cout << 0;
		return 0;
	}

	q.push({ -1, -1 });

	while (!q.empty()) {
		pair<int, int> cur = q.front();

		if (cur.X == -1) {
			day++;
			q.pop();

			if (q.size() > 0)
				q.push({ -1, -1 });
			
			continue;
		}

		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			
			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;
			if (box[nx][ny] != 0)
				continue;

			box[nx][ny] = 1;
			q.push({ nx, ny });
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (box[i][j] == 0) {
				cout << -1;
				return 0;
			}
		}
	}

	cout << day;


	return 0;
}