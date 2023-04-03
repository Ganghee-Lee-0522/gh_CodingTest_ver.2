#include <bits/stdc++.h>

using namespace std;

int board[100002];

int main() {

	int N, K;
	queue<int> q;
	cin >> N >> K;

	fill(board, board + 100001, -1);

	board[N] = 0;
	q.push(N);

	while (board[K] == -1) {
		int cur = q.front();
		q.pop();

		for (int nxt : {cur - 1, cur + 1, 2 * cur}) {
			if (nxt < 0 || nxt > 100000)
				continue;
			if (board[nxt] != -1)
				continue;
			board[nxt] = board[cur] + 1;
			q.push(nxt);
		}
	}
	cout << board[K];

	return 0;
}