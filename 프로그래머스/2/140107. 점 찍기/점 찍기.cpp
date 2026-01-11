#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int k, int d) {
        long long kk = k;
        long long dd = d;
        long long d2 = dd * dd;

        long long ans = 0;

        for (long long x = 0; x <= dd; x += kk) {
            long long remain = d2 - x * x;

            // y = floor(sqrt(remain)) (부동소수 오차 보정 포함)
            long long y = (long long) sqrt((long double)remain);
            while ((y + 1) * (y + 1) <= remain) y++;
            while (y * y > remain) y--;

            ans += (y / kk) + 1; // y=0 포함
        }

        return ans;
    }