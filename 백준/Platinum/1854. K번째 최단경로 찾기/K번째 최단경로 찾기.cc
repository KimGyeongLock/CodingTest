#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<pair<int, int> > > A;
vector<priority_queue<int> > distQueue;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;

    A.resize(n+1);
    distQueue.resize(n+1);
    distQueue[1].push(0);

    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        A[u].push_back(make_pair(v, w));
    }

    priority_queue<pair<int, int>, vector<pair<int,int> >, greater<pair<int, int> > > pq;
    pq.push(make_pair(0, 1));
    while(!pq.empty()) {
        pair<int, int> cur = pq.top();
        pq.pop();

        for(pair<int, int> i : A[cur.second]) {
            if(distQueue[i.first].size() < k) { // 저장된 경로가 k개가 안될 경우 그냥 추가
                distQueue[i.first].push(cur.first + i.second);
                pq.push(make_pair(cur.first + i.second, i.first));
            } else if (distQueue[i.first].top() > cur.first + i.second) {
                distQueue[i.first].pop();
                distQueue[i.first].push(cur.first + i.second);
                pq.push(make_pair(cur.first + i.second, i.first));
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        if (distQueue[i].size() == k) {
            cout << distQueue[i].top() << "\n";
        } else {
            cout << -1 << "\n";
        }
    }
}