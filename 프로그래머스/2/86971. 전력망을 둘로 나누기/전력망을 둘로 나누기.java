import java.util.*;

class Solution {
    public int solution(int n, int[][] wires) {
        int answer = Integer.MAX_VALUE;
        int s = wires.length;
        
        for (int i = 0; i < s; i++) {
            ArrayList<ArrayList<Integer>> edgeList = new ArrayList<>();
            
            for (int j = 0; j <= n; j++) {
                edgeList.add(new ArrayList<>());
            }
            
            for (int j = 0; j < s; j++) {
                if (j == i) continue; 
                edgeList.get(wires[j][0]).add(wires[j][1]);
                edgeList.get(wires[j][1]).add(wires[j][0]);
            }
            
            boolean[] visited = new boolean[n + 1];
            int cnt = dfs(1, visited, edgeList);
            
            answer = Math.min(answer, Math.abs(cnt - n + cnt));
        }
        
        return answer;
    }
    
    private int dfs(int start, boolean[] visited, ArrayList<ArrayList<Integer>> edgeList) {
        int cnt = 1;
        visited[start] = true;
        for (int nxt : edgeList.get(start)) {
            if (visited[nxt]) continue;
            cnt += dfs(nxt, visited, edgeList);
        }
        return cnt;
    }
}