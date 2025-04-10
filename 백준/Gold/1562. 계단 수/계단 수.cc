#include <iostream>

using namespace std;

const int MOD = 1000000000;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    int A[101][10][1024] = {0};

    for(int i = 1; i <= 9; i++) {
        A[1][i][1 << i] = 1;
    }

    for(int i = 1; i < N; i++) {
        for(int j = 0; j <= 9; j++) {
            for(int k = 0; k < 1024; k++) {
                if(A[i][j][k] == 0) continue;

                if (j > 0) {
                    int next_j = j - 1;
                    int next_k = k | (1 << next_j);
                    A[i + 1][next_j][next_k] += A[i][j][k];
                    A[i + 1][next_j][next_k] %= MOD;
                }
                if (j < 9) {
                    int next_j = j + 1;
                    int next_k = k | (1 << next_j);
                    A[i + 1][next_j][next_k] += A[i][j][k];
                    A[i + 1][next_j][next_k] %= MOD;
                }
            }
        }
    }

    int ans = 0;
    for(int i = 0; i <= 9; i++) {
        ans += A[N][i][1023];
        ans %= MOD;
    }

    cout << ans;
}