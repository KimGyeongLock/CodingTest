#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<pair<double, int>> res;
    vector<int> st(N+2, 0);
    for (int s : stages) {
        st[s]++;
    }
    int n = stages.size();
    for (int i = 1; i <= N; i++) {
        res.push_back({(double)st[i] / n, i});
        n -= st[i];
    }
    const double EPS = 1e-12;
    sort(res.begin(), res.end(), [&](const pair<double,int>& a, const pair<double,int>& b) {
        if (fabs(a.first - b.first) > EPS) return a.first > b.first; // 실패율 내림차순
        return a.second < b.second;                                   // 동일하면 번호 오름차순
    });
    vector<int> answer;
    for (int i = 0; i < N; i++) {
        answer.push_back(res[i].second);
    }
    return answer;
}