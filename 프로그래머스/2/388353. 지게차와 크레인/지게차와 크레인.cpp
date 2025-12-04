#include <string>
#include <vector>
#include <queue>

using namespace std;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int n, m;
void markOutsideSpaces(const vector<string>& g, vector<vector<bool>>& outside) {
    outside.assign(n, vector<bool>(m, false));
    queue<pair<int, int>> q;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == ' ' && (i == 0 || i == n-1 || j == 0 || j == m-1)) {
                outside[i][j] = true;
                q.push({i, j});
            }
        }
    }
    
    while(!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (!(nx >= 0 && nx < n && ny >= 0 && ny < m)) continue;
            if (g[nx][ny] != ' ' || outside[nx][ny]) continue;
            outside[nx][ny] = true;
            q.push({nx, ny});
        }
    }
    
}

int solution(vector<string> storage, vector<string> requests) {
    int answer = 0;
    n = storage.size();
    m = storage[0].size();
    for (string r : requests) {
        int len = r.length();
        int c = r[0];
        if (len == 1) {
            vector<vector<bool>> outside;
            markOutsideSpaces(storage, outside);
            
            vector<pair<int, int>> willRemove;
            
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (storage[i][j] != c) continue;
                    
                    if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                        willRemove.push_back({i, j});
                        continue;
                    }
                    
                    bool accessible = false;
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = i + dx[dir];
                        int ny = j + dy[dir];
                        if (!(nx >= 0 && nx < n && ny >= 0 && ny < m)) continue;
                        if (storage[nx][ny] == ' ' && outside[nx][ny]) {
                            accessible = true;
                            break;
                        }
                    }
                    if (accessible) willRemove.push_back({i, j});
                }
            }
            
            for (auto [x, y] : willRemove) {
                storage[x][y] = ' ';
            }
        } else {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (storage[i][j] == c) storage[i][j] = ' ';
                }
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (storage[i][j] != ' ') answer++;
        }
    }
    return answer;
}