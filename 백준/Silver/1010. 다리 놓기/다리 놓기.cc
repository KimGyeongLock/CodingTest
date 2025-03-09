#include <iostream>

using namespace std;

int D[30][30];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for(int i = 0; i < 30; i++) {
        D[i][1] = i;
        D[i][0] = 1;
        D[i][i] = 1;
    }

    for(int i = 2; i < 30; i++) {
        for(int j = 1; j <= i; j++) {
            D[i][j] = D[i-1][j] + D[i-1][j-1];
        }
    }

    int T;
    cin >> T;

    for(int i = 0; i < T; i++) {
        int a, b;
        cin >> a >> b;
        cout << D[b][a] << "\n";
    }
}