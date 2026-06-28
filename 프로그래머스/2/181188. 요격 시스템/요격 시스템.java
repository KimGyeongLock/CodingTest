import java.util.*;
class Solution {
    public int solution(int[][] targets) {
        int answer = 0;
        
        Arrays.sort(targets, (a, b) -> a[1] - b[1]);
        int flag = 0;
        for (int[] target : targets) {
            if(target[0] >= flag) {
                answer++;
                flag = target[1];
            }
        }
        
        return answer;
    }
}