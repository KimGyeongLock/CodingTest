#include <string>
#include <vector>
#include <queue>
#include <array>
#include <climits>

using namespace std;

struct Node {
    int x, y, dir, cur;
    bool operator<(const Node o) const {
        return cur > o.cur;
    }
};

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int solution(vector<vector<int>> board) {
    int n = board.size();
    vector<vector<array<int, 4>>> cost(n, vector<array<int, 4>>(n, {INT_MAX, INT_MAX, INT_MAX, INT_MAX}));
    priority_queue<Node> pq;
    
    if (!board[1][0]) {
        cost[1][0][0] = 100;
        pq.push({1, 0, 0, 100});
    }
    if (!board[0][1]) {
        cost[0][1][2] = 100;
        pq.push({0, 1, 2, 100});
    }
    
    while(!pq.empty())
    {
        auto [x, y, dir, cur] = pq.top(); pq.pop();
        
        if (cost[x][y][dir] < cur) continue;
        if (x == n - 1 && y == n - 1) return cur;
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (board[nx][ny] == 1) continue;
            
            int nxt = cur + (dir == i ? 100 : 600);
            
            if (cost[nx][ny][i] > nxt) {
                cost[nx][ny][i] = nxt;
                pq.push({nx, ny, i, nxt});
            }
        }
    }
    
    return 0;
}