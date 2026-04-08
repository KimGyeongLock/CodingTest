class Solution {
    int answer = -1;
    public int solution(int k, int[][] dungeons) {
        boolean[] visited = new boolean[dungeons.length];
        dfs(0, 0, k, dungeons, visited);
        return answer;
    }
    
    private void dfs(int depth, int idx, int k, int[][] dungeons, boolean[] visited) {
        answer = Math.max(answer, depth);
        for (int i = 0; i < dungeons.length; i++) {
            if (visited[i]) continue;
            if (dungeons[i][0] <= k) {
                visited[i] = true;
                dfs(depth+1, i, k - dungeons[i][1], dungeons, visited);
                visited[i] = false;
            }
        }
    }
}