#include <iostream>

using namespace std;

bool isPrime(int x) {
    if (x < 2) return false;

    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (isPrime(a)) cnt++;
    }
    cout << cnt;
    return 0;
}