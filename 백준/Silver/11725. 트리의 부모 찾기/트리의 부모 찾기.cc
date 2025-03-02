#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > A;
vector<bool> visited;
vector<int> answer;

void DFS(int number) {
    visited[number] = true;

    for(int i : A[number]) {
        if (!visited[i]) {
            answer[i] = number;
            DFS(i);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    A.resize(N+1);
    visited.resize(N+1, false);
    answer.resize(N+1);
    for(int i = 1; i < N; i++) {
        int a, b;
        cin >> a >> b;
        A[a].push_back(b);
        A[b].push_back(a);
    }

    DFS(1);

    for(int i = 2; i <= N; i++) {
        cout << answer[i] << "\n";
    }
}