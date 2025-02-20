#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> b_time;
vector<vector<int> > A;
vector<int> indegree;
vector<int> answer;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    A.resize(N+1);
    b_time.resize(N+1);
    indegree.resize(N+1, 0);
    answer.resize(N+1, 0);

    for(int i = 1; i <= N; i++) {
        cin >> b_time[i];

        while(true) {
            int b_number;
            cin >> b_number;

            if(b_number == -1) break;

            A[b_number].push_back(i);
            indegree[i]++;
        }
    }

    queue<int> myqueue;
    for(int i = 1; i <= N; i++) {
        if (indegree[i] == 0) {
            myqueue.push(i);
        }
    }

    while(!myqueue.empty()) {
        int new_node = myqueue.front();
        myqueue.pop();
        for(int i : A[new_node]) {
            indegree[i]--;

            answer[i] = max(answer[i], answer[new_node] + b_time[new_node]);

            if (indegree[i] == 0) {
                myqueue.push(i);
            }
        }
    }

    for(int i = 1; i <= N; i++) {
        cout << answer[i] + b_time[i] << "\n";
    }
}