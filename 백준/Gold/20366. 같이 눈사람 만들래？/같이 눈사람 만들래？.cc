#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<long> H(N);
    for(int i = 0; i < N; i++) {
        cin >> H[i];
    }

    sort(H.begin(), H.end());

    long min_v = LONG_MAX;
    for(int i = 0; i < N - 1; i++) {
        for(int j = i + 1; j < N; j++) {
            long first_snow = H[i] + H[j];

            int left = 0;
            int right = N - 1;
            while(left < right) {
                if (left == i || left == j) {
                    left++;
                    continue;
                }
                if (right == i || right == j) {
                    right--;
                    continue;
                }

                long second_snow = H[left] + H[right];
                min_v = min(min_v, abs(first_snow - second_snow));

                if (second_snow < first_snow) { //두번째 눈사람이 더 작으면 키우기
                    left++;
                } else {
                    right--;
                }
            }
        }
    }

    cout << min_v;
}