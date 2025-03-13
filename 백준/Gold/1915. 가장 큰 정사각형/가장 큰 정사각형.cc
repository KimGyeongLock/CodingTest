#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<vector<int> > A;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin >> n >> m;

    A.resize(n, vector<int>(m));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            char a = cin.get();
            if (a == '\n') {
                a = cin.get();
            }
            A[i][j] = a - '0';
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if (A[i][j] == 1 && i > 0 && j > 0) {
                A[i][j] = min(A[i][j - 1], min(A[i - 1][j], A[i - 1][j - 1])) + 1;
            } 

        }
    }

    int max_v = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            max_v = max(max_v, A[i][j]);
        }
    }
    cout << pow(max_v, 2);
}