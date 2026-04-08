import java.util.*;
class Solution {
    HashSet<Integer> set = new HashSet<>();
    public int solution(String numbers) {
        boolean[] visited = new boolean[numbers.length()];
        dfs("", numbers, visited);
       
        int answer = 0;
        for (int s : set) {
            if (isPrime(s)) answer++;
        }
        return answer;
    }
    
    private void dfs(String current, String numbers, boolean[] visited) {
        if (!current.equals("")) {
            set.add(Integer.parseInt(current));
        }
        for (int i = 0; i < numbers.length(); i++) {
            if(!visited[i]) {
                visited[i] = true;
                dfs(current + numbers.charAt(i), numbers, visited);
                visited[i] = false;
            }
        }
    }
    
    private boolean isPrime(int x) {
        if (x < 2) return false;
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) return false;
        }
        return true;
    }
}