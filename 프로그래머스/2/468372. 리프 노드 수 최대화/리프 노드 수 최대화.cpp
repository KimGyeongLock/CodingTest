#include <string>
#include <vector>

using namespace std;

long long answer, D, S;

/*
cur   = 현재 깊이에서 분배 노드로 확장할 수 있는 노드 수
used  = 지금까지 분배 노드로 사용한 개수
split = 현재 깊이까지의 분배도
leaf  = 이미 리프로 확정된 노드 수
*/
void dfs(long long cur, long long used, long long split, long long leaf) {
    if (used > D) return;
    
    answer = max(answer, leaf + cur);
    
    if (cur == 0) return;
    
    for (int child = 2; child <= 3; child++) {
        long long nextSplit = split * child;
        
        if (nextSplit > S) continue;
        
        long long nextNodes = cur * child;
        
        long long remain = D - used; // 남은 분배 노드 개수
        
        long long nextCur = min(nextNodes, remain);
        
        long long nextLeaf = leaf + (nextNodes - nextCur);
        
        dfs(nextCur, used + nextCur, nextSplit, nextLeaf);
    }
}

int solution(int dist_limit, int split_limit) {
    D = dist_limit, S = split_limit;
    answer = 1;
    if (dist_limit == 0) return 1;
    dfs(1, 1, 1, 0);
    return answer;
}