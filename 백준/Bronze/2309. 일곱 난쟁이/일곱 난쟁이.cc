#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[9];
vector<int> ans;
void dfs(int idx, int cnt, int total, vector<int>& vec) {
    if (cnt == 7) {
        if (total == 100) {
            ans = vec;
        }
        return;
    }
    if (idx == 9) return; 
    vec.push_back(arr[idx]);
    dfs(idx+1, cnt+1, total + arr[idx], vec);
    vec.pop_back();

    dfs(idx+1, cnt, total, vec);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 0; i < 9; i++)
        cin >> arr[i];

    vector<int> cur; 
    dfs(0, 0, 0, cur);

    sort(ans.begin(), ans.end());

    for (int i : ans) {
        cout << i << "\n";
    }

    return 0;
}