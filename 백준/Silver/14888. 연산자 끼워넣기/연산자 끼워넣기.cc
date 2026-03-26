#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int a = INT_MIN, b = INT_MAX;

void dfs(int idx, const vector<int>& A, vector<int>& com, int total) {
    if (idx == A.size()) {
        a = max(a, total);
        b = min(b, total);
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (com[i] == 0) continue;

        com[i]--;
        if (i == 0) {
            dfs(idx + 1, A, com, total + A[idx]);
        } else if (i == 1) {
            dfs(idx + 1, A, com, total - A[idx]);
        } else if (i == 2) {
            dfs(idx + 1, A, com, total * A[idx]);
        } else {
            dfs(idx + 1, A, com, total / A[idx]);
        }
        com[i]++;
    }
}

pair<int, int> solution(int n, vector<int> A, int plus, int minus, int multi, int divide) {

    vector<int> commands = {plus, minus, multi, divide};
    dfs(1, A, commands, A[0]);
    return {a, b};
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    int plus = 0, minus = 0, multi = 0, divide = 0;
    cin >> plus >> minus >> multi >> divide;

    cout << solution(N, A, plus, minus, multi, divide).first << "\n" << solution(N, A, plus, minus, multi, divide).second;
}