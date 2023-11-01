#include <bits/stdc++.h>
using namespace std;

int order[26];

int solution(string skill, vector<string> skill_trees) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int answer = 0, pre = -1;
    memset(order, -1, sizeof(order));
    
    for(char c : skill) {
        order[c - 'A'] = pre;
        pre = c - 'A';
    }
    
    for(int i = 0; i < skill_trees.size(); i++) {
        bool isPossible = true;
        set<int> s;
        s.insert(-1);
        
        for(char c : skill_trees[i]) {            
            int idx = c - 'A';            
            
            while(idx != -1) {
                idx = order[idx];
                if(s.find(idx) == s.end()) {
                    isPossible = false;
                    break;
                }
            }
            
            if(!isPossible) {
                break;
            }
            else {
                s.insert(c - 'A');
            }
        }
        
        if(isPossible) {
            answer++;
        }
    }
    
    return answer;
}