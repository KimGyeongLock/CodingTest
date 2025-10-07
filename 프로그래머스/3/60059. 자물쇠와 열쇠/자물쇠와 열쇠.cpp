#include <string>
#include <vector>

using namespace std;

vector<vector<int>> rotate90(const vector<vector<int>>& key) {
    int n = key.size();
    vector<vector<int>> res(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res[j][n - i - 1] = key[i][j];
        }
    }
    return res;
}

bool checkCenterIsAllOne(const vector<vector<int>>& board, int m, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[m - 1 + i][m - 1 + j] != 1) return false;
        }
    }
    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int m = key.size();
    int n = lock.size();
    
    int B = n + 2 * (m - 1);
    vector<vector<int>> board(B, vector<int>(B, 0));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            board[m - 1 + i][m - 1 + j] = lock[i][j];
        }
    }
    
    for (int rot = 0; rot < 4; rot++) {
        for (int x = 0; x <= B - m; x++) {
            for (int y = 0; y <= B - m; y++) {
                
                for (int i = 0; i < m; i++) {
                    for (int j = 0; j < m; j++) {
                        board[x + i][y + j] += key[i][j];
                    }
                }
                
                if (checkCenterIsAllOne(board, m, n)) return true;
                
                for (int i = 0; i < m; i++) {
                    for (int j = 0; j < m; j++) {
                        board[x + i][y + j] -= key[i][j];
                    }
                }
            }
        }
        key = rotate90(key);
    }
    
    return false;
}