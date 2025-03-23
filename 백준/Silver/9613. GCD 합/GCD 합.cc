#include <iostream>
#include <vector>

using namespace std;

long gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    for(int i = 0; i < N; i++) {
        int c;
        cin >> c;

        vector<int> A(c);
        for(int j = 0; j < c; j++) {
            cin >> A[j];
        }
        long sum = 0;
        for(int j = 0; j < c - 1; j++) {
            for(int k = j + 1; k < c; k++) {
                sum += gcd(A[j], A[k]);
            }
        }
        cout << sum << "\n";
    }
}