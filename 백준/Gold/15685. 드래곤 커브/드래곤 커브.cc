#include <iostream>
#include <vector>

using namespace std;

bool board[101][101];

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};

void drawDragonCurve(int x, int y, int d, int g) {
    vector<int> dir;
    dir.push_back(d);

    for (int gen = 1; gen <= g; gen++) {
        for (int i = dir.size() - 1; i >= 0; i--) {
            dir.push_back((dir[i] + 1) % 4);
        }
    }

    board[x][y] = true;
    for (int d : dir) {
        x += dx[d];
        y += dy[d];
        board[x][y] = true;
    }
}

int countSquare() {
    int cnt = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (board[i][j] && board[i+1][j] && board[i][j+1] && board[i+1][j+1]) cnt++;
        }
    }
    return cnt;
}

int main()
{
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int x, y, d, g;
        cin >> x >> y >> d >> g;
        drawDragonCurve(x, y, d, g);
    }

    cout << countSquare();
}