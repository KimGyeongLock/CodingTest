import java.util.*;

class Solution {
    public int solution(int[][] game_board, int[][] table) {
        int answer = 0;
        int n = game_board.length;
        
        ArrayList<List<int[]>> blanks = new ArrayList<>();
        boolean[][] visitedBoard = new boolean[n][n];
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (game_board[i][j] == 1 || visitedBoard[i][j]) continue;
                List<int[]> shape = bfs(i, j, game_board, visitedBoard, 0);
                normalize(shape);
                blanks.add(shape);
            }
        }
        
        ArrayList<List<int[]>> pieces = new ArrayList<>();
        boolean[][] visitedTable = new boolean[n][n];
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (table[i][j] == 0 || visitedTable[i][j]) continue;
                List<int[]> shape = bfs(i, j, table, visitedTable, 1);
                normalize(shape);
                pieces.add(shape);
            }
        }
        
        boolean[] used = new boolean[pieces.size()];
        
        for (List<int[]> blank : blanks) {
            for (int i = 0; i < pieces.size(); i++) {
                if (used[i]) continue;
                if (blank.size() != pieces.get(i).size()) continue;
                
                if (match(blank, pieces.get(i))) {
                    used[i] = true;
                    answer += blank.size();
                    break;
                }
            }
        }
        
        return answer;
    }
    
    int[] dx = {1, 0, -1, 0};
    int[] dy = {0, 1, 0, -1};
    private List<int[]> bfs(int x, int y, int[][] board, boolean[][] visited, int target) {
        int n = board.length;
        int m = board[0].length; 
        
        Queue<int[]> q = new LinkedList<>();
        List<int[]> shape = new ArrayList<>();
        
        q.offer(new int[]{x, y});
        visited[x][y] = true;
        
        while(!q.isEmpty()) {
            int[] cur = q.poll();
            int cur_x = cur[0];
            int cur_y = cur[1];
            
            shape.add(new int[]{cur_x, cur_y});
            
            for (int dir = 0; dir < 4; dir++) {
                int nx = cur_x + dx[dir];
                int ny = cur_y + dy[dir];
                
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (board[nx][ny] != target) continue;
                if (visited[nx][ny]) continue;
                
                q.offer(new int[]{nx, ny});
                visited[nx][ny] = true;
            }
        }
        return shape;
    }
    
    private void normalize(List<int[]> shape) {
        int minX = Integer.MAX_VALUE;
        int minY = Integer.MAX_VALUE;
        
        for (int[] p : shape) {
            minX = Math.min(minX, p[0]);
            minY = Math.min(minY, p[1]);
        }
        
        for (int[] p : shape) {
            p[0] -= minX;
            p[1] -= minY;
        }
        
        shape.sort((a, b) -> {
            if (a[0] == b[0]) return a[1] - b[1]; 
            return a[0] - b[0];
        });
    }
    
    private boolean match(List<int[]> blank, List<int[]> piece) {
        List<int[]> cur = copy(piece);
        
        for (int r = 0; r < 4; r++) {
            if (isSame(blank, cur)) return true;
            cur = rotate(cur);
        }
        return false;
    }
    
    private List<int[]> copy(List<int[]> shape) {
        List<int[]> res = new ArrayList<>();
        for (int[] p : shape) {
            res.add(new int[]{p[0], p[1]});
        }
        return res;
    }
    
    private boolean isSame(List<int[]> a, List<int[]> b) {
        if (a.size() != b.size()) return false;
        
        for (int i = 0; i < a.size(); i++) {
            if (a.get(i)[0] != b.get(i)[0] || a.get(i)[1] != b.get(i)[1]) {
                return false;
            }
        }
        return true;
    }
    
    private List<int[]> rotate(List<int[]> shape) {
        List<int[]> rotated = new ArrayList<>();
        for (int[] p : shape) {
            rotated.add(new int[]{p[1], -p[0]});
        }
        normalize(rotated);
        return rotated;
    }
}