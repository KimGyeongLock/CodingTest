#include <iostream>
#include <vector>

using namespace std;

int answer = 0;

void dfs(int start, int total, vector<int>& T, vector<int>& P) {
    int n = T.size();
    answer = max(answer, total);
    for (int i = start + T[start]; i < n; i++) {
        if (i + T[i] > n) continue;
        dfs(i, total + P[i], T, P);
    }
}
 
int solution(int n, vector<int> T, vector<int> P) {
    
    for (int i = 0; i < n; i++) {
        if (i + T[i] <= n) {
            dfs(i, P[i], T, P);
        }
    }

    return answer;
}

int main()
{
    int N;
    cin >> N;
    vector<int> T(N), P(N);
    for (int i = 0; i < N; i++) {
        cin >> T[i] >> P[i];
    }
     
    cout << solution(N, T, P);
}