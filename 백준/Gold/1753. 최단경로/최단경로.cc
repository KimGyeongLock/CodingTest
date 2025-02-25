#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int V, E, K;
    cin >> V >> E;
    cin >> K;

    //인접 리스트 노드 저장
    vector<vector<pair<int, int> > > mlist(V+1);
    for(int i = 0;i < E;i++) {
        int u, v, w;
        cin >> u >> v >> w;

        mlist[u].push_back(make_pair(v, w));
    }

    //최단 거리 배열 초기화
    vector<int> mdistance(V+1, INT_MAX);
    mdistance[K] = 0;

    //노드 사용 여부 저장
    vector<bool> visited(V+1, false);
    //다익스트라 알고리즘 수행을 위한 우선순위 큐
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;

    q.push(make_pair(0, K));

    while(!q.empty()) {
        int node = q.top().second;
        q.pop();

        if(visited[node]) continue;
        visited[node] = true;

        for(size_t i = 0;i < mlist[node].size(); i++) {
            pair<int, int> p = mlist[node][i];

            if (!visited[p.first] && mdistance[node] + p.second < mdistance[p.first]) {
                mdistance[p.first] = mdistance[node] + p.second;
                q.push(make_pair(mdistance[p.first], p.first));
            }
        }
    }

    for(int i = 1;i <= V;i++) {
        if(mdistance[i] == INT_MAX) cout << "INF" << "\n";
        else cout << mdistance[i] << "\n";
    }
}