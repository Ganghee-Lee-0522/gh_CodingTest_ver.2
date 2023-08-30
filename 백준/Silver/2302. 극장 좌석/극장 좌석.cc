#include <bits/stdc++.h>
using namespace std;

int dp[45];

int main() {

	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;

	for (int i = 4; i < 41; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	int n, m, nxt;
	int pre = 1, ans = 1;

	cin >> n >> m;

	for(int i = 0; i < m; i++) {
		cin >> nxt;
		ans *= dp[nxt - pre];
		pre = nxt + 1;
	}

	ans *= dp[n - pre + 1];

	cout << ans;
	

	return 0;
}