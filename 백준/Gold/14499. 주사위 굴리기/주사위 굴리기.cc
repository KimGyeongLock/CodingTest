#include <iostream>
#include <vector>

using namespace std;

void solution(int n, int m, int x, int y, int k, vector<vector<int>> map, vector<int> command) {
    int up = 0, down = 0, left = 0, right = 0, front = 0, back = 0;

    for (int i = 0; i < k; i++) {
        int nx = x;
        int ny = y;

        if (command[i] == 1) {
            ny += 1;
        } else if (command[i] == 2) {
            ny -= 1;
        } else if (command[i] == 3) {
            nx -= 1;
        } else if (command[i] == 4) {
            nx += 1;
        }

        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        x = nx; y = ny;

        if (command[i] == 1) {
            int tmp = right;
            right = up;
            up = left;
            left = down;
            down = tmp;
        } else if (command[i] == 2) {
            int tmp = left;
            left = up;
            up = right;
            right = down;
            down = tmp;
        } else if (command[i] == 3) {
            int tmp = back;
            back = up;
            up = front;
            front = down;
            down = tmp;
        } else if (command[i] == 4) {
            int tmp = front;
            front = up;
            up = back;
            back = down;
            down = tmp;
        }
        if (map[nx][ny] == 0) {
            map[nx][ny] = down;
        } else {
            down = map[nx][ny];
            map[nx][ny] = 0;
        }
        cout << up << "\n";
    }
}

int main()
{
    int N, M, x, y, K;
    cin >> N >> M >> x >> y >> K;

    vector<vector<int>> map(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }
    
    vector<int> command(K);
    for (int i = 0; i < K; i++) {
        cin >> command[i];
    }
    
    solution(N, M, x, y, K, map, command);
}