import java.util.*;

class Solution {
    public int solution(int n, int[][] computers) {
        int answer = 0;
        
        ArrayList<ArrayList<Integer>> edgeList = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            edgeList.add(new ArrayList<>());
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (computers[i][j] == 1) {
                    edgeList.get(i).add(j);
                    edgeList.get(j).add(i);
                }
            }
        }
        
        boolean[] visited = new boolean[n];
        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;
            dfs(i, visited, edgeList);
            answer++;
        }
        
        return answer;
    }
    
    private void dfs(int node, boolean[] visited, ArrayList<ArrayList<Integer>> edgeList) {
        visited[node] = true;
        
        for (int nxt : edgeList.get(node)) {
            if (visited[nxt]) continue;
            dfs(nxt, visited, edgeList);
        }
    }
}