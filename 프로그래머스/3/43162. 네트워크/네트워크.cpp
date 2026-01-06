#include <string>
#include <vector>
#include <unordered_set>

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

int solution(int n, vector<vector<int>> computers) {
    parent.resize(n);
    for (int i = 0; i < n; i++) parent[i] = i;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && computers[i][j] == 1) {
                unionfunc(i, j);
            }
        }
    }
  
    unordered_set<int> s;
    for (int i = 0; i < n; i++) {
        s.insert(find(i));
    }
    
    return s.size();
}