#include <string>
#include <vector>
#include <queue>

using namespace std;

int bfs(int start, vector<vector<int>>& graph, vector<bool>& visited) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    int count = 1;
    
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for(int next : graph[node]) {
            if(!visited[next]) {
                visited[next] = true;
                q.push(next);
                count++;
            }
        }
    }
    return count;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = n;
    
    for (int i = 0; i < wires.size(); i++) {
        vector<vector<int>> graph(n + 1);
        for(int j = 0; j < wires.size(); j++) {
            if(i == j) continue;
            int a = wires[j][0], b = wires[j][1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        
        vector<bool> visited(n + 1, false);
        int cnt = bfs(1, graph, visited);
        int diff = abs((n - cnt) - cnt);
        answer = min(answer, diff);
    }
    
    return answer;
}