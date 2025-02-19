#include <iostream>
#include <vector>

using namespace std;

vector<int> vec;

int find(int a) {
    if (a == vec[a]) {
        return a;
    } else {
        return vec[a] = find(vec[a]);
    }
}

void unionfunc(int a, int b) {
    a = find(a);
    b = find(b);

    if (a != b) {
        vec[b] = a;
    }
}

bool checkSame(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) {
        return true;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vec.resize(n+1);

    for(int i = 1; i <= n; i++) {
        vec[i] = i;
    }

    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 0) {
            unionfunc(b, c);
        } else if (a == 1) {
            if (checkSame(b, c)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
}