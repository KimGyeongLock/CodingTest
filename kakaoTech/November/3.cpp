#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<vector<int> > A;
vector<vector<int> > P;
long N, S;

bool involve(int K) {
    return P[N][N] - P[K][N] - P[N][K] + P[K][K] >= S;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    
    cin >> N >> S;

    A.resize(N, vector<int>(N));
    P.resize(N + 1, vector<int>(N + 1, 0));

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            P[i][j] = P[i - 1][j] + P[i][j - 1] + A[i - 1][j - 1] - P[i - 1][j - 1];
        }
    }

    // for(int i = 0; i <= N; i++) {
    //     for(int j = 0; j <= N; j++) {
    //         cout << P[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    long start = 1;
    long end = N;
    long result = -1;
    while(start < end) {
        long mid = (start + end) / 2;
        if (involve(mid)) {
            end = mid - 1;
            result = mid;
        } else {
            start = mid + 1;
        }
    }

    cout << result;
}
