#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> v;
string answer;

void dfs(int x, int y, int n) {
    int first = v[x][y];
    bool same = true;
    for (int i = x; i < x+n; i++) {
        for (int j = y; j < y+n; j++) {
            if (v[i][j] != first) { same = false; break; }
        }
    }

    if (same) {
        answer.push_back(first + '0');
        return;
    }

    int m = n / 2;
    answer.push_back('(');
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            dfs(x + i * m, y + j * m, m);
        }
    }
    answer.push_back(')');
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    v.resize(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < n; j++) {
            v[i][j] = str[j] - '0';
        }
    }

    dfs(0, 0, n);
    cout << answer;
    return 0;
}