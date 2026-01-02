#include <string>
#include <vector>
#include <iostream>

using namespace std;

const int rate[4] = {10, 20, 30, 40};

vector<vector<int>> usersG;
vector<int> emotG;
vector<int> chosen;
int n, m;

int bestA = 0, bestB = 0;
void evaluate() {
    int a = 0, b = 0;
    
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < m; j++) {
            if (usersG[i][0] <= chosen[j]) { // 이모티콘 구매
                sum += emotG[j] * (100 - chosen[j]) / 100;
            }
        }
        if (sum >= usersG[i][1]) { // 이모티콘 구매 취소 & 플러스 가입
            a++;
        } else { // 이모티콘 구매
            b += sum;
        }
    }
    
    if (a > bestA) {
        bestA = a;
        bestB = b;
    } else if (a == bestA) {
        if (b > bestB) {
            bestA = a;
            bestB = b;
        }
    }
}

void dfs(int idx) {
    if (idx == m) {
        evaluate();
        return;
    }
    
    for (int i = 0; i < 4; i++) {
        chosen[idx] = rate[i];
        dfs(idx + 1);
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    n = users.size();
    m = emoticons.size();
    
    usersG = move(users);
    emotG = move(emoticons);
    chosen.resize(m);

    dfs(0);
    return {bestA, bestB};
}