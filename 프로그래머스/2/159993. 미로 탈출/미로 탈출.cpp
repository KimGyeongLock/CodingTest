#include <string>
#include <vector>
#include <queue>

using namespace std;

int bfs(const vector<string>& maps, pair<int,int> start, char target) {
    int n = (int)maps.size();
    int m = (int)maps[0].size();
    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<pair<int,int>> q;

    dist[start.first][start.second] = 0;
    q.push(start);

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();

        if (maps[x][y] == target) return dist[x][y];

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (maps[nx][ny] == 'X') continue;         // 벽
            if (dist[nx][ny] != -1) continue;          // 방문됨

            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }
    return -1; // target 도달 불가
}

int solution(vector<string> maps) {
    int n = (int)maps.size();
    int m = (int)maps[0].size();

    pair<int,int> S{-1,-1}, L{-1,-1};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (maps[i][j] == 'S') S = {i, j};
            else if (maps[i][j] == 'L') L = {i, j};
        }
    }

    int d1 = bfs(maps, S, 'L');   // S -> L
    if (d1 == -1) return -1;

    int d2 = bfs(maps, L, 'E');   // L -> E
    if (d2 == -1) return -1;

    return d1 + d2;
}
