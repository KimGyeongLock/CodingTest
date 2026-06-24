class Solution {
    public int solution(String[] board) {        
        int o = 0;
        int x = 0;
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[i].length(); j++) {
                if (board[i].charAt(j) == 'O') o++;
                else if (board[i].charAt(j) == 'X') x++;
            }
        }
        
        if (o != x && o != x + 1) return 0;
        boolean oWin = line(board, 'O');
        boolean xWin = line(board, 'X');
        
        if (oWin && xWin) return 0;
        if (oWin && o != x + 1) return 0;
        if (xWin && o != x) return 0;
        return 1;
    }
    
    private boolean line(String[] board, char c) {
        for (int i = 0; i < 3; i++) {
            int cnt = 0;
            for (int j = 0; j < 3; j++) {
                if (board[i].charAt(j) == c) cnt++;
            }
            if (cnt == 3) return true;
        }
        for (int i = 0; i < 3; i++) {
            int cnt = 0;
            for (int j = 0; j < 3; j++) {
                if (board[j].charAt(i) == c) cnt++;
            }
            if (cnt == 3) return true;
        }
        int cnt = 0;
        for (int i = 0; i < 3; i++) {
            if (board[i].charAt(i) == c) cnt++;
        }
        if (cnt == 3) return true;
        cnt = 0;
        for (int i = 0; i < 3; i++) {
            if (board[i].charAt(2 - i) == c) cnt++;
        }
        if (cnt == 3) return true;
        return false;
    }
}