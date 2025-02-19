#include <iostream>
#include <vector>

using namespace std;

vector<int> parents;
vector<vector<int> > city;
vector<int> route;

int find(int a) {
    if (a == parents[a]) {
        return a;
    } else {
        return parents[a] = find(parents[a]);
    }
}

void unionfunc(int a, int b) {
    a = find(a);
    b = find(b);

    if (a != b) {
        parents[b] = a;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    parents.resize(N+1);
    city.resize(N+1, vector<int>(N+1));
    route.resize(M);

    for(int i = 1; i <= N; i++) {
        parents[i] = i;
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cin >> city[i][j];
        }
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if (city[i][j] == 1) {
                unionfunc(i, j);
            }
        }
    }

    for(int i = 0; i < M; i++) {
        cin >> route[i];
    }

    int first = find(route[0]);
    bool result = true;
    for(int i = 1; i < M; i++) {
        if (find(route[i]) != first) {
            result = false;
            break;
        }
    }
    if (result) cout << "YES";
    else cout << "NO";
}