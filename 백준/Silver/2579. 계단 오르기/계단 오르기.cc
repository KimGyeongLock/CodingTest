#include <iostream>
#include <vector>

using namespace std;

vector<int> vec;
vector<int> dp(301);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vec.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> vec[i];
    }

    dp[0] = vec[0];
    dp[1] = vec[0] + vec[1];
    dp[2] = max(vec[0] + vec[2], vec[1] + vec[2]);
    for(int i = 3; i < N; i++) {
        dp[i] = max(dp[i - 3] + vec[i - 1] + vec[i], dp[i - 2] + vec[i]);
    }

    cout << dp[N - 1];
}