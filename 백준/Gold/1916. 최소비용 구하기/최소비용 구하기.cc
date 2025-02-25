#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

vector<vector<pair<int ,int> > > A;
vector<bool> visited;
vector<int> V;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    A.resize(n+1);
    V.resize(n+1, INT_MAX);
    visited.resize(n+1, false);

    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        A[a].push_back(make_pair(b, c));
    }

    int start, end;
    cin >> start >> end;

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;

    V[start] = 0;
    q.push(make_pair(0, start));

    while(!q.empty()) {
        pair<int, int> n = q.top();
        q.pop();

        if (visited[n.second]) {
            continue;
        }

        visited[n.second] = true;

        for(pair<int, int> i : A[n.second]) {
            if (V[i.first] > V[n.second] + i.second) {
                V[i.first] = V[n.second] + i.second;
                q.push(make_pair(V[i.first], i.first));
            }
        }
    }

    cout << V[end];
}