#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    priority_queue<int> pq; 
    int cleared = 0;

    for (int e : enemy) {
        n -= e;
        pq.push(e);

        if (n < 0) {
            if (k == 0) break;
            n += pq.top();
            pq.pop();
            k--;
        }

        cleared++;
    }

    return cleared;
}
