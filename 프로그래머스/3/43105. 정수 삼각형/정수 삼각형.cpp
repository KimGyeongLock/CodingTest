#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int a = triangle.size();
    int b = triangle[a-1].size();
    vector<vector<int>> dp(a, vector<int>(b));
    
    dp[0][0] = triangle[0][0];
    for (int i = 1; i < a; i++) {
        for (int j = 0; j < triangle[i].size(); j++) {
            if (j == 0) dp[i][j] = dp[i-1][j] + triangle[i][j];
            else if (j == i) dp[i][j] = dp[i-1][j-1] + triangle[i][j];
            else dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];
        }
    }
    
    for (int i : dp[a-1]) {
        answer = max(answer, i);
    }
    return answer;
}