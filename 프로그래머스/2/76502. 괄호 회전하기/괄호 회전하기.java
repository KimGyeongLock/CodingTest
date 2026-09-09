import java.util.*;

class Solution {
    public int solution(String s) {
        int answer = 0;
        
        Deque<Character> q = new ArrayDeque<>();
        for (char c : s.toCharArray()) {
            q.offerLast(c);
        }
        
        for (int i = 0; i < s.length(); i++) {
            if(isPossible(q)) answer++;
            char c = q.pollFirst();
            q.offerLast(c);
        }
        
        return answer;
    }
    
    private boolean isPossible(Deque<Character> q) {
        Deque<Character> st = new ArrayDeque<>();
        
        for (char c : q) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                // 닫는 괄호인데 앞에 여는 괄호가 없음
                if (st.isEmpty()) return false;
                
                char top = st.pop();
                
                if (c == ')' && top != '(') return false;
                if (c == '}' && top != '{') return false;
                if (c == ']' && top != '[') return false;
            }
        }
        
        return st.isEmpty();
    }
}