#include <bits/stdc++.h>

using namespace std;

int main() {

	int A, B, C, ans, freq[10] = { 0 };
	cin >> A >> B >> C;

	ans = A * B * C;
	while (ans > 0) {
		freq[ans % 10]++;
		ans /= 10;
	}

	for (int e : freq)
		cout << e << "\n";

	return 0;
}