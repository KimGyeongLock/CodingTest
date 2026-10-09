class Solution {
    int[] answer;
    int[][] arr;
    public int[] solution(int[][] arr) {
        this.arr = arr;
        answer = new int[2];
        func(0, 0, arr.length, arr[0].length);
        return answer;
    }
    
    private void func(int x1, int y1, int x2, int y2) {
        int first = -1;
        boolean pass = true;
        for (int i = x1; i < x2; i++) {
            for (int j = y1; j < y2; j++) {
                if (first != -1 && first != arr[i][j]) {
                    pass = false;
                    break;
                }
                first = arr[i][j];
            }
            if (!pass) break;
        }
        
        if (pass) {
            answer[first]++;
            return;
        }
        
        if (x2 - x1 <= 1 || y2 - y1 <= 1) return;
        
        int midX = (x1 + x2) / 2;
        int midY = (y1 + y2) / 2;
        func(x1, y1, midX, midY);
        func(x1, midY, midX, y2);
        func(midX, y1, x2, midY);
        func(midX, midY, x2, y2);
    }
}