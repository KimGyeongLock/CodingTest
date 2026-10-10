class Solution {
    int[][] arr;
    int num = 1;
    
    public int[] solution(int n) {
        arr = new int[n][n];
        
        snail(0, 0, n, 0);
        
        int[] answer = new int[n * (n + 1) / 2];
        int index = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                answer[index++] = arr[i][j];
            }
        }
        return answer;
    }
    
    private void snail(int x, int y, int size, int depth) {
        if (size <= 0) return;
        
        for (int i = 0; i < size; i++) {
            arr[x++][y] = num++;
        }
        x--;
        
        for (int i = 0; i < size - 1; i++) {
            arr[x][++y] = num++; 
        }
        
        for (int i = 0; i < size - 2; i++) {
            arr[--x][--y] = num++;
        }
        
        snail(x + 1, y, size - 3, depth + 1);
    } 
}