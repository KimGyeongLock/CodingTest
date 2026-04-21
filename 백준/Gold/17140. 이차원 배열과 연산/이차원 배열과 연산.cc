#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> board(101, vector<int>(101, 0));

int h = 3, w = 3;

vector<vector<int>> rsort() {
    int max_w = 0;
    vector<vector<int>> new_board(101, vector<int>(101, 0));
    for (int i = 0; i < h; i++) {
        int cnt[101] = {};
        for (int j = 0; j < w; j++) {
            if (board[i][j] == 0) continue;
            cnt[board[i][j]]++;
        }
        vector<pair<int, int>> v;

        for (int j = 0; j <= 100; j++) {
            if (cnt[j] > 0) v.push_back({j, cnt[j]});
        }

        sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) {
            if (a.second == b.second) return a.first < b.first;
            return a.second < b.second;
        });

        vector<int> result;
        for (auto com : v) {
            result.push_back(com.first);
            result.push_back(com.second);
        }

        for (int j = 0; j < result.size(); j++) {
            new_board[i][j] = result[j];   
        }
        max_w = max(max_w, (int)result.size());
    }
    w = max_w;

    return new_board;
}

vector<vector<int>> csort() {
    int max_h = 0;
    vector<vector<int>> new_board(101, vector<int>(101, 0));
    for (int i = 0; i < w; i++) {
        int cnt[101] = {};
        for (int j = 0; j < h; j++) {
            if (board[j][i] == 0) continue;
            cnt[board[j][i]]++;
        }
        vector<pair<int, int>> v;

        for (int j = 0; j <= 100; j++) {
            if (cnt[j] > 0) v.push_back({j, cnt[j]});
        }

        sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) {
            if (a.second == b.second) return a.first < b.first;
            return a.second < b.second;
        });

        vector<int> result;
        for (auto com : v) {
            result.push_back(com.first);
            result.push_back(com.second);
        }

        for (int j = 0; j < result.size(); j++) {
            new_board[j][i] = result[j];   
        }
        max_h = max(max_h, (int)result.size());
    }
    h = max_h;

    return new_board;
}

int main()
{
    int r, c, k;
    cin >> r >> c >> k;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> board[i][j];
        }
    }

    for (int time = 0; time <= 100; time++) {
        if (board[r-1][c-1] == k) {
            cout << time;
            return 0;
        }

        if (h >= w) {
            board = rsort();
        } else {
            board = csort();            
        }  
    }

    cout << -1;
    return 0;
}