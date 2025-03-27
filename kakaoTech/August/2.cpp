#include <iostream>
#include <vector>

using namespace std;

long dp[501][501];
const long MOD = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M, K;
	cin >> N >> M >> K;

	for(int i = 0; i < K; i++) {
		int a, b;
		cin >> a >> b;
		dp[a - 1][b - 1] = -1;
	}

	dp[0][0] = 1;

	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			if (dp[i][j] == -1) continue;
			for(int k = 1; k <= 6; k++) {
				if (i - k >= 0 && dp[i - k][j] != -1) {
					dp[i][j] = (dp[i][j] + dp[i - k][j]) % MOD;
				}
				if (j - k >= 0 && dp[i][j - k] != -1) {
					dp[i][j] = (dp[i][j] + dp[i][j - k]) % MOD;
				}
			}
		}
	}

	cout << dp[N - 1][M - 1];
	
	
	return 0;
}
