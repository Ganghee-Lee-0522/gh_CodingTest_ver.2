#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, freq[10] = { 0 };
	cin >> N;

	while (N > 0) {
		freq[N % 10]++;
		N /= 10;
	}

	freq[6] = (int)((freq[6] + freq[9] + 1) / 2);
	freq[9] = 0;

	N = freq[0];
	for (int e : freq)
		if (N < e)
			N = e;
	cout << N;
}