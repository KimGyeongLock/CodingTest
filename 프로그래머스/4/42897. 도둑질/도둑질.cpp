#include <string>
#include <vector>

using namespace std;

int solution(vector<int> money) {
    int n = money.size();
    vector<int> dp1(n);
    vector<int> dp2(n);
    
    dp1[0] = money[0];
    dp1[1] = money[0];
    // 2번집부터 집을 털지 안털지
    // 안 털 경우 dp1[i-1] : 이전 비용 그대로
    // 털 경우 dp1[i-2] + money[i] : 이전 집은 안털었을 거니까 전전 집 + 현재 비용
    for (int i = 2; i <= n - 2; i++) {
        dp1[i] = max(dp1[i-1], dp1[i-2] + money[i]);
    }
    
    dp2[0] = 0;
    dp2[1] = money[1];
    for (int i = 2; i <= n - 1; i++) {
        dp2[i] = max(dp2[i-1], dp2[i-2] + money[i]);
    }
        
    return max(dp1[n-2], dp2[n-1]);
}