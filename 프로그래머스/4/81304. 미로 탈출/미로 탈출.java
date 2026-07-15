import java.util.*;

class Solution {
    static final int INF = Integer.MAX_VALUE;
        
    List<Edge>[] graph;
    int[] trapIndex;
    int trapCount;
    
    public int solution(int n, int start, int end, int[][] roads, int[] traps) {
        graph = new ArrayList[n + 1];
        
        for (int i = 1; i <= n; i++) {
            graph[i] = new ArrayList<>();
        }
        
        for (int[] road : roads) {
            int from = road[0];
            int to = road[1];
            int cost = road[2];
            
            graph[from].add(new Edge(to, cost, 0));
            graph[to].add(new Edge(from, cost, 1));
        }
        
        trapCount = traps.length;
        trapIndex = new int[n + 1];
        Arrays.fill(trapIndex, -1);
        
        for (int i = 0; i < trapCount; i++) {
            trapIndex[traps[i]] = i;
        }
        
        int[][] dist = new int[n + 1][1 << trapCount];
        
        for (int i = 1; i <= n; i++) {
            Arrays.fill(dist[i], INF);
        }
        
        PriorityQueue<State> pq = new PriorityQueue<>((a, b) -> a.cost - b.cost);
        
        dist[start][0] = 0;
        pq.offer(new State(start, 0, 0));
        
        while (!pq.isEmpty()) {
            State current = pq.poll();
            
            int currentNode = current.node;
            int currentMask = current.mask;
            int currentCost = current.cost;
            
            if (dist[currentNode][currentMask] < currentCost) {
                continue;
            }
            
            if (currentNode == end) {
                return currentCost;
            }
            
            for (Edge edge : graph[currentNode]) {
                int nextNode = edge.to;
                
                boolean currentTrapOn = isTrapOn(currentNode, currentMask);
                
                boolean nextTrapOn = isTrapOn(nextNode, currentMask);
                
                boolean reversed = currentTrapOn ^ nextTrapOn; // XOR 두 상태가 다르면 true 같으면 false
                
                if ((!reversed && edge.direction == 1) 
                        || (reversed && edge.direction == 0)) continue;
                
                int nextMask = currentMask;
                
                if (trapIndex[nextNode] != -1) { // 함정
                    nextMask ^= (1 << trapIndex[nextNode]);
                }
                
                int nextCost = currentCost + edge.cost;
                
                if (nextCost < dist[nextNode][nextMask]) {
                    dist[nextNode][nextMask] = nextCost;
                    pq.offer(new State(nextNode, nextMask, nextCost));
                }
            }
        }
        return -1;
    }
    
    private boolean isTrapOn(int node, int mask) {
        int index = trapIndex[node];
        
        if (index == -1) {
            return false;
        }
        
        return (mask & (1 << index)) != 0;
    }
    
    static class Edge {
        int to;
        int cost;
        int direction;
        
        Edge(int to, int cost, int direction) {
            this.to = to;
            this.cost = cost;
            this.direction = direction;
        }
    }
    
    static class State{
        int node;
        int mask;
        int cost;
        
        State(int node, int mask, int cost) {
            this.node = node;
            this.mask = mask;
            this.cost = cost;
        }
    }
}