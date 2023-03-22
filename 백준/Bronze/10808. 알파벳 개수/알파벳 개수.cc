#include <bits/stdc++.h>

using namespace std;

int main() {
	string S;
	int alpha[26] = { 0 };
	cin >> S;

	for (char e : S)
		alpha[e - 'a']++;

	for (int i = 0; i < 26; i++)
		cout << alpha[i] << ' ';

	return 0;
}