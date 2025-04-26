import java.util.*;
class Solution {
    static HashSet<Integer> set = new HashSet<>();
    static boolean[] visited;
    public int solution(String numbers) {
        visited = new boolean[numbers.length()];
        dfs(numbers, "", 0);
        
        int count = 0;
        for(int num : set) {
            if (isPrime(num)) {
                count++;
            }
        }
        
        return count;
    }
    private void dfs(String numbers, String current, int depth) {
        if (!current.equals("")) {
            set.add(Integer.parseInt(current));
        }
        
        if (depth == numbers.length()) {
            return;
        }
        
        for(int i = 0; i < numbers.length(); i++) {
            if(!visited[i]){
                visited[i] = true;
                dfs(numbers, current + numbers.charAt(i), depth + 1);
                visited[i] = false;
            }
        }
    }
    
    private boolean isPrime(int num) {
        if (num <= 1) return false;
        
        for(int i = 2; i <= Math.sqrt(num); i++) {
            if (num % i == 0) return false;
        }
        return true;
    }
}