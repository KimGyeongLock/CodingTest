import java.util.*;
class Solution {
    public int[] solution(int[] answers) {
        List<Integer> list = new ArrayList<>();
        int[] stuScore = new int[3];
        int[][] students = {
            {1, 2, 3, 4, 5},
            {2, 1, 2, 3, 2, 4, 2, 5},
            {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}
        };
        
        int maxScore = 0;
        for(int i = 0; i < 3; i++){
            int score = 0;
            for(int j = 0; j < answers.length; j++) {
                if(answers[j] == students[i][j % students[i].length]) {
                    score++;
                }
                stuScore[i] = score;
            }
            maxScore = Math.max(maxScore, score);
        }
        
        for(int i = 0; i < 3; i++) {
            if (maxScore == stuScore[i]) list.add(i + 1);
        }
        return list.stream().mapToInt(i -> i).toArray();
    }
}