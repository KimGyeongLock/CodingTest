import java.util.*;
class Solution {
    static int MAX = 1_000_001;
    public int[] solution(int[][] edges) {
        int[] answer = new int[4];
        
        int[] indegree = new int[MAX];
        int[] outdegree = new int[MAX];
        int maxNumber = 0;
        
        for (int[] edge : edges) {
            indegree[edge[1]]++;
            outdegree[edge[0]]++;
            maxNumber = Math.max(maxNumber, edge[0]);
            maxNumber = Math.max(maxNumber, edge[1]);
        }
        
        // 정점
        for (int i = 1; i <= maxNumber; i++) {
            if (indegree[i] == 0 && outdegree[i] >= 2) answer[0] = i;
        }
        
        // 막대 모양
        for (int i = 1; i <= maxNumber; i++) {
            if (outdegree[i] == 0 && indegree[i] >= 1) answer[2]++;
        }
        
        // 8자 모양
        for (int i = 1; i <= maxNumber; i++) {
            if (outdegree[i] >= 2 && indegree[i] >= 2) answer[3]++;
        }
        
        // 도넛 모양
        answer[1] = outdegree[answer[0]] - answer[2] - answer[3];
        
        return answer;
    }
}