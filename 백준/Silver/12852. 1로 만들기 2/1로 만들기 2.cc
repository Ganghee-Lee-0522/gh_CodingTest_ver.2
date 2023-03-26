#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int n) {
	vector<int> dp(n + 1);
	vector<int> ans;
	dp[1] = 0;
	
	for (int i = 2; i <= n; i++) {

		dp[i] = dp[i - 1] + 1;

		if (i % 2 == 0)
			dp[i] = min(dp[i], dp[i / 2] + 1);

		if (i % 3 == 0)
			dp[i] = min(dp[i], dp[i / 3] + 1);
	}

	ans.push_back(n);

	while (n > 1) {
		if (dp[n] == dp[n - 1] + 1) {
			n = n - 1;
			ans.push_back(n);
		}
		else if (n % 2 == 0 && dp[n] == dp[n / 2] + 1) {
			n = n / 2;
			ans.push_back(n);
		}
		else if (n % 3 == 0 && dp[n] == dp[n / 3] + 1) {
			n = n / 3;
			ans.push_back(n);
		}
	}
	return ans;
}

int main() {
	int n;
	cin >> n;
	vector<int> ans = solution(n);

	cout << ans.size() - 1 << "\n";
	for (int e : ans) {
		cout << e << " ";
	}

	return 0;
}