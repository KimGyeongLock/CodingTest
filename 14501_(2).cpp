#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> t(N);
  vector<int> p(N);
  vector<int> dp(N + 1, 0); // dp[i]는 i일차까지 얻을 수 있는 최대 수익

  for (int i = 0; i < N; i++) {
    cin >> t[i] >> p[i];
  }

  for (int i = 0; i < N; i++) {
    if (i + t[i] <= N) {
      // 이전에 계산했던 값(다른 경우의 수) 와 i날을 선택하게 되었을 때 얻는 수익을 비교하여 최대 수익으로 대체
      dp[i + t[i]] = max(dp[i + t[i]], dp[i] + p[i]);
    }
    // 전날 값과 현재 값을 비교하여 최대로 벌 수 있는 수익으로 대체
    // i번째 날까지의 최대 수익을 다음 날로 전달
    dp[i + 1] = max(dp[i + 1], dp[i]);
  }

  cout << dp[N];
  return 0;
}
