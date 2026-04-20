#include <iostream>
#include <vector>

using namespace std;

int board[31][11];
int N, M, H;

bool check() {
    for (int start = 1; start <= N; start++) {
        int col = start;
        for (int row = 1; row <= H; row++) {
            if (board[row][col]) col++;
            else if (col > 1 && board[row][col-1]) col--;
        }
        if (start != col) return false;
    }
    return true;
}

bool dfs(int idx, int cnt, int target) {
    if (cnt == target) {
        return check();
    }

    for (int k = idx; k <= H * (N - 1); k++) {
        int row = (k - 1) / (N - 1) + 1;
        int col = (k - 1) % (N - 1) + 1;

        if (board[row][col]) continue;
        if (col > 1 && board[row][col - 1]) continue;
        if (col < N - 1 && board[row][col + 1]) continue;

        board[row][col] = true;
        if (dfs(k + 1, cnt + 1, target)) return true;
        board[row][col] = false;
    }
    return false;
}

int solution(vector<pair<int, int>> hz) {    
    for (auto c : hz) {
        board[c.first][c.second] = true;
    }

    for (int add = 0; add <= 3; add++) {
        if (dfs(1, 0, add)) {
            return add;
        }
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    
    cin >> N >> M >> H;

    vector<pair<int, int>> hz(M);
    for (int i = 0; i < M; i++) {
        cin >> hz[i].first >> hz[i].second;
    }

    cout << solution(hz);
}