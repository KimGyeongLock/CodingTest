import java.util.*;

class Solution {
    List<int[]>[] edge;
    int N, K;
    
    public int solution(int N, int[][] road, int K) {
        this.N = N;
        this.K = K;
        
        edge = new ArrayList[N + 1];
        for (int i = 1; i <= N; i++) {
            edge[i] = new ArrayList<>();
        }
        
        for (int[] r : road) {
            edge[r[0]].add(new int[]{r[1], r[2]});
            edge[r[1]].add(new int[]{r[0], r[2]});
        }
        
        return dijkstra(1);
    }
    
    private int dijkstra(int start) {
        PriorityQueue<int[]> pq = 
            new PriorityQueue<>((o1, o2) -> Integer.compare(o1[1], o2[1]));
        int[] dist = new int[N + 1];
        Arrays.fill(dist, Integer.MAX_VALUE);
        
        dist[start] = 0;
        pq.offer(new int[]{start, 0});
        
        while(!pq.isEmpty()) {
            int[] cur = pq.poll();
            int node = cur[0];
            int weight = cur[1];
            
            if (dist[node] < weight) continue;
            
            for (int[] next : edge[node]) {
                int total = weight + next[1];
                if (dist[next[0]] > total) {
                    dist[next[0]] = total;
                    pq.offer(new int[]{next[0], total});
                }
            }
        }
        
        int cnt = 0;
        for (int i = 1; i <= N; i++) {
            if (dist[i] <= K) cnt++;
        }
        return cnt;
    }
}