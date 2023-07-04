#include <bits/stdc++.h>
using namespace std;

int answer = 0;

void dfs(vector<int> numbers, int target, int depth, int cur) {
    if(depth == numbers.size()) {
        if(target == cur) {
            answer++;
        }
        return;
    }
    dfs(numbers, target, depth + 1, cur + numbers[depth]);
    dfs(numbers, target, depth + 1, cur - numbers[depth]);
}

int solution(vector<int> numbers, int target) {
    dfs(numbers, target, 0, 0);
    
    return answer;
}