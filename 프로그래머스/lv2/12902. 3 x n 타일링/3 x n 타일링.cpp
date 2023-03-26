#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

int solution(int n) {

	if (n % 2)
		return 0;

	long long dp[5001] = { 0 };
	dp[0] = 1;
	dp[2] = 3;

	for (int i = 4; i <= n; i += 2) {
		dp[i] = dp[i - 2] * 3;

		for (int j = i - 4; j >= 0; j -= 2) {
			dp[i] += dp[j] * 2;
		}
		dp[i] %= MOD;
	}
	
	return dp[n];
}