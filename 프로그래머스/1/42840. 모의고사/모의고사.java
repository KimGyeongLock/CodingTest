import java.util.*;
class Solution {
    public int[] solution(int[] answers) {
        int[] method1 = {1, 2, 3, 4, 5};
        int[] method2 = {2, 1, 2, 3, 2, 4, 2, 5};
        int[] method3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
        
        int one = 0;
        for(int i = 0; i < answers.length; i++) {
            if (answers[i] == method1[i % method1.length]) {
                one++;
            }
        }
        
        int two = 0;
        for(int i = 0; i < answers.length; i++) {
            if (answers[i] == method2[i % method2.length]) {
                two++;
            }
        }
        
        int three = 0;
        for(int i = 0; i < answers.length; i++) {
            if (answers[i] == method3[i % method3.length]) {
                three++;
            }
        }
        int max = Math.max(one, Math.max(two, three));
        
        ArrayList<Integer> result = new ArrayList<>();
        if (one == max) result.add(1);
        if (two == max) result.add(2);
        if (three == max) result.add(3);
    
        
        return result.stream().mapToInt(i -> i).toArray();
    }
}