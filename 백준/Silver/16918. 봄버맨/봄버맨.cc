#include <bits/stdc++.h>

using namespace std;

int bomb[205][205];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int main()
{
    char ch;
    int r, c, n;
    cin >> r >> c >> n;

    for (int i = 0; i < r; i++) {
        string st;
        cin >> st;
        for (int j = 0; j < st.size(); j++) {
            if (st[j] == '.') {
                bomb[i][j] = -1;
            }
            else {
                bomb[i][j] = 3;
            }
        }
    }

    for (int t = 2; t <= n; t++) {
        if (t % 2 == 0) {
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    if (bomb[i][j] == -1) {
                        bomb[i][j] = t + 3;
                    }
                }
            }
        }
        else {
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    if (bomb[i][j] == t) {
                        bomb[i][j] = -1;
                        for (int dir = 0; dir < 4; dir++) {
                            int curX = dy[dir] + i;
                            int curY = dx[dir] + j;

                            if (curX < 0 || curY < 0 || curX >= r || curY >= c) {
                                continue;
                            }
                            if (bomb[curX][curY] == t) {
                                continue;
                            }

                            bomb[curX][curY] = -1;
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (bomb[i][j] == -1) {
                cout << '.';
            }
            else {
                cout << 'O';
            }
        }
        cout << '\n';
    }

    return 0;
}