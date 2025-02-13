#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    long A, B;
    cin >> A >> B;

    vector<long> v(10000000+1); //10^14의 제곱근까지 소수를 탐색하면됨
    for(int i = 2; i < 10000001; i++) {
        v[i] = i;
    }

    for(int i = 2; i <= sqrt(10000001); i++) {
        if (v[i] == 0) continue;
        for(int j = i + i; j <= 10000001; j += i) {
            v[j] = 0;
        }
    }

    long count = 0;
    for(int i = 2; i <= 10000001; i++) {
        if (v[i] != 0) {
            long temp = v[i];

            while ((double) v[i] <= (double) B / (double) temp) {
                if ((double) v[i] >= (double) A / (double) temp) {
                    count++;
                }
                temp *= v[i];
            }
        }
    }

    cout << count;
}