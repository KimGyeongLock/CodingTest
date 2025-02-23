#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> v;
int result = 0;

void b(int start, int count, int sum) {
    if (sum > m) {
        return ;
    }

    if (count == 3) {
        result = max(result, sum);
        return;
    }

    for(int i = start; i < n; i++) {
        b(i + 1, count + 1, sum + v[i]);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    v.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    b(0, 0, 0);
    cout << result;
}