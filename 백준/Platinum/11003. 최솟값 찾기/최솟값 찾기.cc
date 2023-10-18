#include <bits/stdc++.h>
using namespace std;
#define INF 5000005;

struct s {
	int k;
	int idx;

	s(int num, int cnt) : k(num), idx(cnt) {}
};

struct cmp {
	bool operator()(s a, s b) {
		return a.k > b.k; // key값 작은 것이 우선하도록 리턴
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, l, tmp;
	priority_queue<s, vector<s>, cmp> pq;

	cin >> n >> l;
	vector<int> ans;

	for (int i = 1; i <= n; i++) {
		cin >> tmp;
		pq.push(s(tmp, i));
		
		while (pq.top().idx <= i - l) {
			pq.pop();
		}

		ans.push_back(pq.top().k);
	}

	for (auto e : ans) {
		cout << e << ' ';
	}

	return 0;
}