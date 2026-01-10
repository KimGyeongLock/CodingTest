#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {    
    priority_queue<int> pq;
    for (int i = 0; i < enemy.size(); i++) {
        int e = enemy[i];
        n -= e;
        pq.push(e);
        
        if (n < 0) {
            if (k > 0) {
                n += pq.top();
                pq.pop();
                k--;
            } else {
                return i;
            }
        }
        
    }
    return enemy.size();
}