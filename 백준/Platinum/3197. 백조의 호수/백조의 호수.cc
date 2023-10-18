#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int ice[1501][1501];
bool swanVisit[1501][1501];
bool tmpVisit[1501][1501];


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int r, c, lx, ly, day = 0;
	string s;
	queue<pair<int, int>> thaw;
	queue<pair<int, int>> nxt;
	queue<pair<int, int>> swan;
	queue<pair<int, int>> tmp;

	cin >> r >> c;

	for (int i = 0; i < r; i++) {
		cin >> s;
		// 입력 받은 문자열 처리
		for (int j = 0; j < c; j++) {
			// 빙판일 때
			if (s[j] == 'X') {
				ice[i][j] = -1;
			}
			// 물일 때
			else if (s[j] == '.') {
				ice[i][j] = 0;
				thaw.push({ i, j });
			}
			// 백조일 때
			else {
				ice[i][j] = -1000;
				lx = i;
				ly = j;
				thaw.push({ i, j });
			}
		}

	}

	swan.push({ lx, ly });
	swanVisit[lx][ly] = true;

	while (true) {
		// 맞닿은 빙판 찾기
		while (!thaw.empty()) {
			pair<int, int> cur = thaw.front();
			thaw.pop();

			tmpVisit[cur.X][cur.Y] = true;

			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];

				if (nx < 0 || nx >= r || ny < 0 || ny >= c || tmpVisit[nx][ny]) {
					continue;
				}

				// 맞닿은 빙판만 큐에 넣기
				if (ice[nx][ny] == -1) {
					nxt.push({ nx, ny });
				}

				tmpVisit[nx][ny] = true;
			}
		}

		// 맞닿은 빙판 녹이기
		while (!nxt.empty()) {
			pair<int, int> cur = nxt.front();
			nxt.pop();

			ice[cur.X][cur.Y] = 0;
			thaw.push({ cur.X, cur.Y });
		}

		day++;

		// 백조 찾기
		while (!swan.empty()) {
			pair<int, int> cur = swan.front();
			swan.pop();

			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];

				if (nx < 0 || nx >= r || ny < 0 || ny >= c || swanVisit[nx][ny]) {
					continue;
				}

				// 빙판을 만나면 큐에 넣기
				if (ice[nx][ny] == -1) {
					swanVisit[nx][ny] = true;
					tmp.push({ nx, ny });
					continue;
				}
				// 다른 백조를 만나면 중단하기
				else if (ice[nx][ny] == -1000) {
					cout << day;
					return 0;
				}

				swanVisit[nx][ny] = true;
				swan.push({ nx, ny });
			}
		}

		// 맞닿은 빙판들을 다시 백조 큐에 넣기
		// 다음 번 백조 탐색은 빙판부터 시작할 수 있도록
		while (!tmp.empty()) {
			pair<int, int> cur = tmp.front();
			tmp.pop();

			swan.push({ cur.X, cur.Y });
		}
	}

	return 0;
}