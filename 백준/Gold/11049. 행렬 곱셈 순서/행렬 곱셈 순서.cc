#include <iostream>
#include <vector>
#include <climits>

using namespace std;

long DP[501][501];
vector<pair<int, int> > A;

long execute(int s, int e) {
    long result = INT_MAX;
    // 메모이제이션
    if (DP[s][e] != -1) {
        return DP[s][e];
    }

    if (s == e) { //행렬 한 개의 곱셈 연산의 수
        return 0;
    }
    if (s + 1 == e) { //행렬 두 개의 곱셈 연산의 수
        return A[s].first * A[e].first * A[e].second;
    }

    for(int i = s; i < e; i++) {
        result = min(result, execute(s, i) + execute(i + 1, e) + A[s].first * A[i].second * A[e].second);
    }
    return DP[s][e] = result; // 메모이제이션
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    A.resize(N + 1);
    for(int i = 0; i <= N; i++) {
        for(int j = 0; j <= N; j++) {
            DP[i][j] = -1;
        }
    }

    for(int i = 1; i <= N; i++) {
        int x, y;
        cin >> x >> y;
        A[i] = make_pair(x, y);
    }

    cout << execute(1, N);
}