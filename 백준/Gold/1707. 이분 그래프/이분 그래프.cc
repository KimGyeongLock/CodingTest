#include <iostream>
#include <vector>

using namespace std;


vector<vector<int> > vec;
vector<bool> visited;
vector<int> check;
bool result = true;

void DFS(int node) {
    visited[node] = true;

    for(int i : vec[node]) {
        if (!visited[i]) {
            check[i] = (check[node] + 1) % 2;
            DFS(i);
        } else if (check[node] == check[i]) {
            result = false;
        }
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int K;
    cin >> K;
    
    for(int i = 0; i < K; i++) {
        int V, E;
        cin >> V >> E;
        vec.resize(V+1);
        visited.resize(V+1, false);
        check.resize(V+1, 0);

        for(int j = 0; j < E; j++) {
            int a, b;
            cin >> a >> b;
            vec[a].push_back(b);
            vec[b].push_back(a);
        }

        for(int j = 1; j <= V; j++) {
            DFS(j);
            if(!result) break;
        }

        if(result) cout << "YES\n";
        else cout << "NO\n"; 

        for(int j = 1; j <= V; j++) {
            vec[j].clear();
            visited[j] = false;
        }
        fill(check.begin(), check.end(), 0);
        result = true;
    }
}