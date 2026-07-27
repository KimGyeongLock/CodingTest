import java.util.*;

class Solution {
    
    private static class UnionFind {
        int[] parent;
        int[] rank;
        
        UnionFind(int n) {
            parent = new int[n];
            rank = new int[n];
            
            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }
        
        int find(int x) {
            if (parent[x] == x) {
                return x;
            }
            
            return parent[x] = find(parent[x]);
        }
        
        boolean union(int a, int b) {
            int rootA = find(a);
            int rootB = find(b);
            
            if (rootA == rootB) return false;
            
            if (rank[rootA] < rank[rootB]) { // rootA의 랭크가 작으면 전환
                int temp = rootA;
                rootA = rootB;
                rootB = temp;
            }
            
            parent[rootB] = rootA;
            
            if (rank[rootA] == rank[rootB]) {
                rank[rootA]++;
            }
            
            return true;
        }
    }
    
    public int solution(int n, int[][] costs) {
        int answer = 0;
        int edgeCount = 0;
        
        Arrays.sort(costs, (a, b) -> Integer.compare(a[2], b[2]));
        
        UnionFind unionFind = new UnionFind(n);
        
        for (int[] cost : costs) {
            int a = cost[0];
            int b = cost[1];
            int bridgeCost = cost[2];
            
            if (unionFind.union(a, b)) {
                answer += bridgeCost;
                edgeCount++;
                
                if (edgeCount == n - 1) break;
            }
        }
        
        return answer;
    }
}