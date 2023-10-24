#include <bits/stdc++.h>
using namespace std;
#define MAX 2100000000

int solution(int n)
{
    int ans = 0;
    
    while(n > 0) {
        // 짝수일 때
        if(n % 2 == 0) {
            n /= 2;
        }
        // 홀수일 떄
        else {
            n -= 1;
            ans++;
        }
    }
    return ans;
}