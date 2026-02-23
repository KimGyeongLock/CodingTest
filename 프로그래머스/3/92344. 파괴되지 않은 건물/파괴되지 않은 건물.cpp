#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int n = board.size();
    int m = board[0].size();
    
    vector<vector<int>> diff(n+2, vector<int>(m+2, 0));
     
    for (auto s : skill) {
        int type = s[0], r1 = s[1], c1 = s[2], r2 = s[3], c2 = s[4];
        int degree = (type == 1) ? -s[5] : s[5];
        
        diff[r1][c1] += degree;
        diff[r1][c2 + 1] -= degree;
        diff[r2 + 1][c1] -= degree;
        diff[r2 + 1][c2 + 1] += degree;
    }
    
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            diff[i + 1][j] += diff[i][j];
        }
    }
    
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            diff[i][j + 1] += diff[i][j];
        }
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(board[i][j] + diff[i][j] > 0) ans++;
        }
    }
    
    return ans;
}