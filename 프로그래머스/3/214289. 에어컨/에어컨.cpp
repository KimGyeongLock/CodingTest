#include <string>
#include <vector>

using namespace std;

int solution(int temperature, int t1, int t2, int a, int b, vector<int> onboard) {
    const int OFFSET = 10;
    const int MIN_T = -10;
    const int MAX_T = 40;
    const int T_SIZE = MAX_T - MIN_T + 1;
    const int INF = 1e9;
    
    int n = onboard.size();
    vector<vector<int>> dp(n, vector<int>(T_SIZE, INF));
    
    dp[0][temperature - MIN_T] = 0;
    
    for (int i = 0; i < n - 1; i++) {
        for (int curT = MIN_T; curT <= MAX_T; curT++) {
            int curIdx = curT - MIN_T;
            int curCost = dp[i][curIdx];
            if (curCost == INF) continue;
            
            // ---------- 1) 에어컨 OFF ----------
            int nextT = curT;
            if (curT < temperature) nextT++;
            else if (curT > temperature) nextT--;
            
            if (nextT >= MIN_T && nextT <= MAX_T) {
                if (onboard[i+1] == 0 || (t1 <= nextT && nextT <= t2)) { // 손님 없거나, 현재 희망온도 안에 있을 경우
                    int nextIdx = nextT - MIN_T;
                    dp[i+1][nextIdx] = min(dp[i+1][nextIdx], curCost);
                }
            }
            
            // ---------- 2) 에어컨 ON ----------
            for (int d = -1; d <= 1; d++) {
                int t2next = curT + d;
                if (t2next < MIN_T || t2next > MAX_T) continue;
                
                if (onboard[i+1] == 1 && !(t1 <= t2next && t2next <= t2)) continue;
                
                int addCost = (d == 0 ? b : a);
                int nextIdx = t2next - MIN_T;
                dp[i+1][nextIdx] = min(dp[i+1][nextIdx], curCost + addCost);
            }
        }
    }
    
    int answer = INF;
    for (int t = MIN_T; t <= MAX_T; t++) {
        answer = min(answer, dp[n-1][t - MIN_T]);
    }
    return answer;
}