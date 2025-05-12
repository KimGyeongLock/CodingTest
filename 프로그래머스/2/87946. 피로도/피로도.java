class Solution {
    boolean visited[];
    int answer = -1;
    public int solution(int k, int[][] dungeons) {
        visited = new boolean[dungeons.length];
        dfs(dungeons, k, 0);
        return answer;
    }
    private void dfs(int[][] dungeons, int current, int depth) {
        answer = Math.max(depth, answer);
        
        
        for(int i = 0; i < dungeons.length; i++) {
            if(!visited[i]) {
                if (dungeons[i][0] <= current) {
                    visited[i] = true;
                    dfs(dungeons, current - dungeons[i][1], depth + 1);
                    visited[i] = false;
                }
            }
        }
    }
}