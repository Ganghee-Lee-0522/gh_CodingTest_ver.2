#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    vector<int> cnt(n + 1, 0);
    set<string> s;
    char pre = words[0][0];
    
    for(int i = 0; i < words.size(); i++) {
        
        // 번호 구하기
        int idx = i % n + 1;
        // 차례 count
        cnt[idx]++;
        
        if(!s.empty()) {
            // 새로운 단어 중복 체크
            set<string>::iterator iter;
            iter = s.find(words[i]);

            // 중복 or 끝말잇기 실패 시 번호와 차례 반환
            if(iter != s.end() || pre != words[i][0]) {
                answer.push_back(idx);
                answer.push_back(cnt[idx]);
                return answer;
            }
        }
        
        // 맨 마지막 원소 위치 구하기
        int len = words[i].length() - 1;
        // 맨 마지막 알파벳 구하기
        pre = words[i][len];
        // 단어 삽입
        s.insert(words[i]);
    }
    
    answer.push_back(0);
    answer.push_back(0);

    return answer;
}