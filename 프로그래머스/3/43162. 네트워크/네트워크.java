class Solution {
    static boolean visited[];
    public int solution(int n, int[][] computers) {
        visited = new boolean[n];
        int answer = 0;
        
        for(int i = 0; i < n; i++){
            if (!visited[i]) {
                dfs(i, computers, n);
                answer++;
            }
        }
        return answer;
    }
    private void dfs(int v, int[][] computers, int n) {
        visited[v] = true;
        
        for(int i = 0; i < n; i++) {
            if (!visited[i] && computers[v][i] == 1) {
                dfs(i, computers, n);
            }
        }
    }
}