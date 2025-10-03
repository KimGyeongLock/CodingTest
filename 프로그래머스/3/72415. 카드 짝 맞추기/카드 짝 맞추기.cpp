#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

const int N = 4;
int answer = INT_MAX;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

pair<int, int> ctrlMove(vector<vector<int>>& board, int x, int y, int dir) {
    int nx = x, ny = y;
    while(true) {
        int tx = nx + dx[dir], ty = ny + dy[dir];
        if (tx < 0 || tx >= N || ty < 0 || ty >= N) return {nx, ny};
        nx = tx; ny = ty;
        if (board[nx][ny] != 0) return {nx, ny};
    }
}

int distBFS(vector<vector<int>>& board, int cx, int cy, int tx, int ty) {
    if (cx == tx && cy == ty) return 0;
    vector<vector<int>> dist(N, vector<int>(N, INT_MAX));
    queue<pair<int, int>> q;
    dist[cx][cy] = 0;
    q.push({cx, cy});
    
    while(!q.empty()) {
        auto [x, y] = q.front(); q.pop();        
        int d = dist[x][y];
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < N && ny >= 0 && ny < N && dist[nx][ny] == INT_MAX) {
                dist[nx][ny] = d + 1;
                if (nx == tx && ny == ty) return dist[nx][ny];
                q.push({nx, ny});
            }
            
            auto [sx, sy] = ctrlMove(board, x, y, i);
            if (dist[sx][sy] == INT_MAX) {
                dist[sx][sy] = d + 1;
                if (sx == tx && sy == ty) return dist[sx][sy];
                q.push({sx, sy});
            }
        }
    }
    return INT_MAX;
}

void dfs(   int idx,
            int curx, int cury,
            vector<int>& kind,
            vector<vector<int>>& board,
            const vector<vector<pair<int, int>>>& pos,
            int curCost) 
{
    if (curCost >= answer) return;
    if (idx == kind.size()) {
        answer = min(answer, curCost);
        return;
    }
    int card = kind[idx];
    auto p = pos[card];
    auto p1 = p[0];
    auto p2 = p[1];
    {
        int c1 = distBFS(board, curx, cury, p1.first, p1.second);
        int c2 = distBFS(board, p1.first, p1.second, p2.first, p2.second);
        int add = c1 + c2 + 2;
        
        int v1 = board[p1.first][p1.second];
        int v2 = board[p2.first][p2.second];
        board[p1.first][p1.second] = 0;
        board[p2.first][p2.second] = 0;
        
        dfs(idx + 1, p2.first, p2.second, kind, board, pos, curCost + add);
        
        board[p1.first][p1.second] = v1;
        board[p2.first][p2.second] = v2;
    }
    
    {
        int c1 = distBFS(board, curx, cury, p2.first, p2.second);
        int c2 = distBFS(board, p2.first, p2.second, p1.first, p1.second);
        int add = c1 + c2 + 2;
        
        int v1 = board[p1.first][p1.second];
        int v2 = board[p2.first][p2.second];
        board[p1.first][p1.second] = 0;
        board[p2.first][p2.second] = 0;
        
        dfs(idx + 1, p1.first, p1.second, kind, board, pos, curCost + add);
        
        board[p1.first][p1.second] = v1;
        board[p2.first][p2.second] = v2;
    }
}

int solution(vector<vector<int>> board, int r, int c) {
    vector<vector<pair<int, int>>> pos(7);
    vector<int> seen(7, 0);
    vector<int> kind;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int v = board[i][j];
            if (v) {
                pos[v].push_back({i, j});
                if (!seen[v]) {
                    kind.push_back(v);
                    seen[v] = 1;
                }
            }
        }
    }
    
    sort(kind.begin(), kind.end());
    
    do {
        vector<vector<int>> b = board;
        dfs(0, r, c, kind, b, pos, 0);
    } while(next_permutation(kind.begin(), kind.end()));
    return answer;
}