#include <iostream>
#include <vector>
// #include <algorithm>
#include <queue>

using namespace std;

int main()
{
    /*
        표에 적힌 수는 -10억보다 크거나 같고, 10억보다 작거나 같은 정수 => type long long?
        모든 수는 자신의 한칸 위에 있는 수보다 크다

        1. 모든 수를 list에 넣어서 정렬 -> 5번째  => 메모리 초과 (12MB) 1500*1500 = 2,250,000 배열은 크다
            int 4 byte => 2,250,000 * 4 = 9,000,000 byte => 9MB
            정렬 - NlogN 
        2. priority queue
    */
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;

    priority_queue<int, vector<int>, greater<int> > pq;

    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            int val;
            cin >> val;

            if (pq.size() < N) {
                pq.push(val);
            } else if (pq.top() < val) {
                pq.pop();
                pq.push(val);
            }
        }
    }

    cout << pq.top();
    // vector<int> vec(N*N);

    // for(int i=0;i<N;i++) {
    //     for(int j=0;j<N;j++) {
    //         cin >> vec[i * N + j];           
    //     }
    // }
    // sort(vec.begin(), vec.end(), greater<int>());
    // cout << vec[N-1];
}