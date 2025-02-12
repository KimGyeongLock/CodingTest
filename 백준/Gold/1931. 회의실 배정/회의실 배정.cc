#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp (pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first < b.first;
}

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

    sort(A.begin(), A.end(), cmp);
    
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
