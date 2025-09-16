#include <bits/stdc++.h>
using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    int di = n - 1, pi = n - 1;

    auto pull_tail = [](vector<int>& v, int idx) {
        while (idx >= 0 && v[idx] == 0) --idx;
        return idx;
    };

    while (true) {
        di = pull_tail(deliveries, di);
        pi = pull_tail(pickups,    pi);
        if (di < 0 && pi < 0) break;                 // 모두 끝

        int far = max(di, pi) + 1;                   // 1-based 거리
        answer += 2LL * far;                         // 왕복

        // 배달: 뒤에서부터 cap 만큼 줄이기
        int load = cap;
        while (di >= 0 && load > 0) {
            if (deliveries[di] == 0) { --di; continue; }
            int use = min(load, deliveries[di]);
            deliveries[di] -= use;
            load -= use;
            if (deliveries[di] == 0) --di;
        }

        // 수거: 뒤에서부터 cap 만큼 줄이기
        load = cap;
        while (pi >= 0 && load > 0) {
            if (pickups[pi] == 0) { --pi; continue; }
            int use = min(load, pickups[pi]);
            pickups[pi] -= use;
            load -= use;
            if (pickups[pi] == 0) --pi;
        }
    }
    return answer;
}
