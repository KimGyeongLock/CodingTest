import java.util.*;

class Solution {
    public int solution(int[] nums) {
        HashSet<Integer> set = new HashSet<>();
        for(int i : nums) {
            set.add(i);
        }
        
        int answer = Math.min(set.size(), nums.length / 2);
        return answer;
    }
}