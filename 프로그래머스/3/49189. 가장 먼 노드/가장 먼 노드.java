import java.util.*;

class Solution {
    int n;
    List<Integer>[] edgeList;
    int[] dist;
        
    public int solution(int n, int[][] edge) {
        int answer = 0;
        this.n = n;
        
        edgeList = new ArrayList[n + 1];
        for (int i = 1; i <= n; i++) {
            edgeList[i] = new ArrayList<>();
        }
        
        for (int[] e : edge) {
            edgeList[e[0]].add(e[1]);
            edgeList[e[1]].add(e[0]);
        }
        
        bfs(1);
        
        int maxVal = 0;
        for (int i = 1; i <= n; i++) {
            if (maxVal < dist[i]) {
                answer = 1;
                maxVal = dist[i];
            }
            else if (maxVal == dist[i]) answer++;
        }
        return answer;
    }
    
    private void bfs(int start) {
        Queue<Integer> q = new ArrayDeque<>();
        dist = new int[n + 1];
        Arrays.fill(dist, -1);
        
        dist[start] = 0;
        q.offer(start);
        
        while(!q.isEmpty()) {
            int cur = q.poll();
            
            for (int next : edgeList[cur]) {
                if (dist[next] != -1) continue;
                
                q.offer(next);
                dist[next] = dist[cur] + 1;
            }
        }
    }
}