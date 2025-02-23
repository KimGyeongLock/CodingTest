#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;

    vector<int> v(n+1);
    v[1] = 1;
    v[2] = 2;
    
    for(int i = 3; i <= n; i++) {
        v[i] = (v[i-1] + v[i-2])  % 10007;
    }

    cout << v[n];
}