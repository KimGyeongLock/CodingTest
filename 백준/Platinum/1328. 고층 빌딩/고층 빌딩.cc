#include <iostream>

using namespace std;

long D[101][101][101];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, L, R;
    cin >> N >> L >> R;

    D[1][1][1] = 1;
    for(int i = 2; i <= N; i++) {
        for(int j = 1; j <= L; j++) {
            for(int k = 1; k <= R; k++) {
                D[i][j][k] = (D[i - 1][j - 1][k] + D[i - 1][j][k - 1] + D[i - 1][j][k] * (i - 2)) % 1000000007;
            }
        }
    }

    cout << D[N][L][R];
}