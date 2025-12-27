#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int x, int y, int n) {
    int answer = 0;
    const int INF = 1e9;
    vector<int> dist(y + 1, INF);
    queue<int> q;
    
    q.push(x);
    dist[x] = 0;
    
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        
        if (cur == y) return dist[cur];
        
        int nx1 = cur + n;
        int nx2 = cur * 2;
        int nx3 = cur * 3;
        
        if (nx1 <= y && dist[nx1] > dist[cur] + 1) {
            dist[nx1] = dist[cur] + 1;
            q.push(nx1);
        }
        if (nx2 <= y && dist[nx2] > dist[cur] + 1) {
            dist[nx2] = dist[cur] + 1;
            q.push(nx2);
        }
        if (nx3 <= y && dist[nx3] > dist[cur] + 1) {
            dist[nx3] = dist[cur] + 1;
            q.push(nx3);
        }
    }
    
    return -1;
}