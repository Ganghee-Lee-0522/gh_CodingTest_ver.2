#include <bits/stdc++.h>
using namespace std;

int delta[2] = {1, -1};

int solution(vector<int> numbers, int target) {
    int answer = 0;
    queue<int> oldq;
    queue<int> newq;
    int cur, nxt;
    oldq.push(0);
    for(int n : numbers) {
        while(!oldq.empty()) {
            cur = oldq.front(); oldq.pop();
            for(int i = 0; i < 2; i++) {
                nxt = cur + n * delta[i];
                newq.push(nxt);
            }
        }
        while(!newq.empty()) {
            cur = newq.front(); newq.pop();
            oldq.push(cur);
        }
    }
    
    while(!oldq.empty()) {
        cur = oldq.front(); oldq.pop();
        if(cur == target) {
            answer++;
        }
    }
    return answer;
}