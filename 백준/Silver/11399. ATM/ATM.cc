#include <bits/stdc++.h>

using namespace std;

int main() {

	int N, temp = 0, P[1001] = { 0 };
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> P[i];

	sort(P, P + N);
	
	for (int i = 0; i < N; i++)
		temp += P[i] * (N - i);

	cout << temp;

	return 0;
}