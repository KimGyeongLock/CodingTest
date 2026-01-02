#include <bits/stdc++.h>
using namespace std;

static const int DIS[4] = {10, 20, 30, 40};

pair<int, int> bestAns = {0, 0}; // {plusCount, revenue}
vector<int> chosen;             // chosen discount index per emoticon
vector<vector<int>> U;
vector<int> E;

void evaluate() {
    int plusCnt = 0;
    int revenue = 0;

    for (auto &u : U) {
        int minDisc = u[0];
        int limit = u[1];

        int sum = 0;
        for (int i = 0; i < (int)E.size(); i++) {
            int d = DIS[chosen[i]];
            if (d >= minDisc) {
                // discounted price
                sum += E[i] * (100 - d) / 100;
            }
        }

        if (sum >= limit) {
            plusCnt++;
        } else {
            revenue += sum;
        }
    }

    if (plusCnt > bestAns.first) bestAns = {plusCnt, revenue};
    else if (plusCnt == bestAns.first && revenue > bestAns.second) bestAns = {plusCnt, revenue};
}

void dfs(int idx) {
    if (idx == (int)E.size()) {
        evaluate();
        return;
    }
    for (int k = 0; k < 4; k++) {
        chosen[idx] = k;
        dfs(idx + 1);
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    U = std::move(users);
    E = std::move(emoticons);

    chosen.assign(E.size(), 0);
    bestAns = {0, 0};

    dfs(0);

    return {bestAns.first, bestAns.second};
}
