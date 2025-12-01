#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

const int MOD = 1000000007;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    
    dp[1][1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == 1 && j == 1) continue;
            vector<int> vec = {j, i};
            if (find(puddles.begin(), puddles.end(), vec) != puddles.end()) continue;
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
        }
    }
    
    return dp[n][m];
}