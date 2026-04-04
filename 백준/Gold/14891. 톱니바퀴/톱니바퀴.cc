#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void clockWise(vector<int>& wheel) {
    int temp = wheel[7];
    for (int i = 7; i >= 1; i--) {
        wheel[i] = wheel[i-1];
    }
    wheel[0] = temp;
}

void antiClockWise(vector<int>& wheel) {
    int temp = wheel[0];
    for (int i = 0; i < 7; i++) {
        wheel[i] = wheel[i + 1];
    }
    wheel[7] = temp;
}

int solution(vector<vector<int>>& wheel, vector<pair<int, int>>& commands) {
    for (auto c : commands) {
        int num = c.first - 1;
        int dir = c.second;

        vector<int> rotateDir(4, 0);
        rotateDir[num] = dir;

        // 왼쪽 전파
        for (int i = num; i > 0; i--) {
            if (wheel[i][6] != wheel[i - 1][2]) {
                rotateDir[i - 1] = -rotateDir[i];
            } else {
                break;
            }
        }

        // 오른쪽 전파
        for (int i = num; i < 3; i++) {
            if (wheel[i][2] != wheel[i + 1][6]) {
                rotateDir[i + 1] = -rotateDir[i];
            } else {
                break;
            }
        }

        // 한꺼번에 회전
        for (int i = 0; i < 4; i++) {
            if (rotateDir[i] == 1) clockWise(wheel[i]);
            else if (rotateDir[i] == -1) antiClockWise(wheel[i]);
        }
    }

    int answer = 0;
    for (int i = 0; i < 4; i++) {
        if (wheel[i][0] == 1) answer += pow(2, i);
    }
    return answer;
}

int main()
{
    vector<vector<int>> wheel(4, vector<int>(8));
    for (int i = 0; i < 4; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < 8; j++) {
            wheel[i][j] = s[j] - '0';
        }
    }
    int n;
    cin >> n;
    vector<pair<int, int>> commands(n);
    for (int i = 0; i < n; i++) {
        cin >> commands[i].first >> commands[i].second;
    }

    cout << solution(wheel, commands);
}