#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int> > V;
vector<bool> visited;
vector<int> answer;

void BFS(int node) {
    queue<int> myqueue;
    myqueue.push(node);
    visited[node] = true;

    while(!myqueue.empty()) {
        int new_node = myqueue.front();
        myqueue.pop();
        for(int i : V[new_node]) {
            if(!visited[i]) {
                visited[i] = true;
                myqueue.push(i);
                answer[i]++;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    V.resize(N+1);
    visited.resize(N+1, false);
    answer.resize(N+1, 0);

    for(int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        V[A].push_back(B);
    }

    for(int i = 1; i <= N; i++) {
        fill(visited.begin(), visited.end(), false);
        BFS(i);
    }

    int max_v = 0;
    for(int i = 1; i <= N; i++) {
        max_v = max(max_v, answer[i]);
    }

    for(int i = 1; i <= N; i++) {
        if (max_v == answer[i]) {
            cout << i << " ";
        }
    }
}