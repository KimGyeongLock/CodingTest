import java.util.*;

class Solution {
    List<Integer>[] edgeList;
    int answer = 0;
    int[] info;
    int n;
    
    public int solution(int[] info, int[][] edges) {
        this.info = info;
        n = info.length;
        edgeList = new ArrayList[n];
        
        for (int i = 0; i < n; i++) {
            edgeList[i] = new ArrayList<>();
        }
        
        for (int[] edge : edges) {
            edgeList[edge[0]].add(edge[1]);
        }
        
        dfs(1);
        return answer;
    }
    
    private void dfs(int mask) {
        int sheep = 0;
        int wolf = 0;
        
        for (int node = 0; node < n; node++) {
            if ((mask & (1 << node)) == 0) continue;
            
            if (info[node] == 0) {
                sheep++;
            } else {
                wolf++;
            }
        }
        
        if (wolf >= sheep) return;
        
        answer = Math.max(answer, sheep);
        
        for (int current = 0; current < n; current++) {
            if ((mask & (1 << current)) == 0) continue;
            
            for (int next : edgeList[current]) {
                if ((mask & (1 << next)) != 0) continue;
                
                dfs(mask | (1 << next));
            }
        }
    }
}