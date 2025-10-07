#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

inline bool has(const vector<vector<int>>& b, int x, int y, int n) {
    return (0 <= x && x <= n && 0 <= y && y <= n) && b[y][x] == 1;
}

bool canBuildPillar(const vector<vector<int>>& b1, const vector<vector<int>>& b2, int x, int y, int n) {
    if (y == 0) return true;
    if (y > 0 && has(b1, x, y - 1, n)) return true;
    if (has(b2, x, y, n)) return true;
    if (x > 0 && has(b2, x - 1, y, n)) return true;
    return false;
}

bool canBuildBeam(const vector<vector<int>>& b1, const vector<vector<int>>& b2, int x, int y, int n) {
    if (y > 0 && has(b1, x, y - 1, n)) return true;
    if (y > 0 && x + 1 <= n && has(b1, x + 1, y - 1, n)) return true;
    if (x > 0 && x + 1 <= n && has(b2, x - 1, y, n) && has(b2, x + 1, y, n)) return true;
    return false;
}

bool validAround(const vector<vector<int>>& b1, const vector<vector<int>>& b2, int x, int y, int n) {
    for (int i = max(0, x - 1); i <= min(n, x + 1); i++) {
        for (int j = max(0, y - 1); j <= min(n, y + 1); j++) {
            if (has(b1, i, j, n) && !canBuildPillar(b1, b2, i, j, n)) return false;
            if (has(b2, i, j, n) && !canBuildBeam(b1, b2, i, j, n)) return false; 
        }
    }
    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    vector<vector<int>> board(n+1, vector<int>(n+1, 0));
    vector<vector<int>> board2(n+1, vector<int>(n+1, 0));
    
    for (auto bf : build_frame) {
        int x = bf[0], y = bf[1], a = bf[2], b = bf[3];
        
        if (b == 1) { // 설치
            if (a == 0) { // 기둥
                if (canBuildPillar(board, board2, x, y, n)) board[y][x] = 1;
            } else { // 보
                if (canBuildBeam(board, board2, x, y, n)) board2[y][x] = 1;
            }
            
        } else { // 삭제
            if (a == 0) {
                board[y][x] = 0;
                if (!validAround(board, board2, x, y, n)) board[y][x] = 1;
            } else {
                board2[y][x] = 0;
                if (!validAround(board, board2, x, y, n)) board2[y][x] = 1;
            }
        }
    }
    
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (board[i][j] == 1) answer.push_back({j, i, 0});
            if (board2[i][j] == 1) answer.push_back({j, i, 1});
        }
    }
    sort (answer.begin(), answer.end());
    return answer;
}