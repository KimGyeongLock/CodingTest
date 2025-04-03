#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int N, M, T;
vector<vector<int> > A;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool canEscape(int K) {
    vector<vector<vector<bool> > > visited(N, vector<vector<bool> >(M, vector<bool>(K + 1, false)));
    queue<tuple<int, int, int, int> > q;

    q.push(make_tuple(0, 0, 0, K));
    visited[0][0][K] = true;

    while(!q.empty()) {
        auto [x, y, t, e] = q.front();
        q.pop();

        if(t > T) continue; //제한 시간이 넘어가면
        if(x == N - 1 && y == M - 1) return true; //도착

        if(A[x][y] == 2 && e < K && !visited[x][y][e + 1]) { // 땅일 경우 에너지 + 1
            visited[x][y][e + 1] = true;
            q.push(make_tuple(x, y, t + 1, e + 1));
        }

        for(int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if (A[nx][ny] == 0) continue; //쑥대밭

            int ne = e;

            if (A[x][y] != 2 || A[nx][ny] != 2) {
                if (ne == 0) continue;
                ne--;
            }

            if(!visited[nx][ny][ne]) {
                visited[nx][ny][ne] = true;
                q.push(make_tuple(nx, ny, t + 1, ne));
            }
        }  
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> T;
    A.resize(N, vector<int>(M));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> A[i][j];
        }
    }
    int left = 0, right = N * M;
    int answer = -1;

    while(left <= right) {
        int mid = (left + right) / 2;
        if (canEscape(mid)) {
            answer = mid;
            right = mid - 1; //최솟값
        } else {
            left = mid + 1;
        }
    }
    cout << answer;

}
