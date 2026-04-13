class Solution {
    int answer = Integer.MAX_VALUE;
    public int solution(String begin, String target, String[] words) {
        boolean[] visited = new boolean[words.length];
        dfs(0, begin, words, target, visited);
        return answer == Integer.MAX_VALUE ? 0 : answer;
    }
    
    private boolean compare(String a, String b) {
        int n = a.length();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (a.charAt(i) != b.charAt(i)) cnt++;
        }
        return cnt == 1;
    }
    
    private void dfs(int depth, String text, String[] words, String target, boolean[] visited) {
        if (text.equals(target)) {
            answer = Math.min(answer, depth);
            return;
        }
        for (int i = 0; i < words.length; i++) {
            String word = words[i];
            if (visited[i]) continue;
            if (compare(text, word)) {
                visited[i] = true;
                dfs(depth+1, word, words, target, visited);
                visited[i] = false;
            }
        }
    }
}