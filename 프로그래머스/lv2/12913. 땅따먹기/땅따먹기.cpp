#include <bits/stdc++.h>
using namespace std;

int board[100005][5];

int solution(vector<vector<int> > land)
{
    int answer = 0;
    
    board[1][1] = land[0][0];
    board[1][2] = land[0][1];
    board[1][3] = land[0][2];
    board[1][4] = land[0][3];

    for(int i = 1; i <= land.size(); i++) {
        board[i][1] = max(board[i - 1][2], board[i - 1][3]) + land[i - 1][0];
        board[i][1] = max(board[i][1], board[i - 1][4] + land[i - 1][0]);
        
        board[i][2] = max(board[i - 1][1], board[i - 1][3]) + land[i - 1][1];
        board[i][2] = max(board[i][2], board[i - 1][4] + land[i - 1][1]);
        
        board[i][3] = max(board[i - 1][1], board[i - 1][2]) + land[i - 1][2];
        board[i][3] = max(board[i][3], board[i - 1][4] + land[i - 1][2]);
        
        board[i][4] = max(board[i - 1][1], board[i - 1][2]) + land[i - 1][3];
        board[i][4] = max(board[i][4], board[i - 1][3] + land[i - 1][3]);
    }
    
    answer = max(board[land.size()][1], board[land.size()][2]);
    answer = max(answer, board[land.size()][3]);
    answer = max(answer, board[land.size()][4]);

    return answer;
}