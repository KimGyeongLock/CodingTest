#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long min, max;
    cin >> min >> max;

    vector<bool> A(max - min + 1, false);

    for(long i = 2; i * i <= max; i++) {
        long pow = i * i;
        long start_index = min / pow;

        if (min % pow != 0) {
            start_index++;
        }

        for(long j = start_index; j * pow <= max; j++) {
            A[(j*pow) - min] = true;
        }
    }

    int count = 0;
    for(int i = 0; i < (max - min + 1); i++) {
        if (!A[i]) {
            count++;
        }
    }
    cout << count;
}