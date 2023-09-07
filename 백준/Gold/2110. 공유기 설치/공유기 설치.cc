#include <bits/stdc++.h>
using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, c;
	cin >> n >> c;
	vector<int> house(n);

	for (int i = 0; i < n; i++) {
		cin >> house[i];
	}

	sort(house.begin(), house.end());

	int left = 1; // 최소 간격
	int right = house[n - 1] - house[0]; // 최대 간격
	int ans = 0;

	while (left <= right) {
		int mid = (left + right) / 2;
		int cnt = 1;
		int pre = house[0];

		for (int e : house) {
			if (e - pre >= mid) {
				cnt++;
				pre = e;
			}
		}

		if (cnt >= c) {
			ans = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	cout << ans;

	return 0;
}