#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
vector<vector<bool>> visited;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int bfs(int x, int y, const vector<string>& maps) {
    int res = 0;
    
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    res += (maps[x][y] - '0');
    
    while(!q.empty()) {
        auto u = q.front(); q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = u.first + dx[i];
            int ny = u.second + dy[i];
            
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (maps[nx][ny] == 'X' || visited[nx][ny]) continue;
            
            res += (maps[nx][ny] - '0');
            visited[nx][ny] = true;
            q.push({nx, ny});
        }
        
    }
    
    
    
    return res;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    
    n = maps.size();
    m = maps[0].size();
    visited.resize(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && maps[i][j] != 'X') {
                int res = bfs(i, j, maps);
                answer.push_back(res);
            }
        }
    }
    if (answer.empty()) return {-1};
    sort(answer.begin(), answer.end());
    
    return answer;
}