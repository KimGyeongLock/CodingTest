import java.util.*;
class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        ArrayList<Integer> answer = new ArrayList<>();
        int max = 0;
        int cnt = 0;
        int n = progresses.length;
        for (int i = 0; i < n; i++) {
            int remain = 100 - progresses[i];
            int days = remain / speeds[i];
            if (remain % speeds[i] != 0) days++;
            
            if (max < days) {
                if (max != 0) answer.add(cnt);
                max = days;
                cnt = 1;
            } else {
                cnt++;
            }
        }
        answer.add(cnt);
        return answer.stream().mapToInt(Integer::intValue).toArray();
    }
}