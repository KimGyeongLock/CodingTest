#include <string>
#include <vector>
#include <iostream>

using namespace std;

int answer = 0;
void dfs(vector<bool> visited, vector<vector<int>> dungeons, int depth, int k) {
    for(int i = 0; i < dungeons.size(); i++) {
        if(!visited[i] && k >= dungeons[i][0]) {
            // cout << k << " " << dungeons[i][0] << "\n";
            visited[i] = true;
            dfs(visited, dungeons, depth + 1, k - dungeons[i][1]);
            answer = max(answer, depth);
            visited[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    vector<bool> visited(dungeons.size(), false);
    dfs(visited, dungeons, 1, k);
    
    return answer;
}