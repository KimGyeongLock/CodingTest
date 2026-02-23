#include <string>
#include <vector>
#include <climits>

using namespace std;

struct Result {
    bool win;
    int moves;
};

int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

Result dfs(vector<vector<int>>& board, int cx, int cy, int ox, int oy) {
    if (board[cx][cy] == 0) return {false, 0};
    
    bool canMove = false;

    int bestWin = INT_MAX;
    int bestLose = 0;
    
    for (int dir = 0; dir < 4; dir++) {
        int nx = cx + dx[dir];
        int ny = cy + dy[dir];
        
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (board[nx][ny] == 0) continue;
        
        canMove = true;
        
        board[cx][cy] = 0;
        Result child = dfs(board, ox, oy, nx, ny);
        board[cx][cy] = 1;
        
        if (child.win) {
            bestLose = max(bestLose, child.moves + 1);
        } else {
            bestWin = min(bestWin, child.moves + 1);
        }
    }
    
    if (!canMove) return {false,  0};
    if (bestWin == INT_MAX) return {false, bestLose};
    return {true, bestWin};
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    n = board.size();
    m = board[0].size();
    
    Result ans = dfs(board, aloc[0], aloc[1], bloc[0], bloc[1]);
    return ans.moves;
}