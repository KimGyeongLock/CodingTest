#include <string>
#include <vector>
#include <array>
#include <queue>

using namespace std;

struct State {
  int x, y, dir;  
};

int solution(vector<vector<int>> board) {
    int n = board.size();
    const int INF = 1e9;
    
    auto freeCell = [&](int x, int y) -> bool {
        return (0 <= x && x < n && 0 <= y && y < n && board[x][y] == 0);
    };
    
    vector<vector<array<int, 2>>> dist(n , vector<array<int, 2>>(n, {INF, INF}));
    queue<State> q;
    
    dist[0][0][0] = 0;
    q.push({0, 0, 0});
    
    auto isGoal = [&](const State& s) -> bool {
        if (s.dir == 0) {
            return (s.x == n-1 && s.y == n-1) || (s.x == n-1 && s.y+1 == n-1);
        } else {
            return (s.x == n-1 && s.y == n-1) || (s.x+1 == n-1 && s.y == n-1);
        }
    };
    
    while(!q.empty()) {
        State cur = q.front(); q.pop();
        int d = dist[cur.x][cur.y][cur.dir];
        if (isGoal(cur)) return d;
        
        int x = cur.x, y = cur.y, dir = cur.dir;
        
        if (dir == 0) {
            if (freeCell(x-1, y) && freeCell(x-1, y+1)) {
                if (dist[x-1][y][0] > d+1) {
                    dist[x-1][y][0] = d+1;
                    q.push({x-1, y, 0});
                }
            }
            if (freeCell(x+1, y) && freeCell(x+1, y+1)) {
                if (dist[x+1][y][0] > d+1) {
                    dist[x+1][y][0] = d+1;
                    q.push({x+1, y, 0});
                }
            }
            if (freeCell(x, y+1) && freeCell(x, y+2)) {
                if (dist[x][y+1][0] > d+1) {
                    dist[x][y+1][0] = d+1;
                    q.push({x, y+1, 0});
                }
            }
            if (freeCell(x, y-1) && freeCell(x, y)) {
                if (dist[x][y-1][0] > d+1) {
                    dist[x][y-1][0] = d+1;
                    q.push({x, y-1, 0});
                }
            }
            
            if (freeCell(x-1, y) && freeCell(x-1, y+1)) {
                if (dist[x-1][y][1] > d+1) {
                    dist[x-1][y][1] = d+1;
                    q.push({x-1, y, 1});
                }
                if (dist[x-1][y+1][1] > d+1) {
                    dist[x-1][y+1][1] = d+1;
                    q.push({x-1, y+1, 1});
                }
            }
            if (freeCell(x+1, y) && freeCell(x+1, y+1)) {
                if (dist[x][y][1] > d+1) {
                    dist[x][y][1] = d+1;
                    q.push({x, y, 1});
                }
                if (dist[x][y+1][1] > d+1) {
                    dist[x][y+1][1] = d+1;
                    q.push({x, y+1, 1});
                }
            }
        } else {
            if (freeCell(x-1, y) && freeCell(x, y)) {
                if (dist[x-1][y][1] > d+1) {
                    dist[x-1][y][1] = d+1;
                    q.push({x-1, y, 1});
                }
            }
            if (freeCell(x+1, y) && freeCell(x+2, y)) {
                if (dist[x+1][y][1] > d+1) {
                    dist[x+1][y][1] = d+1;
                    q.push({x+1, y, 1});
                }
            }
            if (freeCell(x, y-1) && freeCell(x+1, y-1)) {
                if (dist[x][y-1][1] > d+1) {
                    dist[x][y-1][1] = d+1;
                    q.push({x, y-1, 1});
                }
            }
            if (freeCell(x, y+1) && freeCell(x+1, y+1)) {
                if (dist[x][y+1][1] > d+1) {
                    dist[x][y+1][1] = d+1;
                    q.push({x, y+1, 1});
                }
            }
            
            if (freeCell(x, y-1) && freeCell(x+1, y-1)) {
                if (dist[x][y-1][0] > d+1) {
                    dist[x][y-1][0] = d+1;
                    q.push({x, y-1, 0});
                }
                if (dist[x+1][y-1][0] > d+1) {
                    dist[x+1][y-1][0] = d+1;
                    q.push({x+1, y-1, 0});
                }
            }
            if (freeCell(x, y+1) && freeCell(x+1, y+1)) {
                if (dist[x][y][0] > d+1) {
                    dist[x][y][0] = d+1;
                    q.push({x, y, 0});
                }
                if (dist[x+1][y][0] > d+1) {
                    dist[x+1][y][0] = d+1;
                    q.push({x+1, y, 0});
                }
            }
        }
    }
    return -1;
}