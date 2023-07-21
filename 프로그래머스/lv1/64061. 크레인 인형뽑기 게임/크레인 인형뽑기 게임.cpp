#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	
	int ans = 0; // 사라진 인형 개수 count
	int n = board.size(); // 격자 높이
	stack<int> s;

	// 크레인 작동
	for (int e : moves) {
		int pos = e - 1; // 크레인 작동 위치

		for (int i = 0; i < n; i++) { // 행(작을수록 높은 위치)
			if (board[i][pos] == 0) // 해당 행에 인형 X -> 아래로!
				continue;
			
			// 인형 잡기
			int doll = board[i][pos];
			board[i][pos] = 0;

			if (!s.empty() && s.top() == doll) {
				s.pop(); // stack에서 인형 팡!
				ans += 2; // 쌍으로 터져야 하니까 2개씩 count
			}
			else { // 다른 종류의 인형은 stack에 적재
				s.push(doll);
			}
			break;
		}
	}

	return ans;
}