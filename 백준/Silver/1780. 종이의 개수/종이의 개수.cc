#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> v;
int cnt[3];

void dfs(int x, int y, int n) {
    int first = v[x][y];
    bool same = true;
    for (int i = x; i < x+n; i++) {
        for (int j = y; j < y+n; j++) {
            if (v[i][j] != first) { same = false; break; }
        }
    }

    if (same) { cnt[first+1]++; return; }

    int m = n / 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            dfs(x + i * m, y + j * m, m);
        }
    }
}
 

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(0);

    int n;
    cin >> n;

    v.resize(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }

    dfs(0, 0, n);
    cout << cnt[0] << "\n" << cnt[1] << "\n" << cnt[2] << "\n";
}