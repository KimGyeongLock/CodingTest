#include <iostream>
#include <vector>
#include <tuple>
#include <climits>

using namespace std;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
int answer = INT_MAX;

void watch(vector<vector<int>>& board, int x, int y, int dir) {
    int n = board.size();
    int m = board[0].size();

    int nx = x;
    int ny = y;

    while (true) {
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) break;
        if (board[nx][ny] == 6) break;

        if (board[nx][ny] == 0) board[nx][ny] = -1;

        nx += dx[dir];
        ny += dy[dir];
    }
}

void dfs(int idx, vector<tuple<int, int, int>> cctv, vector<vector<int>>& arr) {
    int n = arr.size();
    int m = arr[0].size();
    int s = cctv.size();

    if (idx == s) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) if (arr[i][j] == 0) cnt++;
        }
        answer = min(answer, cnt);
        return;
    }

    int type = get<0>(cctv[idx]), x = get<1>(cctv[idx]), y = get<2>(cctv[idx]);

    if (type == 1) {

        for (int dir = 0; dir < 4; dir++) {
            vector<vector<int>> narr = arr;
            watch(narr, x, y, dir);
            dfs(idx+1, cctv, narr);
        }

    } else if (type == 2) {

        for (int dir = 0; dir < 2; dir++) {
            vector<vector<int>> narr = arr;
            watch(narr,x, y, dir);
            watch(narr,x, y, dir+2);
            dfs(idx+1, cctv, narr);
        }

    } else if (type == 3) {
        for (int dir = 0; dir < 4; dir++) {
            vector<vector<int>> narr = arr;
            watch(narr,x, y, dir);
            watch(narr,x, y, (dir+1)%4);
            dfs(idx+1, cctv, narr);
        }
    } else if (type == 4) {
        for (int dir = 0; dir < 4; dir++) {
            vector<vector<int>> narr = arr;
            watch(narr,x, y, dir);
            watch(narr,x, y, (dir+1)%4);
            watch(narr,x, y, (dir+2)%4);
            dfs(idx+1, cctv, narr);
        }
    } else if (type == 5) {
        vector<vector<int>> narr = arr;
        for (int dir = 0; dir < 4; dir++) {
            watch(narr,x, y, dir);
        }
        dfs(idx+1, cctv, narr);
    }
    
}

int solution(int n, int m, vector<vector<int>> arr) {
    vector<tuple<int, int, int>> cctv;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] > 0 && arr[i][j] < 6) cctv.push_back({arr[i][j], i, j});
        }
    }
    dfs(0, cctv, arr);
    return answer;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N, M;
    cin >> N >> M;

    vector<vector<int>> arr(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    cout << solution(N, M, arr);
}