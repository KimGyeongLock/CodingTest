#include <iostream>
#include <vector>

using namespace std;

long long solution(int n, vector<int> a, int b, int c) {
    long long cnt = n;
    for (int num : a) {
        num -= b;
        if (num > 0) {
            cnt += num / c;
            if (num % c != 0) cnt++;
        }
    }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    int B, C;
    cin >> B >> C;

    cout << solution(N, A, B, C);
}