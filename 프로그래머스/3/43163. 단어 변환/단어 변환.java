import java.util.*;
class Solution {
    public int solution(String begin, String target, String[] words) {
        boolean[] visited = new boolean[words.length];
        Queue<Node> q = new LinkedList<>();
        
        q.add(new Node(begin, 0));
        
        while(!q.isEmpty()) {
            Node current = q.poll();
            
            if(current.word.equals(target)) {
                return current.count;
            }
            
            for(int i = 0; i < words.length; i++) {
                if (!visited[i] && canChange(current.word, words[i])) {
                    visited[i] = true;
                    q.add(new Node(words[i], current.count + 1));
                }
            }
            
        }
        return 0;
    }
    
    private boolean canChange(String a, String b) {
        int diff = 0;
        for(int i = 0; i < a.length(); i++) {
            if (a.charAt(i) != b.charAt(i)) {
                diff++;
            }
        }
        if (diff == 1) return true;
        return false;
    }
    
    static class Node {
        String word;
        int count;
        
        public Node (String word, int count) {
            this.word = word;
            this.count = count;
        }
    }
}