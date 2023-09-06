#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, ans = 0;
	vector<int> alpha(26, 0);
	string s;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> s;
		int tmp = 1;
		for (int j = 0; j < s.size(); j++) {
			alpha[s[s.size() - j - 1] - 'A'] += tmp;
			tmp *= 10;
		}
	}

	sort(alpha.begin(), alpha.end(), greater<int>());

	int num = 9;
	for (int i = 0; i <= 10; i++) {
		if (alpha[i] == 0) {
			cout << ans;
			return 0;
		}

		ans += num * alpha[i];
		num--;
	}

	return 0;
}