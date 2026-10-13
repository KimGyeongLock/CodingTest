import java.util.*;

class Solution {
    
    long answer = 0;
    public long solution(String expression) {
        
        List<String> list = new ArrayList<>();
        String num = "";
        for (char e : expression.toCharArray()) {
            if (e >= '0' && e <= '9') {
                num += e;    
            } else {
                list.add(num);
                list.add(String.valueOf(e));
                num = "";
            }
        }
        if (!num.isEmpty()) list.add(num);
        
        boolean[] visited = new boolean[3];
        dfs(list, visited);
        return answer;
    }
    
    private static final String[] exp = {"*", "+", "-"};
    
    private void dfs(List<String> list, boolean[] visited) {
        if (list.size() == 1) {
            long res = Math.abs(Long.parseLong(list.get(0)));
            answer = Math.max(answer, res);
            return;
        }
        
        for (int i = 0; i < 3; i++) {
            if (visited[i]) continue;
            visited[i] = true;
            dfs(calculate(list, exp[i]), visited);
            visited[i] = false;
        }
    }
    
    private List<String> calculate(List<String> list, String exp) {
        List<String> newList = new ArrayList<>();
        for (int i = 0; i < list.size(); i++) {
            if (list.get(i).equals(exp)) {
                long a = Long.parseLong(newList.get(newList.size() - 1));
                long b = Long.parseLong(list.get(i + 1));
                
                if (exp.equals("*")) {
                    newList.set(newList.size() - 1, String.valueOf(a * b));
                } else if (exp.equals("+")) {
                    newList.set(newList.size() - 1, String.valueOf(a + b));
                } else {
                    newList.set(newList.size() - 1, String.valueOf(a - b));
                }
                i++;
            } else {
                newList.add(list.get(i));
            }
        }
     
        return newList;
    }
}