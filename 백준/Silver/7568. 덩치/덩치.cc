#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    vector<int> grade;
    cin >> N;
    
    vector<vector<int>> v1;
    
    for (int i = 0; i < N; i++) {
        int x, y;
        vector<int> v2;
        cin >> x >> y;
        v2.push_back(x);
        v2.push_back(y);
        v1.push_back(v2);
    }
    
    for(int i = 0; i < N; i++) {
        int temp = 1;
        for(int j = 0; j < N; j++) {
            if(v1[i][0] < v1[j][0] && v1[i][1] < v1[j][1]) {
                temp += 1;
            }
        }
        grade.push_back(temp);
    }
    
    for(int i = 0; i < grade.size(); i++) {
        cout << grade[i] << " ";
    }

    return 0;
}