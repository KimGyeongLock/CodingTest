import java.util.*;
class Solution {
    public int[] solution(int[] sequence, int k) {
        int[] answer = new int[2];
        int min_v = Integer.MAX_VALUE;
        
        int start = 0;
        int total = 0;
        for (int end = 0; end < sequence.length; end++) {
            total += sequence[end];
            
            while (total > k) {
                int fr = sequence[start++];
                total -= fr;
            }
            if (total == k) {
                int len = end - start + 1;
                if (min_v > len) {
                    min_v = len;
                    answer = new int[]{start, end};
                }
            }
        }
        
        return answer;
    }
}