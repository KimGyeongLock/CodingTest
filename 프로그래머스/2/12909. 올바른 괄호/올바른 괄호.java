import java.util.*;
class Solution {
    boolean solution(String s) {
        Stack<Character> st = new Stack<>();
        for (char c : s.toCharArray()) {
            if (c == '(') st.push(c);
            else {
                if (st.isEmpty()) return false;
                else if (st.peek() == '(') st.pop();
            }
        }
        if (st.isEmpty()) return true;
        else return false;
    }
}