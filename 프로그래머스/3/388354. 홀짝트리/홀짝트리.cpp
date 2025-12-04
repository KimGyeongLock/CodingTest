#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

vector<int> solution(vector<int> nodes, vector<vector<int>> edges) {
    int n = nodes.size();
    unordered_map<int, int> idx;
    vector<vector<int>> adj(n);
    
    for (int i = 0; i < n; i++) {
        idx[nodes[i]] = i; 
    }
    
    for (auto e : edges) {
        adj[idx[e[0]]].push_back(idx[e[1]]);
        adj[idx[e[1]]].push_back(idx[e[0]]);
    }
    
    vector<int> deg(n), nd(n), dg(n), s(n);
    for (int i = 0; i < n; i++) {
        deg[i] = adj[i].size();
        nd[i] = nodes[i] & 1;
        dg[i] = deg[i] & 1;
        s[i] = (nd[i] == dg[i]) ? 1 : 0;
    }
    
    int holjak = 0;
    int rev_holjak = 0;
    vector<bool> visited(n);
    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        queue<int> q;
        q.push(i);
        visited[i] = true;
        
        int comp_size = 0;
        int cnt_s1 = 0;
        while(!q.empty()) {
            int u = q.front(); q.pop();
            comp_size++;
            cnt_s1 += s[u];
            
            for (int v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        int cnt_s0 = comp_size - cnt_s1;
        if (cnt_s1 == 1) holjak++;
        if (cnt_s0 == 1) rev_holjak++;
    }
    
    return {holjak, rev_holjak};
}