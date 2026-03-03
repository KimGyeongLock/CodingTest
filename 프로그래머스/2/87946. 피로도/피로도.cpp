#include <string>
#include <vector>

using namespace std;

int best = 0;
vector<bool> used;

void dfs(int k, vector<vector<int>>& dungeons, int cnt) {
    best = max(best, cnt);
    
    for (int i = 0; i < dungeons.size(); i++) {
        if (used[i]) continue;
        if (k < dungeons[i][0]) continue;
        used[i] = true;
        dfs(k - dungeons[i][1], dungeons, cnt+1);
        used[i] = false;
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    used.assign(dungeons.size(), false);
    
    dfs(k, dungeons, 0);
    return best;
}