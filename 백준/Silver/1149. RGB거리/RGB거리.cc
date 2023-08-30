#include <bits/stdc++.h>

using namespace std;

int color[1005][4];
int cost[1005][4];

int main() {

	int n;
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		cin >> color[i][1] >> color[i][2] >> color[i][3];
	}

	cost[1][1] = color[1][1];
	cost[1][2] = color[1][2];
	cost[1][3] = color[1][3];

	for (int i = 1; i <= n; i++) {
		cost[i][1] = min(cost[i - 1][2], cost[i - 1][3]) + color[i][1];
		cost[i][2] = min(cost[i - 1][1], cost[i - 1][3]) + color[i][2];
		cost[i][3] = min(cost[i - 1][1], cost[i - 1][2]) + color[i][3];
	}

	int ans = min(cost[n][1], cost[n][2]);
	ans = min(ans, cost[n][3]);

	cout << ans;

	return 0;
}