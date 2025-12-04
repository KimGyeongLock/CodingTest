#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int answer = 0;
void dfs(int start, int n, vector<int> arr, const vector<vector<int>> q, const vector<int> ans) {
    if (arr.size() == 5) {
        for (int i = 0; i < q.size(); i++) {
            auto e = q[i];
            int cnt = 0;
            for (int num : e) {
                if (find(arr.begin(), arr.end(), num) != arr.end()) cnt++;
            }
            if (cnt > ans[i] || cnt < ans[i]) return;
        }
        
        answer++;
        return;
    }
    
    for (int i = start + 1; i <= n; i++) {
        arr.push_back(i);
        dfs(i, n, arr, q, ans);
        arr.pop_back();
    }
}

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    vector<int> arr;
    dfs(0, n, arr, q, ans);
    return answer;
}