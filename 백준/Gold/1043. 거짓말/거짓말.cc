#include <bits/stdc++.h>

using namespace std;
int parent[51] = { -1, };
bool knowsTruth[51] = { false, };

// Find 연산
int Find(int node) {
	if (parent[node] == -1) {
		return node;
	}
	return Find(parent[node]);
}

// Union 연산
void Union(int x, int y) {
	x = Find(x);
	y = Find(y);

	if (x == y) {
		return; // 이미 같은 그룹
	}
	if (knowsTruth[x]) {
		parent[y] = x; // 진실을 아는 사람을 부모로 삼기
	}
	else if (knowsTruth[y]) {
		parent[x] = y;
	}
	else {
		// 둘 다 진실을 모름
		parent[x] = y;
	}
}

int countGroups(int m, vector<vector<int>> party) {
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		int r = Find(party[i][0]);
		if (!knowsTruth[r])
			cnt++;
	}
	return cnt;
}

int solution(int n, int m, vector<int> truth, vector<vector<int>> party) {
	// 정점들의 부모를 -1로 초기화
	for (int i = 1; i <= n; i++) {
		parent[i] = -1;
	}

	// 진실을 아는 사람 표시
	for (int e : truth) {
		knowsTruth[e] = true;
	}

	// 각 파티마다 정점들끼리 Union 연산
	for (int i = 0; i < m; i++) {
		int fp = party[i][0];
		for (int e : party[i]) {
			Union(fp, e);
		}
	}

	// 거짓말을 할 수 있는 파티의 개수 세기
	return countGroups(m, party);
}

int main() {
	int n, m, init;
	//입력
	cin >> n >> m >> init;
	vector<int> truth;
	vector<vector<int>> party(m);

	while (init--) {
		int p; cin >> p;
		truth.push_back(p);
	}
	for (int i = 0; i < m; i++) {
		int sz; cin >> sz;
		while (sz--) {
			int x; cin >> x;
			party[i].push_back(x);
		}
	}
	//연산 & 출력
	cout << solution(n, m, truth, party);

	return 0;
}