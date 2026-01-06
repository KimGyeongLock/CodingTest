#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> parent;

int find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void unionfunc(int a, int b) {
    a = find(a);
    b = find(b);
    
    if (a != b) {
        parent[b] = a;
    }
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    parent.resize(n);
    for (int i = 0; i < n; i++) parent[i] = i;
    
    sort(costs.begin(), costs.end(), [&](const auto& a, const auto& b){
        return a[2] < b[2]; 
    });
    
    for (auto c : costs) {
        if (find(c[0]) != find(c[1])) {
            unionfunc(c[0], c[1]);
            answer += c[2];
        }
        
    }
    return answer;
}