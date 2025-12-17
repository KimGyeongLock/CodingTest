#include <string>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m;
bool out(int x, int y) {
    return x < 0 || x >= n || y < 0 || y >= m;
}

int solution(vector<string> board) {
    pair<int, int> R, G;
    n = board.size();
    m = board[0].size();
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 'R') R = {i, j};
            if (board[i][j] == 'G') G = {i, j};
        }
    }
    
    vector<vector<int>> dist(n, vector<int>(m, -1));
    dist[R.first][R.second] = 0;
    queue<pair<int, int>> q;
    q.push(R);
    
    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        int x = cur.first, y = cur.second;
        
        if (cur == G) return dist[x][y];
        
        for (int i = 0; i < 4; i++) {
            int nx = x;
            int ny = y;
            
            while(true) {
                int tx = nx + dx[i];
                int ty = ny + dy[i];
                
                if (out(tx, ty) || board[tx][ty] == 'D') break;
                nx = tx;
                ny = ty;
            }
            
            if (nx == x && ny == y) continue;
            if (dist[nx][ny] != -1) continue;
            
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }
    
    
    return -1;
}