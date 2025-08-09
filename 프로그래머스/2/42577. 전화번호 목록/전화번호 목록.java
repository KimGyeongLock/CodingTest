import java.util.*;

class Solution {
    public boolean solution(String[] phone_book) {
        Set<String> set = new HashSet<>(Arrays.asList(phone_book));
        for (String num : phone_book) {
            for (int cut = 1; cut < num.length(); cut++) {
                if (set.contains(num.substring(0, cut))) return false;
            }
        }
        return true;
    }
}