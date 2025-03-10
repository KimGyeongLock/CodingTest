#include <iostream>

using namespace std;

int D[201][201];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M, K;
    cin >> N >> M >> K;

    for(int i = 0; i <= 200; i++) {
        D[i][1] = i;
        D[i][0] = 1;
        D[i][i] = 1;
    }

    for(int i = 2; i <= 200; i++) {
        for(int j = 1; j < i; j++) {
            D[i][j] = D[i - 1][j] + D[i - 1][j - 1];
            if (D[i][j] > 1000000000) {
                D[i][j] = 1000000001;
            }
        }
    }

    string ans;
    if(D[N+M][M] < K) {
        cout << -1;
    } else {
        while(!(N == 0 && M == 0)) {
            if(D[N - 1 + M][M] >= K) {
                ans.push_back('a');
                N--;
            } else {
                ans.push_back('z');
                K = K - D[N - 1 + M][M];
                M--;
            }
        }
    }

    cout << ans;
}