#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

// (1) 모듈러 거듭제곱: O(log Y)
ll mod_pow(ll x, ll y, ll mod) {
    __int128 r = 1, b = x % mod;
    while (y > 0) {
        if (y & 1)        r = (r * b) % mod;
        b = (b * b) % mod;
        y >>= 1;
    }
    return (ll)r;
}

// (2) ⌊X^Y / Z⌋ ≥ 1000 인지 100% 정수판정
bool isBigQ(ll X, ll Y, ll Z) {
    __int128 cur = 1, base = X, thr = (__int128)Z * 1000;
    while (Y > 0) {
        if (Y & 1) {
            cur *= base;
            if (cur >= thr) return true;
        }
        base = (base * base >= thr ? thr : base * base);
        Y >>= 1;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        ll x, y, z;
        cin >> x >> y >> z;

        // X^Y mod (Z*1000)
        ll m = mod_pow(x, y, z * 1000LL);

        // 정수부, 소수부 계산
        ll t = m / z;
        ll f = (m % z) * 1000 / z;

        // 원래 몫 ≥ 1000 인지 판정
        bool big = isBigQ(x, y, z);

        string intPart = to_string(t);
        string fracPart = to_string(f);

        if (intPart.length() >= 3) {
            cout << intPart.substr(intPart.length() - 3);
        } else if (big) {
            cout << string(3 - intPart.length(), '0') << intPart;
        } else {
            cout << intPart;
        }

        cout << ".";

        if (fracPart.length() < 3) {
            cout << string(3 - fracPart.length(), '0') + fracPart << "\n";
        } else if (fracPart.length() >= 3) {
            cout << fracPart.substr(0, 3) << "\n";
        }
    }
    return 0;
}
