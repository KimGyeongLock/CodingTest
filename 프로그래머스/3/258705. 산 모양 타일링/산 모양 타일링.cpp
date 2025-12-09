#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> tops) {
    const int MOD = 10007;
    vector<int> dp1(n); // 마름모로 안끝남
    vector<int> dp2(n); // 마름모로 끝남
    
    dp1[0] = tops[0] == 0 ? 2 : 3;
    dp2[0] = 1;
    
    for (int i = 1; i < n; i++) {
        if (tops[i] == 1) dp1[i] = (dp1[i-1] * 3 + dp2[i-1] * 2) % MOD;
        else if (tops[i] == 0) dp1[i] = (dp1[i-1] * 2 + dp2[i-1] * 1) % MOD;
        dp2[i] = (dp1[i-1] + dp2[i-1]) % MOD;
    }
    
    return (dp1[n-1] + dp2[n-1])%MOD;
}