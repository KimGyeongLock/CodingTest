class Solution {
    static final long MOD = 1_000_000_007L;

    public int solution(int n) {
        long[] dp = new long[n + 1];
        
        dp[0] = 1;
        if (n >= 1) dp[1] = 1;
        if (n >= 2) dp[2] = 3;
        if (n >= 3) dp[3] = 10;
        
        long[] sum = new long[3];
        
        for (int i = 4; i <= n ; i++) {
            sum[(i - 4) % 3] = (sum[(i - 4) % 3] + dp[i - 4]) % MOD;
            
            dp[i] = (
                    dp[i - 1]
                    + 2 * dp[i - 2]
                    + 5 * dp[i - 3]
                    + 2 * (sum[0] + sum[1] + sum[2])
                    + 2 * sum[i % 3]
            ) % MOD;
        }
        
        return (int) dp[n];
    }
}