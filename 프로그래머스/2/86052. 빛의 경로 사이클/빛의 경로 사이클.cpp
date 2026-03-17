#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

vector<int> solution(vector<string> grid) {
    vector<int> answer;
    int n = grid.size();
    int m = grid[0].size();
    
    vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(m, vector<bool>(4, false)));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int dir = 0; dir < 4; dir++) {
                if (visited[i][j][dir]) continue;
                
                int x = i;
                int y = j;
                int d = dir;
                int len = 0;
                
                while (!visited[x][y][d]) {
                    visited[x][y][d] = true;
                    len++;
                    
                    char c = grid[x][y];
                    if (c == 'L') d = (d + 3) % 4;
                    else if (c == 'R') d = (d + 1) % 4;
                    
                    x = (x + dx[d] + n) % n;
                    y = (y + dy[d] + m) % m;
                }
                
                answer.push_back(len);
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}