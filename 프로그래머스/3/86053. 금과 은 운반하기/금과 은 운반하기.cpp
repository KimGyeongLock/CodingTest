#include <string>
#include <vector>

using namespace std;

bool canMove(long long time, int a, int b, vector<int>& g, vector<int>& s, vector<int>& w, vector<int>& t) {
    int n = g.size();
    long long gold = 0;
    long long silver = 0;
    long long total = 0;
    
    for (int i = 0; i < n; i++) {
        long long moveCnt = time / (2 * t[i]);
        if (time % (2 * t[i]) >= t[i]) moveCnt++;
        
        long long cap = moveCnt * w[i];
        
        gold += min((long long) g[i], cap);
        silver += min((long long) s[i], cap);
        total += min((long long)g[i] + s[i], cap);
    }
    return gold >= a && silver >= b && total >= a + b;
}

long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    long long answer = -1;
    long long left = 1, right = 400000000000000LL;
    
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        
        if (canMove(mid, a, b, g, s, w, t)) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return answer;
}