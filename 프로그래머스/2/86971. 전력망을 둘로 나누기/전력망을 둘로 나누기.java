import java.util.*;

class Solution {
    private boolean[][] graph;
    public int solution(int n, int[][] wires) {
        graph = new boolean[n + 1][n + 1];
        for(int[] w : wires) {
            graph[w[0]][w[1]] = graph[w[1]][w[0]] = true;
        }
        
        int answer = Integer.MAX_VALUE;
        for(int[] w : wires) {
            int a = w[0];
            int b = w[1];
            graph[a][b] = graph[b][a] = false;
            
            int cnt = bfs(n, a);
            int diff = Math.abs(n - cnt - cnt);
            answer = Math.min(answer, diff);
            
            graph[a][b] = graph[b][a] = true;
            
        }
        return answer;
    }
    
    private int bfs(int n, int start) {
        boolean[] visited = new boolean[n + 1];
        Queue<Integer> q = new LinkedList<>();
        visited[start] = true;
        q.offer(start);
        int cnt = 1;
        
        while(!q.isEmpty()) {
            int current = q.poll();
            for(int i = 1; i <= n; i++) {
                if(graph[current][i] && !visited[i]) {
                    q.offer(i);
                    visited[i] = true;
                    cnt++;
                }
            }
        }
        return cnt;
    }
}