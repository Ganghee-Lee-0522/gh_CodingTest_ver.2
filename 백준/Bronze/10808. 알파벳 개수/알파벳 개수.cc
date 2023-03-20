#include <bits/stdc++.h>

using namespace std;

int main() {
	
	string S;
	int alpha[26] = { 0 };
	cin >> S;

	for (int i = 0; i < S.length(); i++) {
		alpha[S[i] - 'a']++;
	}

	for (int i = 0; i < 26; i++) {
		cout << alpha[i] << " ";
	}
}