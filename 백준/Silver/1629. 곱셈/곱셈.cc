#include <iostream>

using namespace std;

long long modpow(int A, int B, int M) {
    if (B == 0) return 1;
    long long half = modpow(A, B/2, M);
    long long sq = half * half % M;
    if (B & 1) {
        return sq * A % M;
    }
    else return sq;
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(0);

    int A, B, C;
    cin >> A >> B >> C;
    cout << modpow(A % C, B, C);
}