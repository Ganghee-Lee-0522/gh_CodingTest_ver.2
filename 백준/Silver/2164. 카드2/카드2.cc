#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, tmp;
	queue<int> q;

	cin >> N;

	for (int i = 1; i <= N; i++) {
		q.push(i);
	}

	while (q.size() > 1) {
		q.pop();
		tmp = q.front();
		q.pop();
		q.push(tmp);
	}

	cout << q.front();
}