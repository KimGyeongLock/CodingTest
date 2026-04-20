#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
int N, L, R;

bool bfs(vector<vector<int>>& board, int x, int y, vector<vector<bool>>& visited) {
    int n = board.size();
    queue<pair<int, int>> q;
    
    q.push({x, y});
    visited[x][y] = true;

    vector<pair<int, int>> cand;
    cand.push_back({x, y});
    int total = board[x][y];

    while(!q.empty()) {
        auto cur = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (visited[nx][ny]) continue;
            if (abs(board[nx][ny] - board[cur.first][cur.second]) < L || abs(board[nx][ny] - board[cur.first][cur.second]) > R) continue;

            q.push({nx, ny});
            visited[nx][ny] = true;
            cand.push_back({nx, ny});
            total += board[nx][ny];
        }
    }

    if (cand.size() == 1) return false;

    for (auto c : cand) {
        board[c.first][c.second] = total / cand.size();
    }

    return true;
}

int main()
{
    cin >> N >> L >> R;

    vector<vector<int>> board(N, vector<int>(N));
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    int cnt = 0;

    while (true) {    
        bool moved = false;
        vector<vector<bool>> visited(N, vector<bool>(N, false));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (visited[i][j]) continue;
                if (bfs(board, i, j, visited)) {
                    moved = true;
                }
            }
        }
        if (!moved) break;
        cnt++;
    }

    cout << cnt;
}