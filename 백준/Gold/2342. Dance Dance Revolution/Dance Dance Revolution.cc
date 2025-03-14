#include <iostream>
#include <climits>

using namespace std;

long DP[100001][5][5];
int mp[5][5] = { {0, 2, 2, 2, 2},
                 {2, 1, 3, 4, 3},
                 {2, 3, 1, 3, 4},
                 {2, 4, 3, 1, 3},
                 {2, 3, 4, 3, 1}
                };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for(int i = 0; i < 100001; i++) {
        for(int j = 0; j < 5; j++) {
            for(int k = 0; k < 5; k++) {
                DP[i][j][k] = 100001 * 4;
            }
        }
    }

    DP[0][0][0] = 0;
    int s = 1;
    while(true) {
        int n;
        cin >> n;
        if (n == 0) {
            break;
        }
        for(int i = 0; i < 5; i++) {
            if (n == i) { //두 발이 같은 자리에 있을 수 없음
                continue;
            }
            for(int j = 0; j < 5; j++) {
                DP[s][i][n] = min(DP[s][i][n], DP[s - 1][i][j] + mp[j][n]);
            }
        }
        for(int i = 0; i < 5; i++) {
            if (n == i) { //두 발이 같은 자리에 있을 수 없음
                continue;
            }
            for(int j = 0; j < 5; j++) {
                DP[s][n][i] = min(DP[s][n][i], DP[s - 1][j][i] + mp[j][n]);
            }
        }
        s++;
    }
    s--;

    long min_v = INT_MAX;
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            min_v = min(min_v, DP[s][i][j]);
        }
    }
    cout << min_v;
}