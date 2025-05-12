import java.util.*;
class Solution {
    HashSet<Integer> set = new HashSet<>(); 
    boolean[] visited;
    public int solution(String numbers) {
        int answer = 0;
        visited = new boolean[numbers.length()];
        generateNumbers(numbers, "");

        for(int s : set) {
            if (isPrime(s)) {
                answer++;                
            }
        }
        return answer;
    }
    
    private void generateNumbers(String numbers, String current) {
        if (current != "") {
            set.add(Integer.parseInt(current));
        }
        
        for(int i = 0; i < numbers.length(); i++) {
            if (!visited[i]) {
                visited[i] = true;
                generateNumbers(numbers, current + numbers.charAt(i));
                visited[i] = false;
            }
        }
    }
    
    private boolean isPrime(int a) {
        if (a < 2) return false;
        for(int i = 2; i <= Math.sqrt(a); i++) {
            if (a % i == 0) return false;
        }
        return true;
    }
}