#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	
	int ans = 0;
	int n = board.size();
	stack<int> s;

	for (int e : moves) {
		int pos = e - 1;

		for (int i = 0; i < n; i++) {
			if (board[i][pos] == 0)
				continue;
			
			int doll = board[i][pos];
			board[i][pos] = 0;

			if (!s.empty() && s.top() == doll) {
				s.pop();
				ans += 2;
			}
			else {
				s.push(doll);
			}
			break;
		}
	}

	return ans;
}