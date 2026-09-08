import java.util.*;

class Solution {
    int[][] matrix;
    
    public int[] solution(int rows, int columns, int[][] queries) {
        int[] answer = new int[queries.length];
        
        matrix = new int[rows][columns];
        int count = 1;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                matrix[i][j] = count++;
            }
        }
        
        for (int i = 0; i < queries.length; i++) {
            answer[i] = rotate(queries[i]);
        }
        return answer;
    }
    
    private int rotate(int[] query) {
        int x1 = query[0] - 1, y1 = query[1] - 1, x2 = query[2] - 1, y2 = query[3] - 1;
        
        ArrayList<Integer> arr = new ArrayList<>();
        for (int i = y1; i <= y2; i++) arr.add(matrix[x1][i]);
        for (int i = x1 + 1; i <= x2; i++) arr.add(matrix[i][y2]);
        for (int i = y2 - 1; i >= y1; i--) arr.add(matrix[x2][i]);
        for (int i = x2 - 1; i >= x1 + 1; i--) arr.add(matrix[i][y1]);
        
        int index = 0;
        for (int i = y1 + 1; i <= y2; i++) matrix[x1][i] = arr.get(index++);
        for (int i = x1 + 1; i <= x2; i++) matrix[i][y2] = arr.get(index++);
        for (int i = y2 - 1; i >= y1; i--) matrix[x2][i] = arr.get(index++);
        for (int i = x2 - 1; i >= x1 + 1; i--) matrix[i][y1] = arr.get(index++);
        matrix[x1][y1] = arr.get(arr.size() - 1);
        
        Collections.sort(arr);
        
        return arr.get(0);
        // System.out.println("=================");
        // for (int i = 0; i < matrix.length; i++) {
        //     for (int j = 0; j < matrix[0].length; j++) {
        //         System.out.print(matrix[i][j] + " ");
        //     }
        //     System.out.println();
        // }
    }
}