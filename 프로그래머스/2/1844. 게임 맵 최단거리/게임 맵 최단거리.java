import java.util.*;

class Solution {
    private static final int[] dx = {-1, 0, 1, 0};
    private static final int[] dy = {0, 1, 0, -1};
    public int solution(int[][] maps) {
        int n = maps.length;
        int m = maps[0].length;
        int[][] dist = new int[n][m];
        for (int i = 0; i < n; i++) Arrays.fill(dist[i], - 1);
        
        Queue<int[]> q = new LinkedList<>();
        dist[0][0] = 1;
        q.offer(new int[]{0, 0});
        
        while(!q.isEmpty()) {
            int[] cur = q.poll();
            int x = cur[0];
            int y = cur[1];
            
            if (x == n - 1 && y == m - 1) return dist[x][y];
            
            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                    if (maps[nx][ny] != 0 && dist[nx][ny] == -1) {
                        q.offer(new int[]{nx, ny});
                        dist[nx][ny] = dist[x][y] + 1;
                    }
                }
            }
        }
        
        return -1;
    }
}