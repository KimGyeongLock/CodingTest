#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<int> v;
set<int> s;
int cut = 0;

int find(int a) {
    if (a == v[a]) {
        return a;
    }

    return v[a] = find(v[a]);
}

void unionfunc(int a, int b) {
    a = find(a);
    b = find(b);

    if (a != b) {
        v[b] = a;
    } else {
        cut++;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    v.resize(n+1);
    for(int i = 1; i <= n; i++) {
        v[i] = i;
    }

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        unionfunc(a, b);
    }

    for(int i = 1; i <= n; i++) {
        s.insert(find(i));
    }

    cout << s.size() - 1 + cut;
}