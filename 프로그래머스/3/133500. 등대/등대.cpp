#include <string>
#include <vector>
#include <array>

using namespace std;

vector<vector<int>> g;
vector<array<int,2>> dp;
vector<int> parent;

void dfs(int u) {
    dp[u][0] = 0;
    dp[u][1] = 1;
    
    for (int v : g[u]) {
        if (v == parent[u]) continue;
        parent[v] = u;
        dfs(v);
        
        dp[u][1] += min(dp[v][0], dp[v][1]);
        dp[u][0] += dp[v][1];
    }
}

int solution(int n, vector<vector<int>> lighthouse) {
    g.assign(n+1, {});
    for (auto &e : lighthouse) {
        int u = e[0], v = e[1];
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    dp.assign(n+1, {0, 0});
    parent.assign(n+1, 0);
    
    int root = 1;
    parent[root] = -1;
    dfs(root);
    
    return min(dp[root][0], dp[root][1]);
}