class Solution {
    public int solution(int n, int[][] computers) {
        boolean[] visited = new boolean[n];
        int answer = 0;
        for(int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, computers, visited, n);
                answer++;
            }
        }
        return answer;
    }
    
    private void dfs(int start, int[][] computers, boolean[] visited, int n) {
        visited[start] = true;
        for(int i = 0 ; i < n; i++) {
            if (computers[start][i] == 1 && !visited[i]) {
                dfs(i, computers, visited, n);
            }
        }
    }
}