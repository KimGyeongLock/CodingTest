#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> g;
vector<int> visited;

int bfs(int s, int e) {
    queue<int> q;
    q.push(s);
    visited.assign(g.size(), -1);
    visited[s] = 0;
    
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        
        if (cur == e) return visited[cur];
        
        for (int nxt : g[cur]) {
            if (visited[nxt] == -1) {
                visited[nxt] = visited[cur] + 1;
                q.push(nxt);
            }
        }
    }
    return -1;
}

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    
    g.assign(n+1, {});
    visited.assign(n+1, 0);
    for (auto& r : roads) {
        g[r[0]].push_back(r[1]);
        g[r[1]].push_back(r[0]);
    }
    
    for (int s : sources) {
        int d = bfs(s, destination);
        answer.push_back(d);
    }
    
    
    return answer;
}