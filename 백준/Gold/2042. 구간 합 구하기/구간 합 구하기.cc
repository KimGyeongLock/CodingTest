#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N, M, K;
vector<long> A;

void changeVal(int index, long val) {
    long diff = val - A[index];

    while(index > 0) {
        A[index] += diff;
        index /= 2;
    }
}

long getSum(long s, long e) {
    long partSum = 0;
    while(s <= e) {
        if (s % 2 == 1) {
            partSum += A[s];
            s++;
        }
        if (e % 2 == 0) {
            partSum += A[e];
            e--;
        }
        s = s / 2;
        e = e / 2;
    }
    return partSum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> K;

    // 1. 트리 초기화하기
    int k = 1;
    while(pow(2, k) < N) {
        k++;
    }
    int treeSize = int(pow(2, k)) * 2;
    int start_index = treeSize / 2;
    A.resize(treeSize, 0);

    for(int i = 0; i < N; i++) {
        cin >> A[i + start_index];
    }
    for(int i = start_index - 1; i >= 1; i--) {
        A[i] = A[2 * i] + A[2 * i + 1];
    }

    

    for(int i = 0; i < M + K; i++) {
        long a, s, e;
        cin >> a >> s >> e;

        if (a == 1) {
            // 2. 데이터 업데이트하기
            changeVal(start_index -1 + s, e);
        } else if (a == 2) {
            // 3. 질의값 구하기
            cout << getSum(start_index -1 + s, start_index -1 + e) << "\n";
        }
    }


}