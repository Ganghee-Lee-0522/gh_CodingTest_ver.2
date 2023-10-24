#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> q;
    for(int e : d) {
        q.push(e);
    }
    while(!q.empty()) {
        int cur = q.top();
        q.pop();
        if(cur > budget) {
            break;
        }
        budget -= cur;
        answer++;
    }
    return answer;
}