#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<pair<int, int> > A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i].second >> A[i].first; //second: 첫시간, first: 끝시간
    }

    sort(A.begin(), A.end());
    
    int end = -1;
    int count = 0;
    for(int i = 0; i < N; i++) {
        if (end <= A[i].second) {
            end = A[i].first;
            count++;
        }
    }
    cout << count;
}