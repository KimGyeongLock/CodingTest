#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<int>> A(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }

    vector<vector<int>> food(N, vector<int>(N, 5));

    vector<vector<vector<int>>> tree(N, vector<vector<int>>(N));
    for (int i = 0; i < M; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        x--; y--;
        tree[x][y].push_back(z);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            sort(tree[i][j].begin(), tree[i][j].end());
        }
    }

    while(K--) {

        //봄+여름
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (tree[i][j].empty()) continue;

                vector<int> alive;
                int deadFood = 0;

                for (int& age : tree[i][j]) {
                    if (food[i][j] >= age) {
                        food[i][j] -= age;
                        alive.push_back(age + 1);
                    } else {
                        deadFood += age / 2;
                    }
                }

                tree[i][j] = alive;
                food[i][j] += deadFood;
            }
        }

        //가을
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                for (int age : tree[i][j]) {
                    if (age % 5 == 0) {
                        for (int dir = 0; dir < 8; dir++) {
                            int nx = i + dx[dir];
                            int ny = j + dy[dir];
                            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                            tree[nx][ny].push_back(1);
                        }
                    }
                }
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                sort(tree[i][j].begin(), tree[i][j].end());
            }
        }

        //겨울
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                food[i][j] += A[i][j];
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!tree[i][j].empty()) cnt += tree[i][j].size();
        }
    }
    cout << cnt;
}