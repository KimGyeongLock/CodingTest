#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int mod = 1e9 + 7;

long long modpow(long long a, long long b) {
    if (b == 0) return 1;
    long long half = modpow(a, b/2);
    long long sq = half * half % mod;
    if (b & 1) return sq * a % mod;
    else return sq;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> v(n);
    long long total = 0;
    for (int i = 0; i < n; i++) {
        long c, k;
        cin >> c >> k;
        if (k == 0) continue;
        long p = modpow(2, k-1);
        p = (p * k % mod) * c % mod;
        total = (total + p) % mod;
    }

    cout << total;
}