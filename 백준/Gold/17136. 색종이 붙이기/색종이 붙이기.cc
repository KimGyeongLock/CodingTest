#include <iostream>
#include <climits>

using namespace std;

int A[10][10];
int paper[6] = {0, 5, 5, 5, 5, 5};
int ans = INT_MAX;

bool canPlace(int r, int c, int size) {
    if (r + size > 10 || c + size > 10) return false;
    for (int i = r; i < r + size; i++) {
        for(int j = c; j < c + size; j++) {
            if (A[i][j] == 0) return false;
        }
    }
    return true;
}

void setBoard(int r, int c, int size, int value) {
    for(int i = r; i < r + size; i++) {
        for(int j = c; j < c + size; j++) {
            A[i][j] = value;
        }
    }
}

void dfs(int r, int c, int cnt) {
    if (cnt >= ans) return;

    if (r >= 10) {
        ans = min(ans, cnt);
        return;
    }

    int nr = r, nc = c + 1;
    if (nc >= 10) {
        nr = r + 1;
        nc = 0;
    }
    if(A[r][c] == 0) {
        dfs(nr, nc, cnt);
        return;
    }

    for(int size = 1; size <= 5; size++) {
        if (paper[size] > 0 && canPlace(r, c, size)) {
            paper[size]--;
            setBoard(r, c, size, 0);

            dfs(nr, nc, cnt + 1);

            paper[size]++;
            setBoard(r, c, size, 1);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            cin >> A[i][j];
        }
    }

    dfs(0, 0, 0);

    if (ans == INT_MAX) cout << -1;
    else cout << ans;
}