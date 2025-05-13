import java.util.*;
class Solution {
    List<String> list = new ArrayList<>();
    public int solution(String word) {
        int answer = 0;
        dfs("AEIOU", "", 0);
        return list.indexOf(word) + 1;
    }
    private void dfs(String aeiou, String current, int depth) {
        if (!current.equals("")) {
            list.add(current);
        }
        if (depth == 5) return;
        for(int i = 0; i < aeiou.length(); i++) {
            dfs(aeiou, current + aeiou.charAt(i), depth + 1);
        }
    }
}