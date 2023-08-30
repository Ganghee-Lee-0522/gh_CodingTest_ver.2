#include <bits/stdc++.h>
using namespace std;

int board[105][105];
long long dp[105][105];

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	dp[0][0] = 1;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (dp[i][j] == 0 || (i == n - 1 && j == n - 1))
				continue;

			int cnt = board[i][j];
			int d = cnt + i;
			int r = cnt + j;

			if (d < n)
				dp[d][j] += dp[i][j];

			if (r < n)
				dp[i][r] += dp[i][j];
		}
	}

	cout << dp[n - 1][n - 1];
}