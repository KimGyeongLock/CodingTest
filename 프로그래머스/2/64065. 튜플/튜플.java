import java.util.*;

class Solution {
    public int[] solution(String s) {        
        s = s.substring(2, s.length() - 2);
        String[] groups = s.split("\\},\\{");
        
//         for (String g : groups) {
//             System.out.println(g);
//         }
        
        List<Set<Integer>> list = new ArrayList<>();
        
        for (String group : groups) {
            Set<Integer> set = new HashSet<>();
            
            for (String num : group.split(",")) {
                set.add(Integer.parseInt(num));
            }
            
            list.add(set);
        }
        
        list.sort(Comparator.comparingInt(Set::size));
        
        int[] answer = new int[list.size()];
        Set<Integer> visited = new HashSet<>();
        
        for (int i = 0; i < list.size(); i++) {
            for (int num : list.get(i)) {
                if (visited.add(num)) {
                    answer[i] = num;
                    break;
                }
            }
        }
        
        return answer;
    }
}