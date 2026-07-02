import java.util.*;

class Solution {
    static int n, m;
    static int answer;
    static int[][] maze;
    
    static int redEndX, redEndY;
    static int blueEndX, blueEndY;
    
    static boolean[][] redVisited;
    static boolean[][] blueVisited;
    
    static int[] dx = {1, -1, 0, 0};
    static int[] dy = {0, 0, 1, -1};
    
    public int solution(int[][] maze) {
        this.maze = maze;
        n = maze.length;
        m = maze[0].length;
        
        int redStartX = 0, redStartY = 0;
        int blueStartX = 0, blueStartY = 0;
        
        redVisited = new boolean[n][m];
        blueVisited = new boolean[n][m];
        
        answer = Integer.MAX_VALUE;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (maze[i][j] == 1) {
                    redStartX = i;
                    redStartY = j;
                } else if (maze[i][j] == 2) {
                    blueStartX = i;
                    blueStartY = j;
                } else if (maze[i][j] == 3) {
                    redEndX = i;
                    redEndY = j;
                } else if (maze[i][j] == 4) {
                    blueEndX = i;
                    blueEndY = j;
                }
            }
        }
        
        redVisited[redStartX][redStartY] = true;
        blueVisited[blueStartX][blueStartY] = true;
        
        dfs(redStartX, redStartY, blueStartX, blueStartY, 0);
        return answer == Integer.MAX_VALUE ? 0 : answer;
    }
    
    private void dfs(int rx, int ry, int bx, int by, int turn) {
        if (turn >= answer) return;
        
        boolean redArrived = rx == redEndX && ry == redEndY;
        boolean blueArrived = bx == blueEndX && by == blueEndY;
        
        if (redArrived && blueArrived) {
            answer = Math.min(answer, turn);
            return;
        }
        
        List<int[]> redNextList = getNextPositions(rx, ry, redArrived, true);
        List<int[]> blueNextList = getNextPositions(bx, by, blueArrived, false);
        
        for (int[] redNext : redNextList) {
            for (int[] blueNext : blueNextList) {
                int nrx = redNext[0];
                int nry = redNext[1];
                int nbx = blueNext[0];
                int nby = blueNext[1];
                
                if (nrx == nbx && nry == nby) continue;
                
                if (nrx == bx && nry == by && nbx == rx && nby == ry) continue;
                
                boolean redMoved = !(nrx == rx && nry == ry);
                boolean blueMoved = !(nbx == bx && nby == by);
                
                if (redMoved) redVisited[nrx][nry] = true;
                if (blueMoved) blueVisited[nbx][nby] = true;
                
                dfs(nrx, nry, nbx, nby, turn + 1);
                
                if (redMoved) redVisited[nrx][nry] = false;
                if (blueMoved) blueVisited[nbx][nby] = false;
            }
        }
    }
    
    private List<int[]> getNextPositions(int x, int y, boolean arrived, boolean isRed) {
        List<int[]> result = new ArrayList<>();
        
        if (arrived) {
            result.add(new int[]{x, y});
            return result;
        }
        
        boolean[][] visited = isRed ? redVisited : blueVisited;
        
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (maze[nx][ny] == 5) continue;
            if (visited[nx][ny]) continue;
            
            result.add(new int[]{nx, ny});
        }
        
        return result;
    }
}