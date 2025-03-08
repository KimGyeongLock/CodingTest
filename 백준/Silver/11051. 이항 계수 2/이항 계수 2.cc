#include <iostream>

using namespace std;

int D[1001][1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    cin >> N >> K;

    for(int i = 1; i <= N; i++) {
        D[i][1] = i;
        D[i][0] = 1;
        D[i][i] = 1;
    }

    for(int i = 2; i <= N; i++) {
        for(int j = 1; j < i; j++) {
            D[i][j] = (D[i - 1][j] + D[i - 1][j - 1]) % 10007;
        }
    }

    cout << D[N][K];
}