#include <iostream>

using namespace std;

long x[10001], y[10001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }

    x[N] = x[0];
    y[N] = y[0];

    double result = 0;
    for(int i = 0; i < N; i++) {
        result += (x[i] * y[i + 1]) - (x[i + 1] * y[i]);
    }

    cout << fixed;
    cout.precision(1);
    cout << abs(result) / 2.0;
}