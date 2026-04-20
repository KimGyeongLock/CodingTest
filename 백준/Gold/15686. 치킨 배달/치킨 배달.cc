#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int N, M;
vector<vector<int>> board;
vector<pair<int, int>> home;
vector<pair<int, int>> chicken;
int min_dist = INT_MAX;

void dfs(int idx, vector<pair<int, int>> pick) {
    if (pick.size() == M) {
        int dist = 0;
        for (auto h : home) {
            int houseMin = INT_MAX;
            for (auto c : pick) {
                int dist = abs(h.first - c.first) + abs(h.second - c.second);
                houseMin = min(houseMin, dist);
            }
            dist += houseMin;
        }
        min_dist = min(min_dist, dist);
        return;
    }

    for (int i = idx; i < chicken.size(); i++) {
        pick.push_back(chicken[i]);
        dfs(i + 1, pick);
        pick.pop_back();
    }
}

int solution() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 1) {
                home.push_back({i, j});
            }
            if (board[i][j] == 2) {
                chicken.push_back({i, j});
            }
        }
    }

    dfs(0, {});
    return min_dist;
}

int main()
{
    cin >> N >> M;

    board.resize(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    cout << solution();
}