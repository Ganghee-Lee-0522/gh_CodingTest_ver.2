#include <bits/stdc++.h>

using namespace std;

int main() {

	stack<char> s;
	string cmd;
	int ans = 0, idx = 1;

	cin >> cmd;
	for (int i = 0; i < cmd.size(); i++) {
		switch (cmd[i]) {
		case '(':
			idx *= 2;
			s.push(cmd[i]);
			break;
		case '[':
			idx *= 3;
			s.push(cmd[i]);
			break;
		case ')':
			if (s.empty() || s.top() != '(') {
				cout << 0;
				return 0;
			}
			else if (cmd[i - 1] == '(') {
				ans += idx;
			}
			s.pop();
			idx /= 2;
			break;
		default:
			if (s.empty() || s.top() != '[') {
				cout << 0;
				return 0;
			}
			else if (cmd[i - 1] == '[') {
				ans += idx;
			}
			s.pop();
			idx /= 3;
		}
	}
	if (s.empty()) {
		cout << ans;
	}
	else {
		cout << 0;
	}
}