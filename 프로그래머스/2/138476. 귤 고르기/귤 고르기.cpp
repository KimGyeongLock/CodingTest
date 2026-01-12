#include <bits/stdc++.h>
using namespace std;

int solution(int k, vector<int> tangerine) {
    unordered_map<int, int> cnt;
    cnt.reserve(tangerine.size() * 2);

    // 1) 빈도 세기
    for (int x : tangerine) cnt[x]++;

    // 2) 빈도만 뽑아서 정렬
    vector<int> freqs;
    freqs.reserve(cnt.size());
    for (auto &p : cnt) freqs.push_back(p.second);

    sort(freqs.begin(), freqs.end(), greater<int>());

    // 3) 큰 것부터 더해서 k개 채우기
    int sum = 0, kinds = 0;
    for (int f : freqs) {
        sum += f;
        kinds++;
        if (sum >= k) break;
    }
    return kinds;
}
