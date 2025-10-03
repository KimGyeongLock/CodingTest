#include <string>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

vector<vector<pair<int, int>>> edge;
int N;
vector<int> dijkstra(int start) {
    vector<int> dist(N + 1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, start});
    dist[start] = 0;
    
    while(!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        
        int cost = cur.first;
        int node = cur.second;
        
        if (cost > dist[node]) continue;
        
        for (auto nxt : edge[node]) {
            int nxt_node = nxt.first;
            int nxt_cost = nxt.second;
            
            if (dist[nxt_node] > nxt_cost + cost) {
                dist[nxt_node] = nxt_cost + cost;
                pq.push({dist[nxt_node], nxt_node});
            }
        }
    }
    
    return dist;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    N = n;
    edge.resize(n + 1);
    for (auto& f : fares) {
        edge[f[0]].push_back({f[1], f[2]});
        edge[f[1]].push_back({f[0], f[2]});
    }
    
    vector<int> dist1 = dijkstra(s);
    vector<int> dist2 = dijkstra(a);
    vector<int> dist3 = dijkstra(b);
    
    int min_v = INT_MAX;
    for (int k = 1; k <= n; k++) {
        int t = dist1[k] + dist2[k] + dist3[k];
        if (t < min_v) min_v = t;
    }
    return min_v;
}