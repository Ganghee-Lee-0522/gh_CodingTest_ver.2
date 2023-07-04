#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int board[105][105];

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int n = maps.size();
    int m = maps[0].size();
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            board[i][j] = -1;
        }
    }
    queue<pair<int, int>> q;
    q.push({1, 1});
    board[1][1] = 1;
    
    while(!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        for(int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if(nx <= 0 || nx > n || ny <= 0 || ny > m) {
                continue;
            }
            if(board[nx][ny] >= 0 || maps[nx - 1][ny - 1] == 0) {
                continue;
            }
            q.push({nx, ny});
            board[nx][ny] = board[cur.X][cur.Y] + 1;
        }
    }
    
    if(board[n][m] < 0) {
        return -1;
    }
    else {
        return board[n][m];
    }
}