#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll multi(ll A, ll B, ll C) {
	if (B == 1)
		return A % C;
	ll val = multi(A, B / 2, C);
	val = val * val % C;
	if (B % 2 == 0)
		return val;
	return val * A % C;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll A, B, C;
	cin >> A >> B >> C;
	cout << multi(A, B, C);

	return 0;
}