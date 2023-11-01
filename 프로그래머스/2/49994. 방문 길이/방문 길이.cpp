#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[11][11][4];
int dirX[4] = {-1, 0, 0, 1};
int dirY[4] = {0, 1, -1, 0};

int solution(string dirs) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int answer = 0;
    memset(board, -1, sizeof(board));
    pair<int, int> cur = {5, 5};
    
    for(char c : dirs) {
        int idx;        
        if(c == 'U') { // 위쪽으로 한 칸 가기
            idx = 0;
        }
        else if(c == 'D') { // 아래쪽으로 한 칸 가기
            idx = 3;
        }
        else if(c == 'R') { // 오른쪽으로 한 칸 가기
            idx = 1;
        }
        else { // 왼쪽으로 한 칸 가기
            idx = 2;
        }
        
        int nx = cur.X + dirX[idx];
        int ny = cur.Y + dirY[idx];
        
        if(nx > 10 || ny > 10 || nx < 0 || ny< 0) { // out of board
            continue;
        }
        
        if(board[cur.X][cur.Y][idx] < 0) {
            board[cur.X][cur.Y][idx] = 1;
            idx = 3 - idx;
            board[nx][ny][idx] = 1;
            answer++;
        }
        
        cur.X = nx;
        cur.Y = ny;
    }  
    
    return answer;
}