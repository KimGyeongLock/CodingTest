#include <string>
#include <vector>
#include <climits>
#include <queue>
#include <iostream>

using namespace std;

int answer = INT_MAX;

int calcWait(const vector<int>& arr, const vector<vector<int>> reqs) {
    int k = arr.size();
    int totalWait = 0;
    
    vector<vector<pair<int, int>>> byType(k);
    for (const auto& req : reqs) {
        int start = req[0];
        int time = req[1];
        int kind = req[2] - 1;
        
        byType[kind].push_back({start, time});
    }
    
    for (int t = 0; t < k; t++) {
        auto& v = byType[t];
        
        // sort(v.begin(), v.end());
        
        int m = arr[t];
        
        priority_queue<int, vector<int>, greater<>> pq;
        
        for (auto [start, duration] : v) {
            if (pq.size() < m) {
                pq.push(start + duration);
            } else {
                int available = pq.top(); pq.pop();
                
                if (start >= available) {
                    pq.push(start + duration);
                } else {
                    totalWait += available - start;
                    pq.push(available + duration);
                }
            }
        }
    }
    return totalWait;
}

void dfs(int idx, int n, int k, vector<int>& arr, const vector<vector<int>> reqs) {
    if (idx == k - 1) {
        arr[idx] = n;
        for (int x : arr) cout << x << " ";
        cout << "\n";
        answer = min(answer, calcWait(arr, reqs));
        return;
    }
    
    for (int i = 1; i <= n - (k - idx - 1); i++) {
        arr[idx] = i;
        dfs(idx+1, n - i, k, arr, reqs);
    }
}

int solution(int k, int n, vector<vector<int>> reqs) {
    vector<int> arr(k);
    dfs(0, n, k, arr, reqs);
    return answer;
}