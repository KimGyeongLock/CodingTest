#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int e, vector<int> starts) {
    vector<int> d(e + 1, 0);

    // 1) 약수 개수 계산 (sieve 방식)
    for (int i = 1; i <= e; i++) {
        for (int j = i; j <= e; j += i) {
            d[j]++;
        }
    }

    // 2) best[i] = [i..e] 구간에서 약수 개수 최대인 수 (동률이면 더 작은 수)
    vector<int> best(e + 2, 0);
    best[e] = e;
    int curBest = e;

    for (int i = e - 1; i >= 1; i--) {
        // d[i]가 더 크거나 같으면 i로 갱신 (같으면 i가 더 작아서 i가 우선)
        if (d[i] >= d[curBest]) curBest = i;
        best[i] = curBest;
    }

    // 3) 쿼리 처리
    vector<int> answer;
    answer.reserve(starts.size());
    for (int s : starts) {
        answer.push_back(best[s]);
    }
    return answer;
}
