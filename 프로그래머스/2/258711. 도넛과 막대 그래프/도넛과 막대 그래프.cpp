#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<vector<int>> edges) {
    int max_node = 0;
    for (auto e : edges) {
        max_node = max(max(max_node, e[0]), e[1]);
    }
    
    vector<int> indegree(max_node+1, 0), outdegree(max_node+1, 0);
    for (auto e : edges) {
        outdegree[e[0]]++;
        indegree[e[1]]++;
    }
    
    int a = 0, b = 0, c = 0, d = 0;
    for (int i = 1; i <= max_node; i++) {
        if (indegree[i] == 0 && outdegree[i] >= 2) a = i;
        else if (outdegree[i] == 0 && indegree[i] >= 1) c++;
        else if (indegree[i] >= 2 && outdegree[i] >= 2) d++;
    }
    b = outdegree[a] - c - d;
    return {a, b, c, d};
}