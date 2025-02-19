#include <iostream>
#include <vector>

using namespace std;

vector<int> t_people;
vector<int> parents;
vector<vector<int> > party;

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

    if(a != b) {
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

    int truth;
    cin >> truth;
    t_people.resize(truth);
    parents.resize(N+1);
    party.resize(M);

    for(int i = 0; i < truth; i++) {
        cin >> t_people[i];
    }

    for(int i = 1; i <= N; i++) {
        parents[i] = i;
    }  

    for(int i = 0; i < M; i++) {
        int people_count;
        cin >> people_count;

        for(int j = 0; j < people_count; j++) {
            int temp;
            cin >> temp;
            party[i].push_back(temp);
        }
    }

    for(int i = 0; i < M; i++) {
        int firstPeople = party[i][0];
        for(int j = 1; j < party[i].size(); j++) {
            unionfunc(firstPeople, party[i][j]);
        }
    }

    int count = 0;
    for(int i = 0; i < M; i++) {
        int cur = party[i][0];
        bool t = false;
        for(int j = 0; j < truth; j++) {
            if (find(cur) == find(t_people[j])) {
                t = true;
            }
        }
        if (!t) count++;
    }

    cout << count;
}