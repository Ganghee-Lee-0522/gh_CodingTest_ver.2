#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> nums) {
    int answer = 0;
    vector<int> v(3000, -1);
    v[0] = 0;
    v[1] = 0;
    
    // 3000 미만 소수 찾기
    for(int i = 3; i < 3000; i++) {
        for(int j = 2; j < i; j++) {
            if(i % j == 0) {
                v[i] = 0;
                break;
            }
        }
    }

    // 숫자를 세 개씩 조합해보며 찾기
    for(int i = 0; i < nums.size() - 2; i++) {
        for(int j = i + 1; j < nums.size() - 1; j++) {
            for(int k = j + 1; k < nums.size(); k++) {
                
                int sum = nums[i] + nums[j] + nums[k];
                
                if(v[sum] < 0) {
                    answer++;
                }
            }
        }
    }

    return answer;
}