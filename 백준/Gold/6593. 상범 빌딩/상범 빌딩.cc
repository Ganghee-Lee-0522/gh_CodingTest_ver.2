#include <bits/stdc++.h>
using namespace std;

int dl[6] = { -1, 1, 0, 0, 0, 0 };
int dr[6] = { 0, 0, -1, 1, 0, 0 };
int dc[6] = { 0, 0, 0, 0, -1, 1 };

string board[32][32];
int visited[32][32][32];

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	bool isTrapped = true;
	int l, r, c, cl, cr, cc, time;
	char blank;

	while (true) {
		cin >> l >> r >> c;
		if (l == 0 && r == 0 && c == 0) {
			return 0;
		}

		queue<tuple<int, int, int>> q;
		memset(visited, -1, sizeof(visited));

		for (int i = 0; i < l; i++) {
			for (int j = 0; j < r; j++) {
				cin >> board[i][j];
				if (board[i][j][0] == ' ') {
					j--;
					continue;
				}

				for (int k = 0; k < c; k++) {
					if (board[i][j][k] == 'E') {
						q.emplace(i, j, k);
						visited[i][j][k] = 0;
					}
				}
			}
		}

		while (!q.empty() && isTrapped) {
			tie(cl, cr, cc) = q.front();
			q.pop();

			for (int dir = 0; dir < 6; dir++) {
				int nl = cl + dl[dir];
				int nr = cr + dr[dir];
				int nc = cc + dc[dir];

				if (nl < 0 || nr < 0 || nc < 0 || nl >= l || nr >= r || nc >= c) {
					continue;
				}
				if (visited[nl][nr][nc] > 0 || board[nl][nr][nc] == '#') {
					continue;
				}

				visited[nl][nr][nc] = visited[cl][cr][cc] + 1;

				if (board[nl][nr][nc] == 'S') {
					time = visited[nl][nr][nc];
					isTrapped = false;
					break;
				}

				q.emplace(nl, nr, nc);
			}
		}
		if (!isTrapped) {
			cout << "Escaped in " << time << " minute(s)." << '\n';
			isTrapped = true;
		}
		else {
			cout << "Trapped!" << '\n';
		}
	}

	return 0;
}