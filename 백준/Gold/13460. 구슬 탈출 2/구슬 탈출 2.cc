#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {1, -1, 0, 0};

struct State {
    int rx, ry, bx, by, cnt;
};

struct MoveResult {
    int x, y, dist;
    bool hole;
};

MoveResult moveBall(int x, int y, int dir, const vector<string>& board) {
    int dist = 0;

    while (true) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (board[nx][ny] == '#') break;

        x = nx;
        y = ny;
        dist++;

        if (board[nx][ny] == 'O') {
            return {nx, ny, dist, true};
        }
    }

    return {x, y, dist, false};
}

int solution(int n, int m, vector<string>& board) {
    int rx, ry, bx, by;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 'B') {
                bx = i;
                by = j;
                board[i][j] = '.';
            }
            if (board[i][j] == 'R') {
                rx = i;
                ry = j;
                board[i][j] = '.';
            }
        }
    }
    bool visited[10][10][10][10] = {false};
    queue<State> q;
    
    q.push({rx, ry, bx, by, 0});
    visited[rx][ry][bx][by] = true;

    while(!q.empty()) {
        State cur = q.front();
        q.pop();

        if (cur.cnt >= 10) continue;

        for (int dir = 0; dir < 4; dir++) {
            MoveResult red = moveBall(cur.rx, cur.ry, dir, board);
            MoveResult blue = moveBall(cur.bx, cur.by, dir, board);

            if (blue.hole) continue;

            if (red.hole) return cur.cnt + 1;

            if (red.x == blue.x && red.y == blue.y) {
                if (red.dist > blue.dist) {
                    red.x -= dx[dir];
                    red.y -= dy[dir];
                } else {
                    blue.x -= dx[dir];
                    blue.y -= dy[dir];
                }
            }

            if (!visited[red.x][red.y][blue.x][blue.y]) {
                visited[red.x][red.y][blue.x][blue.y] = true;
                q.push({red.x, red.y, blue.x, blue.y, cur.cnt + 1});
            }
        }
    }

    return -1;
}

int main()
{
    int N, M;
    cin >> N >> M;

    vector<string> board(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    cout << solution(N, M, board);
}