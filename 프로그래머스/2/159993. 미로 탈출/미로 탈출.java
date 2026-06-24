import java.util.*;
class Solution {
    int[] dx = {-1, 1, 0, 0};
    int[] dy = {0, 0, -1, 1};
    
    public int solution(String[] maps) {        
        int[] s = new int[2];
        int[] l = new int[2];
        int[] e = new int[2];
        
        for (int i = 0; i < maps.length; i++) {
            for (int j = 0; j < maps[i].length(); j++) {
                if (maps[i].charAt(j) == 'S') {
                    s = new int[]{i, j};
                }
                if (maps[i].charAt(j) == 'L') {
                    l = new int[]{i, j};
                }
                if (maps[i].charAt(j) == 'E') {
                    e = new int[]{i, j};
                }
            }
        }
        
        int a = bfs(maps, s, l);
        if (a == -1) return -1;
        int b = bfs(maps, l, e);
        if (b == -1) return -1;
        return a + b;
    }
    
    private int bfs(String[] maps, int[] start, int[] end) {
        int n = maps.length;
        int m = maps[0].length();
        
        boolean[][] visited = new boolean[n][m];
        Queue<int[]> q = new LinkedList<>();
        
        q.offer(new int[]{start[0], start[1], 0});
        visited[start[0]][start[1]] = true;
        
        while(!q.isEmpty()) {
            int[] cur = q.poll();
            
            int x = cur[0];
            int y = cur[1];
            int dist = cur[2];
            
            if (x == end[0] && y == end[1]) {
                return dist;
            }
            
            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                
                if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                if (visited[nx][ny]) continue;
                if (maps[nx].charAt(ny) == 'X') continue;
                
                visited[nx][ny] = true;
                q.offer(new int[]{nx, ny, dist + 1});
            }
        }
        
        return -1;
    }
}