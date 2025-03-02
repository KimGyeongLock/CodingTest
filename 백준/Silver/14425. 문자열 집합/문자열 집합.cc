#include <iostream>
#include <set>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    set<string> s;
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;
        s.insert(str);
    }
    int count = 0;
    for(int i = 0; i < m; i++) {
        string str;
        cin >> str;
        if(s.count(str)) {
            count++;
        }
    }

    cout << count;
}