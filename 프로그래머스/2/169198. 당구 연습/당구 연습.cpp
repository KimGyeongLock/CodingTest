#include <string>
#include <vector>
#include <climits>

using namespace std;

int sq(int v) { return v * v; }

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;
    
    for (auto& ball : balls) {
        int x = ball[0], y = ball[1];
        int best = INT_MAX;
     
        // 왼쪽
        if (!(startY == y && startX > x)) {
            int mx = -x, my = y;
            best = min(best, sq(startX - mx) + sq(startY - my));
        }
        
        // 오른쪽
        if (!(startY == y && startX < x)) {
            int mx = 2 * m - x, my = y;
            best = min(best, sq(startX - mx) + sq(startY - my));
        }
        
        // 아래
        if (!(startX == x && startY > y)) {
            int mx = x, my = -y;
            best = min(best, sq(startX - mx) + sq(startY - my));
        }
        
        // 위
        if (!(startX == x && startY < y)) {
            int mx = x, my = 2 * n - y;
            best = min(best, sq(startX - mx) + sq(startY - my));
        }
        
        answer.push_back(best);
    }
    return answer;
}