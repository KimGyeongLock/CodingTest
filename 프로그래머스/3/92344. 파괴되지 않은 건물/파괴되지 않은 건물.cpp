#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int n = board.size();
    int m = board[0].size();
    vector<vector<int>> diff(n + 1, vector<int>(m + 1, 0));
        
    for (auto& s : skill) {
        int type = s[0];
        int r1 = s[1];
        int c1 = s[2];
        int r2 = s[3];
        int c2 = s[4];
        int degree = s[5];
        
        if (type == 1) degree = -degree;
        
        diff[r1][c1] += degree;
        diff[r1][c2+1] -= degree;
        diff[r2 + 1][c1] -= degree;
        diff[r2 + 1][c2 + 1] += degree;
    }
    
    for (int i = 0; i < n; i++) {
        int run = 0;
        for (int j = 0; j < m; j++) {
            run += diff[i][j];
            diff[i][j] = run;
        }
    }
    
    for (int j = 0; j < m; j++) {
        int run = 0;
        for (int i = 0; i < n; i++) {
            run += diff[i][j];
            diff[i][j] = run;
        }
    }
    
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] + diff[i][j] >= 1) cnt++;
        }
    }
    return cnt;
}