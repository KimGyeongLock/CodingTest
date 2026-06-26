import java.util.*;
class Solution {
    public int solution(String[] board) {
        int[] r = new int[2];
        int[] g = new int[2];
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[i].length(); j++) {
                if (board[i].charAt(j) == 'R') {
                    r = new int[]{i, j};
                }
                if (board[i].charAt(j) == 'G') {
                    g = new int[]{i, j};
                }
            }
        }
        
        return bfs(r, g, board);
    }
    
    int[] dx = {1, -1, 0, 0};
    int[] dy = {0, 0, 1, -1};
    
    private int bfs(int[] r, int[] g, String[] board) {
        int n = board.length;
        int m = board[0].length();
        Queue<int[]> q = new LinkedList<>();
        boolean[][] visited = new boolean[n][m];
        
        q.offer(new int[]{r[0], r[1], 0});
        visited[r[0]][r[1]] = true;
        
        while (!q.isEmpty()) {
            int[] cur = q.poll();
            
            if (cur[0] == g[0] && cur[1] == g[1]) return cur[2];
            
            for (int d = 0; d < 4; d++) {
                int nx = cur[0];
                int ny = cur[1];
                                
                while (true) {
                    int nextX = nx + dx[d];
                    int nextY = ny + dy[d];
                    
                    if (nextX < 0 || nextY < 0 || nextX >= n || nextY >= m) break;
                    if (board[nextX].charAt(nextY) == 'D') break;

                    nx = nextX;
                    ny = nextY;
                }
                
                if (visited[nx][ny]) continue;

                visited[nx][ny] = true;
                q.offer(new int[]{nx, ny, cur[2] + 1});
            }
        }

        return -1;
    }
}