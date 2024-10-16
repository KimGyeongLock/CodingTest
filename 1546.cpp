#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    int total = 0;
    int max_v = 0;
    for(int i=0;i<N;i++) {
        int point;
        cin >> point;
        total += point;
        max_v = max(max_v, point);
    }
    cout << ((float) total / max_v) * 100 / N;
}