#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	stack<int> s;

	cin >> n;
	vector<int> num(n);
	vector<int> ans(n, -1);

	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	for (int i = 0; i < n; i++) {
		while (!s.empty() && num[i] > num[s.top()]) {
			ans[s.top()] = num[i];
			s.pop();
		}
		s.push(i);
	}



	for (int i = 0; i < n; i++) {
		cout << ans[i] << ' ';
	}

	return 0;
}