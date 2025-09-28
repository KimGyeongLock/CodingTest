#include <string>
#include <vector>
#include <climits>

using namespace std;

struct Outcome {
    bool win;
    int moves;
};

int n, m;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

Outcome dfs(vector<vector<int>>& board, int ax, int ay, int bx, int by) {
    if (board[ax][ay] == 0) return {false, 0};
    
    bool canMove = false;
    Outcome bestWin = {true, INT_MAX};
    Outcome bestLose = {false, 0};
    
    for (int k = 0; k < 4; k++) {
        int nx = ax + dx[k], ny = ay + dy[k];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (board[nx][ny] == 0) continue;
        
        canMove = true;
        
        board[ax][ay] = 0;
        Outcome child = dfs(board, bx, by, nx, ny);
        board[ax][ay] = 1;
        
        if (!child.win) { //상대 패배
            Outcome cand = {true, child.moves + 1};
            if (cand.moves < bestWin.moves) bestWin = cand;
        } else {
            Outcome cand = {false, child.moves + 1};
            if (cand.moves > bestLose.moves) bestLose = cand;
        }
    }
    
    if (!canMove) return {false, 0};
    if (bestWin.moves != INT_MAX) return bestWin;
    return bestLose;
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    n = (int)board.size();
    m = (int)board[0].size();
    Outcome res = dfs(board, aloc[0], aloc[1], bloc[0], bloc[1]);
    return res.moves;
}