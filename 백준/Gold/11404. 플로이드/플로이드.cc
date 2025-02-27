#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<vector<int> > A;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    A.resize(n+1, vector<int>(n+1, INT_MAX));
    for(int i = 1; i <= n; i++) {
        A[i][i] = 0;
    }
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        if(A[u][v] > w) {
            A[u][v] = w;
        }
    }

    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if (A[i][k] != INT_MAX && A[k][j] != INT_MAX) {
                    A[i][j] = min(A[i][j], A[i][k] + A[k][j]);
                }
                
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if (A[i][j] == INT_MAX) {
                cout << 0 << " ";
            } else {
                cout << A[i][j] << " ";
            }
        }
        cout << "\n";
    }
}