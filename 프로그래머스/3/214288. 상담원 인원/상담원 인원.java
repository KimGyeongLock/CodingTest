import java.util.*;

class Solution {
    int k, n;
    int[][] wait;
    int answer = Integer.MAX_VALUE;
    
    public int solution(int k, int n, int[][] reqs) {
        this.k = k;
        this.n = n;
        
        wait = new int[k + 1][n + 1];
        
        List<int[]>[] list = new ArrayList[k + 1];
        
        for(int i = 1; i <= k; i++) {
            list[i] = new ArrayList<>();
        }
        
        for (int[] req : reqs) {
            int start = req[0];
            int time = req[1];
            int type = req[2];
            
            list[type].add(new int[]{start, time});
        }
        
        // wait[type][cnt]
        for (int type = 1; type <= k; type++) {
            for (int cnt = 1; cnt <= n; cnt++) {
                wait[type][cnt] = getWaitTime(list[type], cnt);
            }
        }
        
        dfs(1, n, 0);
        
        return answer;
    }
    
    private void dfs(int type, int remain, int totalWait) {
        if (type == k + 1) {
            if (remain == 0) {
                answer = Math.min(answer, totalWait);
            }
            return;
        }
        
        int leftTypes = k - type; // 3
        
        for (int cnt = 1; cnt <= remain - leftTypes; cnt++) {
            dfs(type + 1, remain - cnt, totalWait + wait[type][cnt]);
        }
    }
    
    private int getWaitTime(List<int[]> reqList, int mentorCount) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        
        for (int i = 0; i < mentorCount; i++) {
            pq.offer(0);
        }
        
        int totalWait = 0;
        
        for (int[] req : reqList) {
            int start = req[0];
            int duration = req[1];
            
            int availableTime = pq.poll();
            
            if (availableTime <= start) {
                pq.offer(start + duration); // 일 줌
            } else {
                totalWait += availableTime - start; // 기다리는 시간
                pq.offer(availableTime + duration);
            }
        }
        
        return totalWait;
    }
}