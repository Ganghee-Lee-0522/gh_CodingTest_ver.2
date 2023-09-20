#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

pair<int, int> parent[52][52];
char color[52][52];
int isVisit[52][52];
bool hasCycle = false;

pair<int, int> Find(pair<int, int> node) {
	if (parent[node.X][node.Y].X == -1 && parent[node.X][node.Y].Y == -1) {
		return node;
	}
	return Find(parent[node.X][node.Y]);
}

void Union(pair<int, int> a, pair<int, int> b) {
	a = Find(a);
	b = Find(b);

	if (a == b) {
		return; // 이미 같은 그룹
	}
	
	if (color[a.X][a.Y] == color[b.X][b.Y]) { // 같은 색이면 연결
		parent[b.X][b.Y] = a;
	}
}

void dfs(int x, int y, int pX, int pY, char c, int n, int m) {
	isVisit[x][y] = true;

	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
			continue;
		}
		if (color[nx][ny] == c) {
			if (!isVisit[nx][ny]) {
				dfs(nx, ny, x, y, c, n, m);
			}
			else if (nx != pX || ny != pY) {
				hasCycle = true;
			}
		}
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	memset(parent, -1, sizeof(parent));

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			color[i][j] = s[j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int dir = 0; dir < 4; dir++) { // 상하좌우 인접 노드 탐색
				int nx = i + dx[dir];
				int ny = j + dy[dir];

				if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
					continue;
				}
				if (color[i][j] == color[nx][ny]) { // 같은 색이면 연결
					Union({ i, j }, { nx, ny });
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!isVisit[i][j]) {
				dfs(i, j, -1, -1, color[i][j], n, m); // 사이클 체크
			}
		}
	}

	if (hasCycle) {
		cout << "Yes\n";
	}
	else {
		cout << "No\n";
	}

	return 0;
}