/**
 * @file 13164.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-03-22
 * 
 * @copyright Copyright (c) 2025
 * 
 * N명의 원생 키순서
 * K개의 조
 * 티셔츠를 맞추는 비용 = 가장 키가 큰 원생 - 가장 키가 작은 원생
 * 최소 비용
 * 1 3 5 6 10
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> diff;
vector<int> A;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    cin >> N >> K;

    A.resize(N);
    diff.resize(N - 1, 0);
    int sum = 0;
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for(int i = 0; i < N - 1; i++) {
        diff[i] = A[i + 1] - A[i];
        sum += diff[i];
    }

    sort(diff.begin(), diff.end(), greater<int>());
    for(int i = 0; i < K - 1; i++) {
        sum -= diff[i];
    }
    cout << sum;
}