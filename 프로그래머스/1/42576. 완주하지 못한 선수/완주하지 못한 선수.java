import java.util.*;
class Solution {
    public String solution(String[] participant, String[] completion) {
        HashMap<String, Integer> s = new HashMap<>();
        for(String c : completion) {
            s.put(c, s.getOrDefault(c, 0) + 1);
        }
        
        for(String p : participant) {
            if (!s.containsKey(p) ||  s.get(p) == 0) {
                return p;
            }
            s.put(p, s.get(p) - 1);
        }
        return "";
    }
}