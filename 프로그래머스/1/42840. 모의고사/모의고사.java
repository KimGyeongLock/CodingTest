import java.util.*;
class Solution {
    public int[] solution(int[] answers) {
        int[] answer = {};
        int[][] people = {{1, 2, 3, 4, 5},
                          {2, 1, 2, 3, 2, 4, 2, 5},
                          {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}
                         };
        int[] point = {0, 0, 0};
        
        int n = answers.length;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                int m = people[j].length;
                if (answers[i] == people[j][i % m]) point[j]++;
            }
        }
        int max = Math.max(point[0], Math.max(point[1], point[2]));
        
        ArrayList<Integer> list = new ArrayList<>();
        for (int i = 0; i < 3; i++) {
            if (point[i] == max) {
                list.add(i + 1);
            }
        }
        
        return list.stream().mapToInt(Integer::intValue).toArray();
    }
}