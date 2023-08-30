#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int t, n, x, y;
	pair<int, int> sang;
	pair<int, int> penta;

	cin >> t;

	while (t--) {
		bool flag = false;
		queue<pair<int, int>> q;

		cin >> n;
		vector<pair<int, int>> store(n);
		vector<int> isVisit(n, -1);

		cin >> sang.X >> sang.Y;
		
		for (int i = 0; i < n; i++) {
			cin >> store[i].X >> store[i].Y;
		}

		cin >> penta.X >> penta.Y;

		q.push({ sang.X, sang.Y });
		
		while (!q.empty()) {
			pair<int, int> cur = q.front();
			q.pop();

			for (int dir = 0; dir < n; dir++) {
				if ((abs(store[dir].X - cur.X) + abs(store[dir].Y - cur.Y)) <= 1000) {
					if (isVisit[dir] == -1) {
						isVisit[dir] = 1;
						q.push({ store[dir].X, store[dir].Y });
					}
				}
			}

			if ((abs(penta.X - cur.X) + abs(penta.Y - cur.Y)) <= 1000) {
				flag = true;
				break;
			}
		}

		if (flag) {
			cout << "happy" << '\n';
		}
		else {
			cout << "sad" << '\n';
		}

	}
	
	return 0;
}