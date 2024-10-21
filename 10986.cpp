#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    vector<long> v(N+1, 0);
    vector<long> s(N+1, 0);
    for(int i=1;i<N+1;i++) {
        cin >> v[i];
        s[i] = s[i-1] + v[i];
    }

    vector<long> C(M, 0);
    long count = 0;
    for(int i = 1; i < N+1; i++) {
        int remainder = s[i] % M;
        if(remainder == 0) count++;
        C[remainder]++;
    }

    for(int i=0;i<C.size();i++) {
        count += C[i] * (C[i] - 1) / 2;
    }
    cout << count;
}