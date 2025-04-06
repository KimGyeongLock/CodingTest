#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

vector<vector<pair<int, int> > > A; 
vector<int> dist;

void bfs(int start) {
    dist[start] = 1;
    queue<int> q;
    q.push(start);

    while(!q.empty()) {
        int cn = q.front();
        q.pop();

        for(auto next : A[cn]) {
            int next_size = dist[cn] + 1;
            if (next_size <= next.second && dist[next.first] > next_size) { //현재 들어가있는 것보다 새로 구한 값이 더 작을 때
                dist[next.first] = next_size; //더 작은걸로 대체
                q.push(next.first);
            }
        }
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M, S, E;
    cin >> N >> M >> S >> E;

    A.resize(N + 1);
    dist.resize(N + 1, INT_MAX);
    for(int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        A[u].push_back(make_pair(v, w));
        A[v].push_back(make_pair(u, w));
    }

    bfs(S);

    if (dist[E] == INT_MAX) cout << -1;
    else cout << dist[E];
}
