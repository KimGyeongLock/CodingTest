#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<long> D(N+1); //N명일 때 선물을 교환할 수 있는 모든 경우의 수

    D[1] = 0;
    D[2] = 1;  

    for(int i = 3; i <= N; i++) {
        D[i] = (i - 1) * (D[i - 2] + D[i - 1]) % 1000000000;
    }

    cout << D[N];
}