#include <string>
#include <vector>
#include <queue>
#include <array>

using namespace std;

struct State {
    int x, y, dir;  
};

int solution(vector<vector<int>> board) {
    int n = board.size();
    int INF = 1e9;
    
    vector<vector<array<int, 2>>> dist(n, vector<array<int, 2>>(n, {INF, INF}));
    queue<State> q;
    q.push({0, 0, 0});
    dist[0][0][0] = 0;
    
    auto free = [&](int x, int y) -> bool {
        if (x >= 0 && x < n && y >= 0 && y < n && board[x][y] == 0) return true;
        return false;
    };
    
    auto isGoal = [&](int x, int y, int dir) -> bool {
        if (dir == 0) return (x == n-1 && y == n-1) || (x == n-1 && y+1 == n-1);
        else return (x == n-1 && y == n-1) || (x+1 == n-1 && y == n-1);
    };
    
    while(!q.empty())
    {
        auto cur = q.front(); q.pop();
        int x = cur.x, y = cur.y, dir = cur.dir;
        int d = dist[x][y][dir];
        if (isGoal(x, y, dir)) return d;
        if (dir == 0) {
            
            if (free(x-1, y) && free(x-1, y+1)) {
                if (dist[x-1][y][0] > d+1) {
                    dist[x-1][y][0] = d+1;
                    q.push({x-1, y, 0});
                }  
            }
            if (free(x+1, y) && free(x+1, y+1)) {
                if (dist[x+1][y][0] > d+1) {
                    dist[x+1][y][0] = d+1;
                    q.push({x+1, y, 0});
                }  
            }
            if (free(x, y+1) && free(x, y+2)) {
                if (dist[x][y+1][0] > d+1) {
                    dist[x][y+1][0] = d+1;
                    q.push({x, y+1, 0});
                }  
            }
            if (free(x, y-1) && free(x, y)) {
                if (dist[x][y-1][0] > d+1) {
                    dist[x][y-1][0] = d+1;
                    q.push({x, y-1, 0});
                }  
            }
            
            if (free(x-1, y) && free(x-1, y+1)) {
                if (dist[x-1][y][1] > d+1) {
                    dist[x-1][y][1] = d+1;
                    q.push({x-1, y, 1});
                }
                if (dist[x-1][y+1][1] > d+1) {
                    dist[x-1][y+1][1] = d+1;
                    q.push({x-1, y+1, 1});
                }
            }
            if (free(x+1, y) && free(x+1, y+1)) {
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
            if (free(x-1, y) && free(x, y)) {
                if (dist[x-1][y][1] > d+1) {
                    dist[x-1][y][1] = d+1;
                    q.push({x-1, y, 1});
                }  
            }
            if (free(x+1, y) && free(x+2, y)) {
                if (dist[x+1][y][1] > d+1) {
                    dist[x+1][y][1] = d+1;
                    q.push({x+1, y, 1});
                }  
            }
            if (free(x, y+1) && free(x+1, y+1)) {
                if (dist[x][y+1][1] > d+1) {
                    dist[x][y+1][1] = d+1;
                    q.push({x, y+1, 1});
                }  
            }
            if (free(x, y-1) && free(x+1, y-1)) {
                if (dist[x][y-1][1] > d+1) {
                    dist[x][y-1][1] = d+1;
                    q.push({x, y-1, 1});
                }  
            }
            
            if (free(x, y+1) && free(x+1, y+1)) {
                if (dist[x][y][0] > d+1) {
                    dist[x][y][0] = d+1;
                    q.push({x, y, 0});
                }
                if (dist[x+1][y][0] > d+1) {
                    dist[x+1][y][0] = d+1;
                    q.push({x+1, y, 0});
                }
            }
            if (free(x, y-1) && free(x+1, y-1)) {
                if (dist[x][y-1][0] > d+1) {
                    dist[x][y-1][0] = d+1;
                    q.push({x, y-1, 0});
                }
                if (dist[x+1][y-1][0] > d+1) {
                    dist[x+1][y-1][0] = d+1;
                    q.push({x+1, y-1, 0});
                }
            }
        }
        
    }
    return 0;
}