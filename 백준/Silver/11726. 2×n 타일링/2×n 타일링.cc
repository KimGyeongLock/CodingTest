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

    vector<int> A(1001);
    A[1] = 1;
    A[2] = 2;

    for(int i = 3; i <= N; i++) {
        A[i] = (A[i-1] + A[i-2]) % 10007;
    }
    cout << A[N];
}