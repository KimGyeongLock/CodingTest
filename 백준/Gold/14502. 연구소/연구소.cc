#include <iostream>
#include <vector>
#include <queue>

using namespace std;
 
int answer;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int moveVirus(vector<pair<int, int>> walls, const vector<pair<int, int>>& twos, vector<vector<int>> map) {
    for (auto w : walls) {
        map[w.first][w.second] = 1;
    }
    int n = map.size();
    int m = map[0].size();

    queue<pair<int, int>> q;
    int cnt = 0;
    for (auto t : twos) {
        q.push(t);
        cnt++;
    }

    while(!q.empty()) {
        auto cur = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (map[nx][ny] == 1 || map[nx][ny] == 2) continue;
            
            map[nx][ny] = 2;
            q.push({nx, ny});
            cnt++;
        }
    }
    return n*m - cnt;
}

void dfs(int idx, int depth, vector<pair<int, int>>& walls, const vector<pair<int, int>>& zeros, const vector<pair<int, int>>& twos, const vector<vector<int>>& map) {
    if (depth == 3) {
        answer = max(answer, moveVirus(walls, twos, map));
        return;
    }

    for (int i = idx; i < zeros.size(); i++) {
        walls.push_back(zeros[i]);
        dfs(i + 1, depth + 1, walls, zeros, twos, map);
        walls.pop_back();
    }
}

int solution(int n, int m, vector<vector<int>> map) 
{
    vector<pair<int, int>> zeros;
    vector<pair<int, int>> twos;
    int one = 3;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 0) {
                zeros.push_back({i, j});
            }
            if (map[i][j] == 2) {
                twos.push_back({i, j});
            }
            if (map[i][j] == 1) {
                one++;
            }
        }
    }
    vector<pair<int, int>> walls;
    dfs(0, 0, walls, zeros, twos, map);
    return answer - one;
}

int main()
{
    int N, M;
    cin >> N >> M;

    vector<vector<int>> map(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) cin >> map[i][j];
    }

    cout << solution(N, M, map);
}