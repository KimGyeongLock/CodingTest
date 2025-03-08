#include <iostream>

using namespace std;

int D[11][11]; //D[N + 1][N + 1]

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    cin >> N >> K;

    for (int i = 0; i <= N; i++) {
        D[i][1] = i; // i개 중 1개를 뽑는 경우의 수 = i개
        D[i][0] = 1; // i개 중 0개를 뽑는 경우의 수 = 1개
        D[i][i] = 1; // i개 중 i를 뽑는 경우의 수 = 1개
    }

    for(int i = 2; i <= N; i++) {
        for(int j = 1; j <= i; j++) {
            D[i][j] = D[i - 1][j] + D[i - 1][j - 1];
        }
    }

    cout << D[N][K];
}