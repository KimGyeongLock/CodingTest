#include <iostream>
#include <vector>

using namespace std;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
vector<vector<bool>> visited;
int answer = 0;
void dfs(int x, int y, int idx, int total, const vector<vector<int>>& paper) {
    int a = paper.size();
    int b = paper[0].size();

    if (idx == 3) {
        answer = max(answer, total);
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= a || ny < 0 || ny >= b) continue;
        if (visited[nx][ny]) continue;
        visited[nx][ny] = true;
        dfs(nx, ny, idx + 1, total + paper[nx][ny], paper);
        visited[nx][ny] = false;
    }
}

void checkT(int x, int y, const vector<vector<int>>& paper) {
    int n = paper.size();
    int m = paper[0].size();

    int center = paper[x][y];
    int sum = center;
    int minWing = 1001;
    int cnt = 0;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

        cnt++;
        sum += paper[nx][ny];
        minWing = min(minWing, paper[nx][ny]);
    }

    if (cnt == 4) {
        answer = max(answer, sum - minWing);
    } else if (cnt == 3) {
        answer = max(answer, sum);
    }
}

int solution(int n, int m, vector<vector<int>> paper) {
    visited.assign(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visited[i][j] = true;
            dfs(i, j, 0, paper[i][j], paper);
            visited[i][j] = false;

            checkT(i, j, paper);
        }
    }
    return answer;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> paper(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> paper[i][j];
        }
    }

    cout << solution(N, M, paper);
}