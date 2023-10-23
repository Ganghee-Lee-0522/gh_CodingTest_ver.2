#include <bits/stdc++.h>
using namespace std;

int board[102][102][102];

int dm[6] = { -1, 1, 0, 0, 0, 0 };
int dn[6] = { 0, 0, -1, 1, 0, 0 };
int dh[6] = { 0, 0, 0, 0, -1, 1 };

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int m, n, h, cm, cn, ch, day = 0;
	queue<tuple<int, int, int>> q;
	cin >> m >> n >> h;

	for (int k = 0; k < h; k++) {
		for (int r = 0; r < n; r++) {
			for (int c = 0; c < m; c++) {
				cin >> board[k][r][c];
				if (board[k][r][c] == 1) {
					q.emplace(k, r, c);
				}
			}
		}
	}

	while (!q.empty()) {
		tie(ch, cn, cm) = q.front();
		q.pop();

		for (int dir = 0; dir < 6; dir++) {
			int nh = ch + dh[dir];
			int nn = cn + dm[dir];
			int nm = cm + dn[dir];

			if (nh < 0 || nn < 0 || nm < 0 || nh >= h || nn >= n || nm >= m) {
				continue;
			}
			if (board[nh][nn][nm] != 0) {
				continue;
			}

			board[nh][nn][nm] = board[ch][cn][cm] + 1;
			q.emplace(nh, nn, nm);
		}
	}

	for (int k = 0; k < h; k++) {
		for (int r = 0; r < n; r++) {
			for (int c = 0; c < m; c++) {
				if (board[k][r][c] == 0) {
					cout << -1;
					return 0;
				}
				if (board[k][r][c] > day) {
					day = board[k][r][c];
				}
			}
		}
	}

	cout << --day;

	return 0;
}