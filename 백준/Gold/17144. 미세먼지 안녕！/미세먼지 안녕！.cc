#include <iostream>
#include <vector>


using namespace std;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main()
{
    int R, C, T;
    cin >> R >> C >> T;

    vector<vector<int>> A(R, vector<int>(C));
    pair<int, int> ac;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> A[i][j];
            if (A[i][j] == -1) ac = {i, j};
        }
    }


    while(T--) {
        //확산
        vector<vector<int>> plus(R, vector<int>(C, 0));
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (A[i][j] == 0 || A[i][j] == -1) continue;

                for (int dir = 0; dir < 4; dir++) {
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];

                    if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
                    if (A[nx][ny] == -1) continue;

                    plus[nx][ny] += A[i][j] / 5;
                    plus[i][j] -= A[i][j] / 5;
                }
            }
        }

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                A[i][j] += plus[i][j];
            }
        }

        //공기청정기 작동
        // 윗
        int top = ac.first - 1;
        for (int i = top - 1; i > 0; i--) A[i][0] = A[i - 1][0];
        for (int i = 1; i < C; i++) A[0][i - 1] = A[0][i]; 
        for (int i = 0; i < top; i++) A[i][C-1] = A[i + 1][C-1];
        for (int i = C - 1; i > 1; i--) A[top][i] = A[top][i - 1];
        A[top][1] = 0;

        // 아래
        int bottom = ac.first;
        for (int i = bottom + 1; i < R - 1; i++) A[i][0] = A[i+1][0];
        for (int i = 0; i < C - 1; i++) A[R - 1][i] = A[R - 1][i + 1];
        for (int i = R - 1; i > bottom; i--) A[i][C - 1] = A[i - 1][C - 1];
        for (int i = C - 1; i > 1; i--) A[bottom][i] = A[bottom][i - 1];
        A[bottom][1] = 0;
    }

    int total = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (A[i][j] != -1) {
                total += A[i][j];
            }
        }
    }

    cout << total;
}