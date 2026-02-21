#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {    
    vector<vector<pair<int, int>>> edgeList(n+1);
    for (auto p : paths) {
        edgeList[p[0]].push_back({p[1], p[2]});
        edgeList[p[1]].push_back({p[0], p[2]});
    }
    
    vector<bool> isSummit(n+1, false);
    for (int s : summits) isSummit[s] = true;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    vector<int> intensity(n+1, INT_MAX);
    
    for (int gate : gates) {
        intensity[gate] = 0;
        pq.push({0, gate});
    }
    
    while(!pq.empty()) {
        auto [curIntensity, cur] = pq.top(); pq.pop();
        
        if (curIntensity > intensity[cur]) continue;
        if (isSummit[cur]) continue;
        
        for (auto [next, w] : edgeList[cur]) {
            int maxIntensity = max(w, curIntensity);
            if (intensity[next] > maxIntensity) {
                intensity[next] = maxIntensity;
                pq.push({intensity[next], next});
            }
        }
    }
    
    sort(summits.begin(), summits.end());
    
    int bestIntensity = INT_MAX;
    int bestNode = 0;
    for (int s : summits) {
        if (intensity[s] < bestIntensity) {
            bestIntensity = intensity[s];
            bestNode = s;
        }
    }
    
    return {bestNode, bestIntensity};
}