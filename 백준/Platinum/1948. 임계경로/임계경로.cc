#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<pair<int, int> > > A;
vector<vector<pair<int, int> > > reverseA;
vector<int> indegree;
vector<int> critical;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    A.resize(n+1);
    reverseA.resize(n+1);
    indegree.resize(n+1, 0);
    critical.resize(n+1, 0);

    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        A[a].push_back(make_pair(b, c));
        reverseA[b].push_back(make_pair(a, c));
        indegree[b]++;
    }

    int startDosi, endDosi;
    cin >> startDosi >> endDosi;

    queue<int> myqueue;
    for(int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            myqueue.push(i);
        }
    }

    while(!myqueue.empty()) {
        int new_node = myqueue.front();
        myqueue.pop();
        for(pair<int, int> i : A[new_node]) {
            indegree[i.first]--;

            critical[i.first] = max(critical[i.first], critical[new_node] + i.second);

            if(indegree[i.first] == 0) {
                myqueue.push(i.first);
            }
        }
    }

    int resultCount = 0;
    vector<bool> visited(n+1, false);
    queue<int> rqueue;
    rqueue.push(endDosi);
    visited[endDosi] = true;
    while(!rqueue.empty()) {
        int new_node = rqueue.front();
        rqueue.pop();
        for(pair<int, int> i : reverseA[new_node]) {
            if(critical[new_node] == critical[i.first] + i.second) {
                resultCount++;
                if(!visited[i.first]) {
                    visited[i.first] = true;
                    rqueue.push(i.first);
                }
            }
        }
    }

    cout << critical[endDosi] << "\n" << resultCount;
}