#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int solution(vector<vector<int>> land) {
    int n = land.size();
    int m = land[0].size();
    
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<int> colSum(m, 0);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (land[i][j] != 1 || visited[i][j]) continue;
            
            int cnt = 0;
            vector<bool> colVisited(m, false);
            queue<pair<int, int>> q;
            
            q.push({i, j});
            visited[i][j] = true;
            
            while(!q.empty()) {
                auto [r, c] = q.front();
                q.pop();
                
                cnt++;
                colVisited[c] = true;
                
                for (int dir = 0; dir < 4; dir++) {
                    int nr = r + dy[dir];
                    int nc = c + dx[dir];
                    
                    if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                    if (land[nr][nc] == 1 && !visited[nr][nc]) {
                        visited[nr][nc] = true;
                        q.push({nr, nc});
                    } 
                }
            }
            
            for (int col = 0; col < m; col++) {
                if (colVisited[col]) {
                    colSum[col] += cnt;
                }
            }
        }
    }
    
    return *max_element(colSum.begin(), colSum.end());
}