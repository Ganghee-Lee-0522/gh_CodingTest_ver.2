#include <bits/stdc++.h>

using namespace std;

int main() {

	int N, X, temp, A[10001];

	cin >> N >> X;
	
	for(int i = 0; i < N; i++) {
		cin >> A[i];
	}

	for (int i = 0; i < N; i++) {
		if (A[i] < X) {
			cout << A[i] << " ";
		}
	}
	return 0;
}