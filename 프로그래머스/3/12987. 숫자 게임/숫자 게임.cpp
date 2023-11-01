#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0, idx = -1;
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    for(int e : A) {
        idx++;
        while(e >= B[idx] && idx < B.size()) {
            idx++;
        }
        if(e >= B[idx]) {
            return answer;
        }
        answer++;
    }
    
    return answer;
}