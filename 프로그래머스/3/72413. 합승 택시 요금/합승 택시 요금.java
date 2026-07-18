import java.util.*;

class Solution {
    List<int[]>[] edgeList;
    int n;
    public int solution(int n, int s, int a, int b, int[][] fares) {
        int answer = Integer.MAX_VALUE;
        this.n = n;
        edgeList = new ArrayList[n + 1];
        for (int i = 1; i <= n; i++) {
            edgeList[i] = new ArrayList<>();
        }
        
        for (int[] fare : fares) {
            edgeList[fare[0]].add(new int[]{fare[1], fare[2]});
            edgeList[fare[1]].add(new int[]{fare[0], fare[2]});
        }
        
        int[] distS = dijkstra(s);
        int[] distA = dijkstra(a);
        int[] distB = dijkstra(b);
        
        for (int i = 1; i <= n; i++) {
            answer = Math.min(answer, distS[i] + distA[i] + distB[i]);
        }
        
        return answer;
    }
    
    private int[] dijkstra(int s) {
        PriorityQueue<int[]> pq = 
            new PriorityQueue<>((o1, o2) -> Integer.compare(o1[0], o2[0]));
        pq.offer(new int[]{0, s});
        int[] dist = new int[n + 1];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[s] = 0;
        
        while(!pq.isEmpty()) {
            int[] cur = pq.poll();
            int weight = cur[0];
            int node = cur[1];
            
            if (weight > dist[node]) continue;
            
            for (int[] next : edgeList[node]) {
                int nextNode = next[0];
                int nextWeight = next[1];
                
                int total = nextWeight + weight;
                    
                if (dist[nextNode] > total) {
                    dist[nextNode] = total;
                    pq.offer(new int[]{total, nextNode});
                }
            }
        }
        
        return dist;
    }
}