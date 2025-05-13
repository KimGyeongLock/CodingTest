import java.util.*;

class Solution {
    boolean visited[][];
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};
    public int solution(int[][] maps) {
        int n = maps.length;
        int m = maps[0].length;
        visited = new boolean[n][m];
        bfs(maps);
        return maps[n - 1][m - 1] == 1 ? -1 : maps[n - 1][m - 1];
    }
    
    private void bfs(int[][] maps) {
        Queue<Position> q = new LinkedList<>();
        q.offer(new Position(0, 0));
        visited[0][0] = true;
        
        while(!q.isEmpty()) {
            Position curr = q.poll();
            int cx = curr.x;
            int cy = curr.y;
            for(int i = 0; i < 4; i++) {
                int nx = cx + dx[i];
                int ny = cy + dy[i];
                if (nx >= 0 && ny >= 0 && nx < maps.length && ny < maps[0].length) {
                    if (!visited[nx][ny] && maps[nx][ny] == 1) {
                        q.offer(new Position(nx, ny));
                        maps[nx][ny] = maps[cx][cy] + 1;
                    }
                }
            }
        }
    }
    
    class Position {
        int x;
        int y;
        
        Position(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
}