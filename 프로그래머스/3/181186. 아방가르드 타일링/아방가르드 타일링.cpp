// https://ampersandor.tistory.com/21
#include <string>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int solution(int n) {
    vector<long long> dp(100001);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 3;
    dp[3] = 10;
    dp[4] = 23;
    dp[5] = 62;
    dp[6] = 170;
    
    if (n <= 6) return dp[n];
    
    for (int i = 7; i <= n; i++) {
        dp[i] = (dp[i-1] + 2 * dp[i-2] + 6 * dp[i-3] + dp[i-4] - dp[i-6]) % MOD;
        if (dp[i] < 0) {
            dp[i] += MOD;
        }
    }
    
    return (int)dp[n];
}