#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int calPoint(vector<int> t, vector<vector<int>> team) {
    int n = t.size();
    int total = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            total += (team[t[i]][t[j]] + team[t[j]][t[i]]);
        }
    }
    return total;
}
 
int answer = INT_MAX;

void dfs(int idx, int n, vector<int> start, vector<vector<int>> team) {
    if (start.size() == n / 2) {
        vector<int> link;
        for (int i = 0; i < n; i++) {
            if (find(start.begin(), start.end(), i) == start.end()) {
                link.push_back(i);
            }
        }

        int s = calPoint(start, team);
        int l = calPoint(link, team);

        answer = min(answer, abs(s - l));
        return;
    }


    for (int i = idx; i < n; i++) {
        start.push_back(i);
        dfs(i+1, n, start, team);
        start.pop_back();
    }
}

int solution(int n, vector<vector<int>> team) {
    dfs(0, n, {}, team);
    return answer;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<vector<int>> team(N, vector<int>(N));

    for (int i = 0; i < N; i++) 
        for (int j = 0; j < N; j++) 
            cin >> team[i][j];
    
    cout << solution(N, team);
}