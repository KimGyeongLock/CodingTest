#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef struct Edge {
    int s, e, v;
    bool operator > (const Edge& temp) const {
        return v > temp.v;
    }
} Edge;

vector<int> parent;

int find(int a) {
    if (a == parent[a]) {
        return a;
    }

    return parent[a] = find(parent[a]);
}

void unionfunc(int a, int b) {
    a = find(a);
    b = find(b);

    if (a != b) {
        parent[b] = a;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    priority_queue<Edge, vector<Edge>, greater<Edge> > pq;
    parent.resize(N+1);

    int sum = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            char tempc = cin.get(); //캐릭터 하나만 받기

            if (tempc == '\n') { //enter일때 다음걸 받기
                tempc = cin.get();
            }

            int temp = 0;

            if (tempc >= 'a' && tempc <= 'z') {
                temp = tempc - 'a' + 1;
            } else if (tempc >= 'A' && tempc <= 'Z') {
                temp = tempc - 'A' + 27;
            }
            sum += temp;

            if (i != j && temp != 0) {
                pq.push(Edge{ i, j, temp });
            }
        }
    }

    for(int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    int useEdge = 0;
    int result = 0;

    while(!pq.empty()) {
        Edge now = pq.top();
        pq.pop();

        if (find(now.s) != find(now.e)) {
            unionfunc(now.s, now.e);
            result += now.v;
            useEdge++;
        }
    }

    if (useEdge == N - 1) {
        cout << sum - result;
    } else {
        cout << -1;
    }
}