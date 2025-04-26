/*
    3 - 2
    1 - 1
    2 - 1
    총 4개 min(2개 키의 갯수 3개)
*/
import java.util.*;
class Solution {
    public int solution(int[] nums) {
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int i : nums) {
            map.put(i, map.getOrDefault(i, 0) + 1);
        }
        
        return Math.min(map.size(), nums.length / 2);
    }
}