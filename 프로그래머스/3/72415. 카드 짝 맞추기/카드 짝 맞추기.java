import java.util.*;

class Solution {
    int[][] memo;
    int cardMask = 0;
    private static final int INF = 1_000_000_000;
    int[][] board;
    List<int[]>[] positions;
    
    public int solution(int[][] board, int r, int c) {
        int answer = 0;
        this.board =board;
        positions = new ArrayList[7];
        
        for (int i = 1; i <= 6; i++) {
            positions[i] = new ArrayList<>();
        }
        
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (board[i][j] > 0) {
                    int card = board[i][j];
                    positions[card].add(new int[]{i, j});
                    cardMask |= 1 << card;
                }
            }
        }
        
        memo = new int[1 << 7][16];
        for (int[] m : memo) {
            Arrays.fill(m, -1);
        }
        
        return dfs(cardMask, r * 4 + c); // cardMask : 1110
    }
    
    private int dfs(int mask, int current) {
        if (mask == 0) {
            return 0;
        }
        
        if (memo[mask][current] != -1) {
            return memo[mask][current];
        }
        
        int currentR = current / 4;
        int currentC = current % 4;
        
        int result = INF;
        for (int card = 1; card <= 6; card++) {
            if ((mask & (1 << card)) == 0) {
                continue;
            }
            
            int[] first = positions[card].get(0);
            int[] second = positions[card].get(1);
            
            int nextMask = mask & ~(1 << card);
            
            int firstOrder = move(currentR, currentC, first[0], first[1], mask)
                             + move(first[0], first[1], second[0], second[1], mask)
                             + 2
                             + dfs(nextMask, second[0] * 4 + second[1]); // 1 -> 2
            int secondOrder = move(currentR, currentC, second[0], second[1], mask)
                              + move(second[0], second[1], first[0], first[1], mask)
                              + 2
                              + dfs(nextMask, first[0] * 4 + first[1]);
            
            result = Math.min(result, Math.min(firstOrder, secondOrder));
        }
        
        return memo[mask][current] = result;
    }
    
    static int[] dr = {-1, 1, 0, 0};
    static int[] dc = {0, 0, 1, -1};
    
    private int move(int sr, int sc, int tr, int tc, int mask) {
        if (sr == tr && sc == tc) return 0;
        
        boolean[][] visited = new boolean[4][4];
        Queue<int[]> q = new ArrayDeque<>();
        
        q.offer(new int[]{sr, sc, 0});
        visited[sr][sc] = true;
        
        while(!q.isEmpty()) {
            int[] current = q.poll();
            
            int r = current[0];
            int c = current[1];
            int distance = current[2];
            
            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d];
                int nc = c + dc[d];
                
                if (!(nr < 0 || nr >= 4 || nc < 0 || nc >= 4) && !visited[nr][nc]) {
                    if (nr == tr && nc == tc) {
                        return distance + 1;
                    }
                    
                    visited[nr][nc] = true;
                    q.offer(new int[]{nr, nc, distance + 1});
                }
                
                // Ctrl + 방향키
                int[] ctrlPosition = ctrlMove(r, c, d, mask);
                nr = ctrlPosition[0];
                nc = ctrlPosition[1];
                
                if (!visited[nr][nc]) {
                    if (nr == tr && nc == tc) {
                        return distance + 1;
                    }
                    visited[nr][nc] = true;
                    q.offer(new int[]{nr, nc, distance + 1});
                }
            }
        }
        return -1;
    }
    
    private int[] ctrlMove(int r, int c, int direction, int mask) {
        int nr = r;
        int nc = c;
        
        while (true) {
            int nextR = nr + dr[direction];
            int nextC = nc + dc[direction];
            
            if (nextR < 0 || nextR >= 4 || nextC < 0 || nextC >= 4) return new int[]{nr, nc};
            
            nr = nextR;
            nc = nextC;
            
            if (hasCard(nr, nc, mask)) {
                return new int[]{nr, nc};
            }
        }
    }
    
    private boolean hasCard(int r, int c, int mask) {
        int cardNumber = board[r][c];
        if (cardNumber == 0) return false;
        return (mask & (1 << cardNumber)) != 0;
    }
}