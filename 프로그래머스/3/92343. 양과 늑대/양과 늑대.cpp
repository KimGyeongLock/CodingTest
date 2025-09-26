#include <string>
#include <vector>

using namespace std;
int answer = 0;

void dfs(int sheep, int wolf, vector<int> cand, const vector<int>& info, const vector<vector<int>>& edges) {
    answer = max(answer, sheep);
    for (int i = 0; i < cand.size(); i++) {
        int u = cand[i];
        int nsheep = sheep + (info[u] == 0);
        int nwolf = wolf + (info[u] == 1);
        if (nwolf >= nsheep) continue;
        
        vector<int> next = cand;
        next.erase(next.begin() + i);
        
        for (int c : edges[u]) {
            next.push_back(c);
        }
        
        dfs(nsheep, nwolf, next, info, edges);
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    
    vector<vector<int>> edgeList(info.size());
    for (auto& e : edges) {
        edgeList[e[0]].push_back(e[1]);
    }
    
    vector<int> cand = {0};
    dfs(0, 0, cand, info, edgeList);
    return answer;
}