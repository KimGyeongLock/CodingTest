import java.util.*;
class Solution {
    public boolean solution(String[] phone_book) {
        HashMap<String, Integer> map = new HashMap<>();
        
        for(String phone : phone_book) {
            map.put(phone, 1);
        }
        
        for(String phone : phone_book) {
            String prefix = "";
            for(int i = 0; i < phone.length() - 1; i++) {
                prefix += phone.charAt(i);
                if (map.containsKey(prefix)) {
                    return false;
                }
            }
        }
        return true;
    }
}