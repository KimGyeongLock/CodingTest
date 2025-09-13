#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<vector<int>> edges) {
    int MAX_ID = 0;
    for (auto &e : edges) MAX_ID = max(MAX_ID, max(e[0], e[1]));

    vector<int> indeg(MAX_ID + 1, 0), outdeg(MAX_ID + 1, 0);
    vector<char> used(MAX_ID + 1, 0);

    for (auto &e : edges) {
        int u = e[0], v = e[1];
        outdeg[u]++;
        indeg[v]++;
        used[u] = used[v] = 1;   // 그래프에 실제로 등장한 라벨만 집계
    }

    // 생성 정점 idx: indeg==0 && outdeg>=2 (등장한 노드만 대상으로)
    int idx = -1;
    for (int i = 0; i <= MAX_ID; ++i) {
        if (!used[i]) continue;
        if (indeg[i] == 0 && outdeg[i] >= 2) { idx = i; break; }
    }

    int b = 0, c = 0;
    for (int i = 0; i <= MAX_ID; ++i) {
        if (!used[i] || i == idx) continue;
        if (outdeg[i] == 0) b++;                         // 막대의 끝
        if (indeg[i] >= 2 && outdeg[i] >= 2) c++;        // 8자 교차점
    }

    int a = outdeg[idx] - b - c;                         // 도넛 개수
    return {idx, a, b, c};
}
