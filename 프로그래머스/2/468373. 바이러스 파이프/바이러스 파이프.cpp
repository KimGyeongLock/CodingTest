#include <string>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

vector<vector<pair<int, int>>> edgeList;
int answer = INT_MIN;
int N;

vector<int> bfs(vector<int> infected, int type) {
    queue<int> q;
    vector<bool> visited(N + 1, false);
    vector<int> result;

    for (int i : infected) {
        q.push(i);
        visited[i] = true;
        result.push_back(i);
    }
    
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for (auto e : edgeList[cur]) {
            if (visited[e.first]) continue;
            if (e.second != type) continue;
            
            visited[e.first] = true;
            q.push(e.first);
            result.push_back(e.first);
        }
    }
    
    return result;
}

void dfs(int depth, int k, vector<int> infected) {
    if (depth == k) {
        answer = max(answer, (int) infected.size());
        return;
    }
    
    for (int i = 1; i <= 3; i++) {
        vector<int> nInfected = bfs(infected, i);
        dfs(depth + 1, k, nInfected);
    }
}

int solution(int n, int infection, vector<vector<int>> edges, int k) {
    edgeList.resize(n+1);
    N = n;
    for (auto e : edges) {
        edgeList[e[0]].push_back({e[1], e[2]});
        edgeList[e[1]].push_back({e[0], e[2]});
    }
    
    vector<int> infected;
    infected.push_back(infection);
    dfs(0, k, infected);
    return answer;
}