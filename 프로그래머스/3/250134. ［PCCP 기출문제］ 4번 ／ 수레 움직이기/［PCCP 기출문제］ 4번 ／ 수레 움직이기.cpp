#include <string>
#include <vector>
#include <climits>

using namespace std;

int n, m;
int board[4][4];
int answer = INT_MAX;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

struct Pos {
  int x, y;
    bool operator==(const Pos& o) {
        return x == o.x && y == o.y;
    }
};

void dfs(Pos a, Pos b, Pos aGoal, Pos bGoal,
        vector<vector<bool>>& aVisited,
        vector<vector<bool>>& bVisited,
        int turn) {
    if (turn > answer) return;
    
    bool aDone = (a == aGoal);
    bool bDone = (b == bGoal);
    
    if (aDone && bDone) {
        answer = min(answer, turn);
        return;
    }
    
    int ax = a.x, ay = a.y;
    int bx = b.x, by = b.y;

    aVisited[a.x][a.y] = true;
    bVisited[b.x][b.y] = true;
    
    for (int dirA = 0; dirA < 4; dirA++) {
        int nax = a.x;
        int nay = a.y;
        
        if (!aDone) {
            nax += dx[dirA];
            nay += dy[dirA];
            
            if (nax < 0 || nax >= n || nay < 0 || nay >= m) continue;
            if (aVisited[nax][nay]) continue;
            if (board[nax][nay] == 5) continue;
            if (nax == bx && nay == by) continue;
        }
        
        for (int dirB = 0; dirB < 4; dirB++) {
            int nbx = b.x;
            int nby = b.y;
            
            if (!bDone) {
                nbx += dx[dirB];
                nby += dy[dirB];
                
                if (nbx < 0 || nbx >= n || nby < 0 || nby >= m) continue;
                if (bVisited[nbx][nby]) continue;
                if (board[nbx][nby] == 5) continue;
                if (nbx == nax && nby == nay) continue;
                if (nax == bx && nay == by && nbx == ax && nby == ay) continue;
            }
            
            dfs({nax, nay}, {nbx, nby}, aGoal, bGoal, aVisited, bVisited, turn + 1);
        }
    }
    aVisited[a.x][a.y] = false;
    bVisited[b.x][b.y] = false;
}

int solution(vector<vector<int>> maze) {
    n = maze.size();
    m = maze[0].size();
    Pos rStart, rGoal, bStart, bGoal;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            board[i][j] = maze[i][j];
            if (maze[i][j] == 1) rStart = {i, j};
            if (maze[i][j] == 2) bStart = {i, j};
            if (maze[i][j] == 3) rGoal = {i, j};
            if (maze[i][j] == 4) bGoal = {i, j};
        }
    }
    
    vector<vector<bool>> rVisited(n, vector<bool>(m, false));
    vector<vector<bool>> bVisited(n, vector<bool>(m, false));
    
    dfs(rStart, bStart, rGoal, bGoal, rVisited, bVisited, 0);
    rVisited.assign(n, vector<bool>(m, false));
    bVisited.assign(n, vector<bool>(m, false));
    dfs(bStart, rStart, bGoal, rGoal, bVisited, rVisited, 0);
    
    if (answer == INT_MAX) return 0;
    return answer;
}