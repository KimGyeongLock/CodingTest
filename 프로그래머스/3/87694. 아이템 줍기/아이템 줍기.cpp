#include <string>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
 
int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int MAX = 102;
    vector<vector<int>> board(MAX, vector<int>(MAX, 0));
    
    for (auto& r : rectangle) {
        int x1 = r[0] * 2, y1 = r[1] * 2, x2 = r[2] * 2, y2 = r[3] * 2;
        for (int i = x1; i <= x2; i++) {
            for (int j = y1; j <= y2; j++) board[i][j] = 1;
        }
    }
    
    for (auto& r : rectangle) {
        int x1 = r[0] * 2, y1 = r[1] * 2, x2 = r[2] * 2, y2 = r[3] * 2;
        for (int i = x1 + 1; i < x2; i++) {
            for (int j = y1 + 1; j < y2; j++) board[i][j] = 0;
        }
    }
    
    int sx = characterX * 2, sy = characterY * 2;
    int tx = itemX * 2, ty = itemY * 2;
    
    queue<pair<int, int>> q;
    q.push({sx, sy});
    
    vector<vector<int>> dist(MAX, vector<int>(MAX, -1));
    dist[sx][sy] = 0;
    
    while(!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        
        if (x == tx && y == ty) break;
        
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= MAX || ny < 0 || ny >= MAX) continue;
            if (board[nx][ny] == 0) continue;
            if (dist[nx][ny] != -1) continue;
            q.push({nx, ny});
            dist[nx][ny] = dist[x][y] + 1;
        }
    }
    
    return dist[tx][ty] / 2;
}