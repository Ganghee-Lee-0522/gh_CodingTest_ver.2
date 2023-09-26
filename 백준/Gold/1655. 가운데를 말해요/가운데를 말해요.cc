#include <bits/stdc++.h>
using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, cur, mid;
	priority_queue<int> pq_f;
	priority_queue<int, vector<int>, greater<int>> pq_b;
	cin >> n >> cur;
	pq_f.emplace(cur);
	mid = cur;
	cout << cur << '\n';

	for(int i = 2; i <= n; i++) {
		cin >> cur;

		if (cur <= mid) {
			pq_f.push(cur);
		}
		else {
			pq_b.push(cur);
		}

		if (pq_f.size() > pq_b.size() + 1) {
			pq_b.push(pq_f.top());
			pq_f.pop();
		}
		else if (pq_b.size() > pq_f.size()) {
			pq_f.push(pq_b.top());
			pq_b.pop();
		}

		mid = pq_f.top();
		cout << mid << '\n';
	}

	return 0;
}