#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long A, B;
    cin >> A >> B;

    long max, min;
    if (A <= B) {
        max = B;
        min = A;
    } else {
        max = A;
        min = B;
    }

    while(max % min != 0) {
        long temp = min;
        min = max % min;
        max = temp;
    }

    for(long i = 0; i < min; i++) {
        cout << 1;
    }
}