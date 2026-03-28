#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool canPass(const vector<int>& line, int n, int l) {
    vector<bool> used(n, false);

    for (int i = 0; i < n - 1; i++) {
        if (line[i] == line[i + 1]) continue;

        if (abs(line[i] - line[i + 1]) > 1) return false;

        if (line[i] + 1 == line[i + 1]) {
            for (int j = 0; j < l; j++) {
                int idx = i - j;
                if (idx < 0) return false;
                if (used[idx]) return false;
                if (line[idx] != line[i]) return false;
                used[idx] = true;
            }
        }
        else if (line[i] - 1 == line[i + 1]) {
            for (int j = 1; j <= l; j++) {
                int idx = i + j;
                if (idx >= n) return false;
                if (used[idx]) return false;
                if (line[idx] != line[i + 1]) return false;
                used[idx] = true;
            }
        }
    }
    return true;
}

int solution(int n, int l, vector<vector<int>> arr) {
    int cnt = 0;
    
    for (int i = 0; i < n; i++) {
        vector<int> line;
        for (int j = 0; j < n; j++) {
            line.push_back(arr[i][j]);
        }
        if (canPass(line, n, l)) cnt++;
    }

    for (int i = 0; i < n; i++) {
        vector<int> line;
        for (int j = 0; j < n; j++) {
            line.push_back(arr[j][i]);
        }
        if (canPass(line, n, l)) cnt++;
    }
    return cnt;
}

int main()
{
    int N, L;
    cin >> N >> L;

    vector<vector<int>> arr(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    cout << solution(N, L, arr);
}