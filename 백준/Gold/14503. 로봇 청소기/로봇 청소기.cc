#include <iostream>
#include <vector>

using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int solution(int n, int m, int r, int c, int d, vector<vector<int>> room) {
    int cnt = 0;
    while (true) {
        if (room[r][c] == 0) {
            room[r][c] = 2;
            cnt++;
            continue;
        }

        bool empty = false;
        for (int dir = 0; dir < 4; dir++) {
            int nx = r + dx[dir];
            int ny = c + dy[dir];
            if (room[nx][ny] == 0) empty = true;
        }

        if (!empty) {
            if (room[r - dx[d]][c - dy[d]] != 1) {
                r -= dx[d];
                c -= dy[d];
            } else {
                break;
            }
        } else {
            d = (d + 3) % 4;
            if (room[r + dx[d]][c + dy[d]] == 0) {
                r += dx[d];
                c += dy[d];
            }
        }
    }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    int r, c, d;
    cin >> r >> c >> d;

    vector<vector<int>> room(N, vector<int>(M));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> room[i][j];

    cout << solution(N, M, r, c, d, room);
}