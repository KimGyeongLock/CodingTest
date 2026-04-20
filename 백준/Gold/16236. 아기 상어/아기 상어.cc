#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

int N;
vector<vector<int>> vec;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int bfs(int sx, int sy, int ex, int ey, int size) {
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    vector<vector<int>> dist(N, vector<int>(N, 0));
    q.push({sx, sy});
    visited[sx][sy] = true;

    while(!q.empty()) {
        auto cur = q.front();
        q.pop();

        if (cur.first == ex && cur.second == ey) return dist[ex][ey];

        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (vec[nx][ny] > size) continue;
            if (visited[nx][ny]) continue;

            q.push({nx, ny});
            visited[nx][ny] = true;
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
        }
    }

    return -1;
}

int main()
{
    cin >> N;

    vec.resize(N, vector<int>(N));
    pair<int, int> baby;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> vec[i][j];
            if (vec[i][j] == 9) {
                baby = {i, j};
                vec[i][j] = 0;
            }
        }
    }
    
    int time = 0;
    int size = 2;
    int eat = 0;
    while (true) {

        vector<pair<int, int>> pos;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (size > vec[i][j] && vec[i][j] > 0) {
                    pos.push_back({i, j});
                }
            }
        }
        if (pos.empty()) break;

        int min_dist = INT_MAX;
        pair<int, int> min_pos;
        for (auto p : pos) {
            int dist = bfs(baby.first, baby.second, p.first, p.second, size);
            if (dist > -1 && min_dist > dist) {
                min_dist = dist;
                min_pos = {p.first, p.second};
            }
        }
        if (min_dist == INT_MAX) break;

        baby = min_pos;
        time += min_dist;
        vec[min_pos.first][min_pos.second] = 0;
        eat++;
        if (eat == size) {
            size++;
            eat = 0;
        }
    }

    cout << time;
}