import java.util.*;

class Solution {
    public int[] solution(String s) {
        int cnt = -1;
        for (char c : s.toCharArray()) if (c == '}') cnt++;
        int[] answer = new int[cnt];
    
        Set<Integer>[] list = new HashSet[cnt];
        Set<Integer> set = new HashSet<>();
        String num = "";
        
        for (int i = 1; i < s.length() - 1; i++) {
            if (s.charAt(i) >= '0' && s.charAt(i) <= '9') {
                num += String.valueOf(s.charAt(i));
            } else if (s.charAt(i) == '}') {
                if (!num.isEmpty()) set.add(Integer.parseInt(num));
                list[set.size() - 1] = set;
                set = new HashSet<>();
                num = "";
            }
            if (s.charAt(i) == ',' && !num.isEmpty()) {
                set.add(Integer.parseInt(num));
                num = "";
            }
        }
        
        Set<Integer> ss = new HashSet<>();
        for (int i = 0; i < cnt; i++) {
            for (int a : list[i]) {
                if (ss.contains(a)) continue;
                answer[i] = a;
                ss.add(a);
            }
        }
        
        return answer;
    }
}