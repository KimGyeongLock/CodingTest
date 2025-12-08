#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void makeSum(int depth, int total, const vector<int>& idx, vector<int>& sum, const vector<vector<int>>& dice) {
    if (depth == idx.size()) {
        sum[total]++;
        return;
    }
    
    for (int i = 0; i < dice[idx[depth]].size(); i++) {
        makeSum(depth+1, total + dice[idx[depth]][i], idx, sum, dice);
    }
}

vector<int> solution(vector<vector<int>> dice) {
    vector<int> answer;
    int max_v = -1;
    int n = dice.size();
    vector<int> arr(n/2, 1);
    for (int i = 0; i < n/2; i++) arr.push_back(0);
    
    sort(arr.begin(), arr.end());
    do {
        vector<int> aIdx, bIdx;
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) aIdx.push_back(i);
            else bIdx.push_back(i);
        }
        
        int maxSum = (n / 2) * 100;         
        vector<int> aSum(maxSum+1), bSum(maxSum+1);
        makeSum(0, 0, aIdx, aSum, dice);
        makeSum(0, 0, bIdx, bSum, dice);
        
        int win = 0;
        for (int i = 0; i < maxSum; i++) {
            int cnt = 0;
            if (aSum[i]) {
                for (int j = 0; j < i; j++) {
                    cnt += bSum[j];
                }
            }
            win += cnt * aSum[i];
        }
        cout << win << "\n";
        if (max_v < win) {
            max_v = win;
            answer = aIdx;
        }
        
    } while (next_permutation(arr.begin(), arr.end()));
    
    for (int& i : answer) {
        i++;
    }
    return answer;
}