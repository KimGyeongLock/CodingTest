import java.util.*;
class Solution {
    static boolean[][] visited;
    static int[] dx = {1, 0, -1, 0};
    static int[] dy = {0, 1, 0, -1};
    public int solution(int[][] maps) {
        visited = new boolean[maps.length][maps[0].length];
        bfs(maps);
        if (maps[maps.length - 1][maps[0].length - 1] == 1) return -1;
        return maps[maps.length - 1][maps[0].length - 1];
    }
    private void bfs(int[][] maps) {
        visited[0][0] = true;
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{0, 0});
        
        while(!q.isEmpty()) {
            int[] current = q.poll();
            int x = current[0];
            int y = current[1];
            
            if(x == maps.length - 1 && y == maps[0].length - 1) {
                return;
            }
            
            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(nx >= 0 && ny >= 0 && nx < maps.length && ny < maps[0].length) {
                    if(!visited[nx][ny] && maps[nx][ny] == 1) {
                        visited[nx][ny] = true;
                        q.add(new int[]{nx, ny});
                        maps[nx][ny] = maps[x][y] + 1; 
                    }
                }
            }
        }
    }
}