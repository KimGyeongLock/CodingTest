class Solution {
    public int[] solution(int m, int n, int startX, int startY, int[][] balls) {
        int[] answer = new int[balls.length];
        for (int i = 0; i < balls.length; i++) {
            int targetX = balls[i][0];
            int targetY = balls[i][1];
            
            int res = Integer.MAX_VALUE;
            
            // 위
            if (!(startX == targetX && targetY < startY)) {
                res = Math.min(res, dist(startX, startY, targetX, -targetY));
            }
            
            // 아래
            if (!(startX == targetX && targetY > startY)) {
                res = Math.min(res, dist(startX, startY, targetX, 2 * n - targetY));
            }
            
            // 왼
            if (!(startX > targetX && targetY == startY)) {
                res = Math.min(res, dist(startX, startY, -targetX, targetY));
            }
            
            // 오
            if (!(startX < targetX && targetY == startY)) {
                res = Math.min(res, dist(startX, startY, 2 * m - targetX, targetY));
            }
            answer[i] = res;
        }
        return answer;
    }
    
    private int dist(int x1, int y1, int x2, int y2) {
        int dx = x1 - x2;
        int dy = y1 - y2;
        return dx * dx + dy * dy;
    }
}