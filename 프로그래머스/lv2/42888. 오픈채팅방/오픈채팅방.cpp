#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> user;
    queue<pair<string, string>> q;
    
    for(string r : record) {
        stringstream ss(r);
        string sub;
        vector<string> tokens;

        while(ss >> sub) {
            tokens.push_back(sub);
        }
        if(tokens[0] == "Enter") { // 입장
            if(user.find(tokens[1]) != user.end()) { // 재입장 유저일 때
                user.at(tokens[1]) = tokens[2]; // 닉네임 변경
            }
            else { // 처음 들어온 유저일 때
                user.insert({tokens[1], tokens[2]}); // 닉네임 추가
            }
            // 최초 입장, 재입장 모두 기록을 남겨야 함!
            q.push({tokens[1], "님이 들어왔습니다."}); // 기록 저장
        }
        else if(tokens[0] == "Leave") { // 퇴장
            q.push({tokens[1], "님이 나갔습니다."}); // 기록 저장
        }
        else { // 닉변
            user.at(tokens[1]) = tokens[2]; // 닉네임 수정
        }
    }
    
    while(!q.empty()) {
        pair<string, string> cur = q.front(); q.pop();
        string nickname = user.at(cur.X);
        answer.push_back(nickname + cur. Y);
    }
    return answer;
}