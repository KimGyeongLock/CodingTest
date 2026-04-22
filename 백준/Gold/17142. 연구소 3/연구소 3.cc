#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

int N, M;
int answer = INT_MAX;
vector<vector<int>> board;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1}; 

int bfs(vector<pair<int, int>> pick) {
    queue<pair<int, int>> q;
    vector<vector<int>> dist(N, vector<int>(N, -1));
    for (auto& p : pick) {
        q.push(p);
        dist[p.first][p.second] = 0;
    }

    while(!q.empty()) {
        auto cur = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (board[nx][ny] == 1) continue;
            if (dist[nx][ny] != -1) continue; //

            q.push({nx, ny});
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
        }
    }

    int max_v = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 0) {
                if (dist[i][j] == -1) return -1;
                max_v = max(max_v, dist[i][j]);
            }
        }
    }
    return max_v;
}

void dfs(int idx, vector<pair<int, int>> pick, vector<pair<int, int>> virus) {
    if (pick.size() == M) {
        int ret = bfs(pick);
        if (ret != -1) answer = min(answer, ret);
        return;
    }

    for (int i = idx; i < virus.size(); i++) {
        pick.push_back(virus[i]);
        dfs(i + 1, pick, virus);
        pick.pop_back();
    }
}

int main()
{
    cin >> N >> M;

    board.resize(N, vector<int>(N));

    vector<pair<int, int>> virus;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            if (board[i][j] == 2) virus.push_back({i, j});
        }
    }

    dfs(0, {}, virus);
    if (answer == INT_MAX) cout << -1;
    else cout << answer;
}