#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

vector<vector<pair<int, int>>> edgeList;


int dijkstra(int start, int N, int k) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    vector<int> dist(N + 1, INT_MAX);
    
    pq.push({0, start});
    dist[start] = 0;
    
    int cnt = 0;
    while(!pq.empty()) {
        auto [curCost, cur] = pq.top();
        pq.pop();
        
        // cnt++;
        if (dist[cur] < curCost) continue;
        if (curCost > k) continue;
        
        for (auto [nxt, nxtCost] : edgeList[cur]) {
            int totalCost = curCost + nxtCost;
            if (dist[nxt] < totalCost) continue;
            if (totalCost > k) continue;
            
            dist[nxt] = totalCost;
            pq.push({totalCost, nxt});
        }
    }
    
    for (int i = 1; i <= N; i++) {
        if (dist[i] <= k) cnt++;
    }
    
    return cnt;
}

int solution(int N, vector<vector<int> > road, int K) {
    edgeList.resize(N + 1);
    for (auto r : road) {
       edgeList[r[0]].push_back({r[1], r[2]});
       edgeList[r[1]].push_back({r[0], r[2]});
    }

    return dijkstra(1, N, K);
}