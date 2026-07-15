class Solution {
    int h, w;
    int[][] board;
    
    int[] dr = {-1, 1, 0, 0};
    int[] dc = {0, 0, -1, 1};
    
    public int solution(int[][] board, int[] aloc, int[] bloc) {
        this.board = board;
        this.h = board.length;
        this.w = board[0].length;
        
        Result result = dfs(aloc[0], aloc[1], bloc[0], bloc[1]);
        
        return result.count;
    }
    
    private Result dfs(int ar, int ac, int br, int bc) {
        if (board[ar][ac] == 0) {
            return new Result(false, 0);
        }
        
        boolean canMove = false;
        boolean canWin = false;
        
        int minWinCount = Integer.MAX_VALUE;
        int maxLoseCount = 0;
        
        for (int d = 0; d < 4; d++) {
            int nr = ar + dr[d];
            int nc = ac + dc[d];
            
            if (!isValid(nr, nc)) continue;
            
            canMove = true;
            
            board[ar][ac] = 0;
            
            Result next = dfs(br, bc, nr, nc);
            
            board[ar][ac] = 1;
            
            if (!next.win) {
                canWin = true;
                minWinCount = Math.min(minWinCount, next.count + 1);
            } else if (!canWin) {
                maxLoseCount = Math.max(maxLoseCount, next.count + 1);
            }
        }
        
        if (!canMove) {
            return new Result(false, 0);
        }
        
        if (canWin) {
            return new Result(true, minWinCount);
        }
        
        return new Result(false, maxLoseCount);
    }
    
    private boolean isValid(int r, int c) {
        return r >= 0 && r < h && c >= 0 && c < w && board[r][c] == 1;
    }
    
    static class Result {
        boolean win;
        int count;
        
        Result(boolean win, int count) {
            this.win = win;
            this.count = count;
        }
    }
}