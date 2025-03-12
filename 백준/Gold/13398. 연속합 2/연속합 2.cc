#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<int> vec(N);
    vector<int> L(N);
    vector<int> R(N);

    for(int i = 0; i < N; i++) {
        cin >> vec[i];
    }
    L[0] = vec[0];
    int result = L[0]; //모두 음수일때
    for(int i = 1; i < N; i++) {
        L[i] = max(vec[i], L[i - 1] + vec[i]);
        result = max(result, L[i]);
    }
    R[N - 1] = vec[N - 1];
    for(int i = N - 2; i >= 0; i--) {
        R[i] = max(vec[i], R[i + 1] + vec[i]);
    }

    for(int i = 1; i < N - 1; i++) {
        result = max(result, L[i - 1] + R[i + 1]);
    }

    cout << result;
}