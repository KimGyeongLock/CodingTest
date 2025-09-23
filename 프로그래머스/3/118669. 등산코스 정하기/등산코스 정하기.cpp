#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {    
    vector<vector<pair<int, int>>> edge(n + 1);
    for (auto& p : paths) {
        edge[p[0]].push_back({p[1], p[2]});
        edge[p[1]].push_back({p[0], p[2]});
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    vector<int> dist(n + 1, INT_MAX);
    vector<char> isGate(n + 1, 0), isSummit(n + 1, 0);
    for (int g : gates) isGate[g] = 1;
    for (int s : summits) isSummit[s] = 1;
    for (int g : gates) {
        dist[g] = 0;
        pq.push({0, g});
    }
    
    while(!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d != dist[u]) continue;
        if (isSummit[u]) continue;
        for (auto [v, w] : edge[u]) {
            if (isGate[v]) continue;
            int nd = max(d, w);
            if (nd < dist[v]) {
                dist[v] = nd;
                pq.push({nd, v});
            }
        }
    }
    
    sort(summits.begin(), summits.end());
    int best1, best2 = INT_MAX;
    for (int s : summits) {
        if (dist[s] < best2) {
            best2 = dist[s];
            best1 = s;
        }
    }
    
    return {best1, best2};
}