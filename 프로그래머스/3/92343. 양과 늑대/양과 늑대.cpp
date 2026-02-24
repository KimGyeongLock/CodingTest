#include <string>
#include <vector>

using namespace std;

vector<vector<int>> edgeList;
vector<int> visited;
int maxSheep = 0;

void dfs(vector<int>& info, int sheep, int wolf, vector<int> possible) {
    maxSheep = max(maxSheep, sheep);
    for (int i = 0; i < possible.size(); i++) {
        vector<int> tmp = possible;
        int nsheep = sheep, nwolf = wolf;
        int p = tmp[i];
        
        if (info[p] == 0) { // sheep
            nsheep++;
        } else { // wolf
            nwolf++;
            if (nwolf >= nsheep) continue;
        }
        tmp.erase(tmp.begin() + i);
        for (auto& e : edgeList[p]) tmp.push_back(e);
        visited[p] = true;
        dfs(info, nsheep, nwolf, tmp);
        visited[p] = false;
    }   
}

int solution(vector<int> info, vector<vector<int>> edges) {
    int n = info.size();
    edgeList.assign(n, {});
    visited.assign(n, false);
    for (auto& e : edges) {
        edgeList[e[0]].push_back(e[1]);
    }
    visited[0] = true;
    dfs(info, 1, 0, edgeList[0]);
    return maxSheep;
}