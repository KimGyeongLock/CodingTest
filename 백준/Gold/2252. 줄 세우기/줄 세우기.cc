#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int> > A;
vector<int> indegree;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    A.resize(N+1);
    indegree.resize(N+1, 0);

    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        A[a].push_back(b);
        indegree[b]++;
    }

    queue<int> myqueue;
    for(int i = 1; i <= N; i++) {
        if(indegree[i] == 0) {
            myqueue.push(i);
        }
    }

    while(!myqueue.empty()){
        int new_node = myqueue.front();
        myqueue.pop();

        cout << new_node << " ";
        for(int i : A[new_node]) {
            indegree[i]--;
            if(indegree[i] == 0) { 
                myqueue.push(i);
            }
        }
    }
}