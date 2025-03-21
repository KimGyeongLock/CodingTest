#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > A;
vector<bool> visited;
vector<int> subtree;

int dfs(int node) {
    visited[node] = true;

    subtree[node] = 1;
    for(int next : A[node]) {
        if(!visited[next]){
            subtree[node] += dfs(next);
        }
    }
    return subtree[node];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, R, Q;
    cin >> N >> R >> Q;

    A.resize(N + 1);
    visited.resize(N + 1, false);
    subtree.resize(N + 1);
    for(int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        A[u].push_back(v);
        A[v].push_back(u);
    }

    dfs(R);

    for(int i = 0; i < Q; i++) {
        int a;
        cin >> a;
        cout << subtree[a] << "\n";
    }
}