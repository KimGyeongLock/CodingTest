#include <iostream>
#include <vector>

using namespace std; 

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<long> A(N), dp(N);

    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    long answer = 0;
    for(int i = 0; i < N; i++) {
        dp[i] = A[i];

        for(int j = 0; j < i; j++) {
            if (A[j] < A[i] && dp[i] < dp[j] + A[i]) {
                dp[i] = dp[j] + A[i];
            }
        }
        answer = max(answer, dp[i]);
    }
    cout << answer;
}