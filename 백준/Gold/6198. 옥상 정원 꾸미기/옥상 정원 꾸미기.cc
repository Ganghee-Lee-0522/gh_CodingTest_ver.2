#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, h;
	long long ans = 0;
	stack<int> s;
	cin >> n;

	for(int i = 0; i < n; i++) {
		cin >> h;
		while (!s.empty() && s.top() <= h) {
			s.pop();
		}
		s.push(h);
		ans += (long long) s.size() - 1;
	}

	cout << ans;
}