#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > tree;
vector<bool> visited;
int answer = 0;
int delete_node;

void DFS(int n) {
    visited[n] = true;
    int cnt = 0;

    for(int i : tree[n]) {
        if(!visited[i] && i != delete_node) {
            cnt++;
            DFS(i);
        }
    }

    if(cnt == 0) {
        answer++;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    tree.resize(N);
    visited.resize(N);
    int root;
    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;
        if (a != -1) {
            tree[i].push_back(a);
            tree[a].push_back(i);
        } else {
            root = i;
        }
    }
    
    cin >> delete_node;

    if (delete_node == root) {
        cout << 0;
    } else {
        DFS(root);
        cout << answer;
    }
}