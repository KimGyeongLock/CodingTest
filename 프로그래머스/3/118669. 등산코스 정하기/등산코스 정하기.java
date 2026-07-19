import java.util.*;

class Solution {
    List<int[]>[] graph;
    boolean[] isSummit;
    int[] dist;
    
    public int[] solution(int n, int[][] paths, int[] gates, int[] summits) {
        graph = new ArrayList[n + 1];
        isSummit = new boolean[n + 1];
        
        for (int i = 1; i <= n; i++) {
            graph[i] = new ArrayList<>();
        }
        
        for (int[] path : paths) {
            int a = path[0];
            int b = path[1];
            int weight = path[2];
            
            graph[a].add(new int[]{b, weight});
            graph[b].add(new int[]{a, weight});
        }
        
        for (int summit : summits) {
            isSummit[summit] = true;
        }
        
        dijkstra(n, gates);
        
        Arrays.sort(summits);
        
        int selectedSummit = 0;
        int minIntensity = Integer.MAX_VALUE;
        
        for (int summit : summits) {
            if (dist[summit] < minIntensity) {
                minIntensity = dist[summit];
                selectedSummit = summit;
            }
        }
        
        return new int[]{selectedSummit, minIntensity};
    }
    
    private void dijkstra(int n, int[] gates) {
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> Integer.compare(a[1], b[1]));
        
        dist = new int[n + 1];
        Arrays.fill(dist, Integer.MAX_VALUE);
        
        for (int gate : gates) {
            dist[gate] = 0;
            pq.offer(new int[]{gate, 0});
        }

        while(!pq.isEmpty()) {
            int[] cur = pq.poll();
            
            int node = cur[0];
            int intensity = cur[1];
            
            if (dist[node] < intensity) {
                continue;
            }
            
            if (isSummit[node]) {
                continue;
            }
            
            for (int[] next : graph[node]) {
                int nextNode = next[0];
                int edgeWeight = next[1];
                
                int nextIntensity = Math.max(intensity, edgeWeight);
                
                if (dist[nextNode] > nextIntensity) {
                    dist[nextNode] = nextIntensity;
                    pq.offer(new int[]{nextNode, nextIntensity});
                }
            }
        }
    }
}