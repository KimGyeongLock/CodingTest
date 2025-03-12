#include <iostream>

using namespace std;

long D[101][11];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    D[1][0] = 0;
    for(int i = 1; i <= 9; i++) {
        D[1][i] = 1;
    }
    
    for(int i = 2; i <= N; i++) {
        D[i][0] = D[i - 1][1];
        D[i][9] = D[i - 1][8];

        for(int j = 1; j <= 8; j++) {
            D[i][j] = (D[i - 1][j - 1] + D[i - 1][j + 1]) % 1000000000;
        }
    }

    long sum = 0;
    for(int i = 0; i <= 9; i++) {
        sum = (sum + D[N][i]) % 1000000000;
    }
    cout << sum;
}