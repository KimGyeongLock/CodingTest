#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

vector<vector<int> > tree;
vector<int> depth;
vector<bool> visited;
int parent[21][100001];
int kmax = 0;

void BFS(int node) {
    queue<int> myqueue;
    visited[node] = true;
    myqueue.push(node);
    int level = 1;
    int count = 0;
    int now_size = 1;

    while (!myqueue.empty())
    {
        int now = myqueue.front();
        myqueue.pop();
        for(int next : tree[now]) {
            if(!visited[next]) {
                visited[next] = true;
                myqueue.push(next);
                depth[next] = level;
                parent[0][next] = now;
            }
        }
        count++;
        if (count == now_size) {
            count = 0;
            level++;
            now_size = myqueue.size();
        }
    }
    
}

int executeLCA(int a, int b) {
    if (depth[a] < depth[b]) {
        int temp = a;
        a = b;
        b = temp;
    }

    for(int k = kmax; k >= 0; k--) {
        if (pow(2, k) <= depth[a] - depth[b]) {
            if (depth[b] <= depth[parent[k][a]]) {
                a = parent[k][a]; 
            }
        }
    }
    for(int k = kmax; k >= 0 && a != b; k--) {
        if (parent[k][a] != parent[k][b]) {
            a = parent[k][a];
            b = parent[k][b];
        }
    } //a와 b가 LCA 바로 아래 노드까지 도달.

    int LCA = a;
    if (a != b) {
        LCA = parent[0][LCA]; //한 칸 위의 노드가 LCA
    }
    return LCA;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N;

    tree.resize(N + 1);
    depth.resize(N + 1);
    visited.resize(N + 1, false);

    for(int i = 1; i < N; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    BFS(1);

    // 최대 가능 깊이 구하기
    int temp = 1;
    while (temp <= N) {
        temp *= 2;
        kmax++;
    }

    for(int k = 1; k <= kmax; k++) {
        for(int n = 1; n <= N; n++) {
            parent[k][n] = parent[k - 1][parent[k - 1][n]];
        }
    }

    cin >> M;

    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        cout << executeLCA(a, b) << "\n";
    }
}