#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int> > A;
vector<int> visited;

void BFS(int node) {
    queue<int> myqueue;
    myqueue.push(node);
    visited[node]++;

    while(!myqueue.empty()) {
        int back = myqueue.front();
        myqueue.pop();

        for(int next : A[back]) {
            if (visited[next] == -1) {
                myqueue.push(next);
                visited[next] = visited[back] + 1;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M, K, X;
    cin >> N >> M >> K >> X;

    A.resize(N+1);
    visited.resize(N+1, -1);

    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        A[a].push_back(b);
    }

    BFS(X);

    vector<int> answer;
    for(int i = 1; i <= N; i++) {
        if (visited[i] == K) {
            answer.push_back(i);
        }
    }

    if (answer.empty()) cout << -1 << "\n";
    else {
        sort(answer.begin(), answer.end());
        for(int i : answer) {
            cout << i << "\n";
        }
    }
}