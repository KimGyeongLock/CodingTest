#include <iostream>

using namespace std;

int D[15][15];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    for(int i = 0; i < T; i++) {
        int k, n;
        cin >> k >> n;

        for(int j = 0; j < 15; j++) {
            D[j][1] = 1; //0층 1호 == 1명 (아래 공식) => D[1][1] = D[1][0] + D[]
            D[0][j] = j;
        }

        for(int j = 1; j <= k; j++) {
            for(int l = 2; l <= n; l++) {
                D[j][l] = D[j][l - 1] + D[j - 1][l];
            }
        }

        cout << D[k][n] << "\n";
    }
}