#include <bits/stdc++.h>
using namespace std;

static const int INF = 1e9;

// 키패드 좌표: (row, col)
// 1 2 3
// 4 5 6
// 7 8 9
//   0
pair<int,int> posOf(int d) {
    switch (d) {
        case 1: return {0,0};
        case 2: return {0,1};
        case 3: return {0,2};
        case 4: return {1,0};
        case 5: return {1,1};
        case 6: return {1,2};
        case 7: return {2,0};
        case 8: return {2,1};
        case 9: return {2,2};
        case 0: return {3,1};
    }
    return {-1,-1};
}

bool isValidCell(int r, int c) {
    // 존재하는 칸만: (3,0),(3,2)는 없음
    if (r < 0 || r > 3 || c < 0 || c > 2) return false;
    if (r == 3 && c != 1) return false;
    return true;
}

int digitAt(int r, int c) {
    // 좌표 -> 숫자
    if (r == 0 && c == 0) return 1;
    if (r == 0 && c == 1) return 2;
    if (r == 0 && c == 2) return 3;
    if (r == 1 && c == 0) return 4;
    if (r == 1 && c == 1) return 5;
    if (r == 1 && c == 2) return 6;
    if (r == 2 && c == 0) return 7;
    if (r == 2 && c == 1) return 8;
    if (r == 2 && c == 2) return 9;
    if (r == 3 && c == 1) return 0;
    return -1;
}

// 인접 이동(누르기 포함) 비용: 상하좌우 2, 대각 3
int stepCost(int from, int to) {
    auto [r1,c1] = posOf(from);
    auto [r2,c2] = posOf(to);
    int dr = abs(r1 - r2), dc = abs(c1 - c2);
    if (dr == 1 && dc == 0) return 2;
    if (dr == 0 && dc == 1) return 2;
    if (dr == 1 && dc == 1) return 3;
    return INF;
}

vector<vector<int>> buildPressDist() {
    // movePressDist[a][b] = a에서 b를 "누르기"까지 최소 비용 (a==b는 0으로 두고, DP에서 1로 처리)
    vector<vector<int>> dist(10, vector<int>(10, INF));

    // 그래프 인접 리스트 구성 (10노드)
    vector<vector<pair<int,int>>> adj(10);
    for (int d = 0; d <= 9; d++) {
        auto [r,c] = posOf(d);
        for (int dr = -1; dr <= 1; dr++) {
            for (int dc = -1; dc <= 1; dc++) {
                if (dr == 0 && dc == 0) continue;
                int nr = r + dr, nc = c + dc;
                if (!isValidCell(nr, nc)) continue;
                int nd = digitAt(nr, nc);
                int w = (abs(dr) + abs(dc) == 1) ? 2 : 3; // 상하좌우=2, 대각=3
                adj[d].push_back({nd, w});
            }
        }
    }

    // 각 시작점에서 다익스트라
    for (int s = 0; s <= 9; s++) {
        vector<int> d(10, INF);
        d[s] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, s});
        while (!pq.empty()) {
            auto [cd, u] = pq.top(); pq.pop();
            if (cd != d[u]) continue;
            for (auto [v, w] : adj[u]) {
                if (d[v] > cd + w) {
                    d[v] = cd + w;
                    pq.push({d[v], v});
                }
            }
        }
        dist[s] = d;
    }
    return dist;
}

int solution(string numbers) {
    auto movePressDist = buildPressDist();

    auto pressCost = [&](int from, int to) -> int {
        if (from == to) return 1;              // 제자리 다시 누르기
        return movePressDist[from][to];        // 이동+누르기 최단 비용
    };

    vector<vector<int>> dp(10, vector<int>(10, INF));
    dp[4][6] = 0; // 시작: 왼손 4, 오른손 6 :contentReference[oaicite:3]{index=3}

    for (char ch : numbers) {
        int x = ch - '0';
        vector<vector<int>> ndp(10, vector<int>(10, INF));

        for (int l = 0; l <= 9; l++) for (int r = 0; r <= 9; r++) {
            int cur = dp[l][r];
            if (cur == INF) continue;
            if (l == r) continue; // 불가능 상태(동일 키 동시 점유)

            // 이미 해당 숫자 위에 손가락이 있으면 그 손가락으로만 눌러야 함 :contentReference[oaicite:4]{index=4}
            if (x == l) {
                ndp[l][r] = min(ndp[l][r], cur + 1);
                continue;
            }
            if (x == r) {
                ndp[l][r] = min(ndp[l][r], cur + 1);
                continue;
            }

            // 왼손으로 누르기 (왼손이 x로 이동, 단 오른손 위치와 겹치면 안 됨)
            if (x != r) {
                ndp[x][r] = min(ndp[x][r], cur + pressCost(l, x));
            }
            // 오른손으로 누르기
            if (x != l) {
                ndp[l][x] = min(ndp[l][x], cur + pressCost(r, x));
            }
        }
        dp.swap(ndp);
    }

    int ans = INF;
    for (int l = 0; l <= 9; l++) for (int r = 0; r <= 9; r++) {
        ans = min(ans, dp[l][r]);
    }
    return ans;
}
