import java.util.*;

class Solution {
    public int solution(int[][] rectangle, int characterX, int characterY, int itemX, int itemY) {
        int[][] board = new int[102][102];
        for (int[] rect : rectangle) {
            int x1 = rect[0]*2, y1 = rect[1]*2, x2 = rect[2]*2, y2 = rect[3]*2;
            for (int i = x1; i <= x2; i++) {
                for (int j = y1; j <= y2; j++) {
                    board[i][j] = 1;
                }
            }
        }
        
        for (int[] rect : rectangle) {
            int x1 = rect[0]*2, y1 = rect[1]*2, x2 = rect[2]*2, y2 = rect[3]*2;
            for (int i = x1+1; i < x2; i++) {
                for (int j = y1+1; j < y2; j++) {
                    board[i][j] = 0;
                }
            }
        }
        
        int answer = bfs(board, characterX*2, characterY*2, itemX*2, itemY*2);
        
        return answer / 2;
    }
    
    int[] dx = {1, 0, -1, 0};
    int[] dy = {0, 1, 0, -1};
    
    private int bfs(int[][] board, int startx, int starty, int endx, int endy) {
        Queue<int[]> q = new LinkedList<>();
        boolean[][] visited = new boolean[102][102];
        q.offer(new int[]{startx, starty});
        visited[startx][starty] = true;
        
        while(!q.isEmpty()) {
            int[] cur = q.poll();
            int x = cur[0];
            int y = cur[1];
            
            if (x == endx && y == endy) return board[endx][endy];
            
            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                
                if (nx < 0 || nx >= 102 || ny < 0 || ny >= 102) continue;
                if (visited[nx][ny]) continue;
                if (board[nx][ny] == 0) continue;
                
                visited[nx][ny] = true;
                q.offer(new int[]{nx, ny});
                board[nx][ny] = board[x][y] + 1;
            }
        }
        return -1;
    }
}