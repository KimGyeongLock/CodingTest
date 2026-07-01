import java.util.*;
class Solution {
    static int n, m;
    public int solution(int[][] land) {
        int answer = 0;
        
        n = land.length;
        m = land[0].length;
        boolean[][] visited = new boolean[n][m];
        HashMap<Integer, Integer> sizeMap = new HashMap<>();
        
        int[][] painted = new int[n][m];
        for (int i = 0; i < n; i++) {
            Arrays.fill(painted[i], -1);
        }
        
        int paint = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (visited[i][j]) continue;
                if (land[i][j] == 0) continue;
                int res = bfs(land, visited, i, j, paint, painted);
                sizeMap.put(paint, res);
                paint++;
            }
        }
        
        for (int i = 0; i < m; i++) {
            Set<Integer> s = new HashSet<>();
            for (int j = 0; j < n; j++) {
                s.add(painted[j][i]);
            }
            int total = 0;
            for (int item : s) {
                if (item == -1) continue;
                total += sizeMap.get(item);
            }
            answer = Math.max(answer, total);
        }
        
        return answer;
    }
    
    static int[] dx = {1, -1, 0, 0};
    static int[] dy = {0, 0, 1, -1};
                    
    private int bfs(int[][] land, boolean[][] visited, int x, int y, int paint, int[][] painted) {
        
        Queue<int[]> q = new LinkedList<>();
        q.offer(new int[]{x, y});
        visited[x][y] = true;
        int cnt = 0;
        
        while (!q.isEmpty()) {
            int[] cur = q.poll();
            int cx = cur[0];
            int cy = cur[1];
            cnt++;
            painted[cx][cy] = paint;
            
            for (int d = 0; d < 4; d++) {
                int nx = cx + dx[d];
                int ny = cy + dy[d];
                
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (visited[nx][ny]) continue;
                if (land[nx][ny] == 0) continue;
                
                visited[nx][ny] = true;
                q.offer(new int[]{nx, ny});
            }
        }
        
        return cnt;
    }
}