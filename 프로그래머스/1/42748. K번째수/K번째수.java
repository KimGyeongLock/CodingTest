import java.util.*;
class Solution {
    public int[] solution(int[] array, int[][] commands) {
        List<Integer> result = new ArrayList<>();
        
        for(int[] command : commands) {
            int[] temp = Arrays.copyOfRange(array, command[0] - 1, command[1]);
            Arrays.sort(temp);
            result.add(temp[command[2] - 1]);
        }
                
        return result.stream().mapToInt(i -> i).toArray();
    }
}