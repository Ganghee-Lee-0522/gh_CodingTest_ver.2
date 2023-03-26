#include <bits/stdc++.h>

using namespace std;

int main() {
	int ans = 0, n;
	string s;

	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> s;
		int check[26] = { 0 };
		char pre = s[0];
		for (char e : s) {
			if (check[e - 'a'] == 0) {
				check[e - 'a'] = 1;
				pre = e;
			}
			else if (pre != e) {
				ans--;
				break;
			}
		}
		ans++;
	}

	cout << ans;
	return 0;
}