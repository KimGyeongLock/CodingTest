import java.util.*;
class Solution {
    static int INF = 1_000_000_000;
    static int OFFSET = 10;
    static int MAX = 51;
    public int solution(int temperature, int t1, int t2, int a, int b, int[] onboard) {
        int n = onboard.length;
        int[][] dp = new int[n][MAX];
        
        for (int i = 0; i < n; i++) {
            Arrays.fill(dp[i], INF);
        }
        
        dp[0][temperature + OFFSET] = 0;
        
        for (int time = 0; time < n - 1; time++) {
            for (int idx = 0; idx < MAX; idx++) {
                if (dp[time][idx] == INF) continue;
                int curTemp = idx - OFFSET;
                
                if (onboard[time] == 1 && (curTemp < t1 || curTemp > t2)) continue;
                
                // 1. 에어컨 OFF
                int nextTemp = curTemp;
                if (temperature < curTemp) nextTemp -= 1;
                else if (temperature > curTemp) nextTemp += 1;
                update(dp, time + 1, nextTemp + OFFSET, dp[time][idx]);
                
                // 2. 에어컨 ON - 온도 떨
                update(dp, time + 1, curTemp + OFFSET - 1, dp[time][curTemp + OFFSET] + a);
                
                // 3. 에어컨 ON - 온도 상
                update(dp, time + 1, curTemp + OFFSET + 1, dp[time][curTemp + OFFSET] + a);
                
                // 4. 에어컨 ON - 온도 유지
                update(dp, time + 1, curTemp + OFFSET, dp[time][curTemp + OFFSET] + b);
            }
        }
        
        int answer = INF;
        for (int idx = 0; idx < MAX; idx++) {
            int curTemp = idx - OFFSET;
            if (onboard[n - 1] == 1 && (curTemp < t1 || curTemp > t2)) continue;
            answer = Math.min(answer, dp[n - 1][idx]);
        }
        
        return answer;
    }
    
    private void update(int[][] dp, int time, int idx, int cost) {
        if (idx < 0 || idx >= MAX) return;
        dp[time][idx] = Math.min(dp[time][idx], cost);
    }
}