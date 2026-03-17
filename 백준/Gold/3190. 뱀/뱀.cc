#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <deque>

using namespace std;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int solution(int n,
             const vector<pair<int, int>>& apples,
             const vector<pair<int, char>>& commands) {

    vector<vector<bool>> apple_position(n, vector<bool>(n, false));
    for (auto a : apples) {
        apple_position[a.first - 1][a.second - 1] = true;
    }

    unordered_map<int, char> com;
    for (auto c : commands) {
        com[c.first] = c.second;
    }


    int time = 0;
    int x = 0, y = 0;
    int dir = 0;
    vector<vector<bool>> snake_position(n, vector<bool>(n, false));
    deque<pair<int, int>> snake;
    
    snake_position[x][y] = true;
    snake.push_back({0, 0});

    while (true) {
        time++;

        int nx = snake.back().first + dx[dir];
        int ny = snake.back().second + dy[dir];

        if (nx < 0 || nx >= n || ny < 0 || ny >= n) break;

        if (snake_position[nx][ny]) break;

        snake.push_back({nx, ny});
        snake_position[nx][ny] = true;

        if (apple_position[nx][ny]) {
            apple_position[nx][ny] = false;
        } else {
            auto tail = snake.front();
            snake.pop_front();
            snake_position[tail.first][tail.second] = false;
        }

        if (com.count(time)) {
            if (com[time] == 'L') dir = (dir + 3) % 4;
            if (com[time] == 'D') dir = (dir + 1) % 4;
        }
       
    }
    return time;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int k;
    cin >> k;

    vector<pair<int, int>> apples(k);
    for (int i = 0; i < k; i++) {
        int r, c;
        cin >> r >> c;
        apples[i] = {r, c};
    }

    int l;
    cin >> l;

    vector<pair<int, char>> commands(l);
    for (int i = 0; i < l; i++) {
        int x;
        char ch;
        cin >> x >> ch;
        commands[i] = {x, ch};
    }

    cout << solution(n, apples, commands) << '\n';
    return 0;
}