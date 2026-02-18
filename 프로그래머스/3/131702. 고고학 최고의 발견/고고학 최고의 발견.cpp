#include <string>
#include <vector>
#include <climits>

using namespace std;

int dx[5] = {0, 1, 0, -1, 0};
int dy[5] = {0, 0, 1, 0, -1};

void rotateCell(vector<vector<int>>& a, int x, int y, int k) {
    int n = a.size();
    for (int dir = 0; dir < 5; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (0 <= nx && nx < n && 0 <= ny && ny < n) {
            a[nx][ny] = (a[nx][ny] + k) % 4;
        }
    }
}

int solution(vector<vector<int>> clockHands) {
    int n = clockHands.size();
    int best = INT_MAX;
    
    int total = 1;
    for (int i = 0; i < n; i++) total *= 4;
    
    for (int mask = 0; mask < total; mask++) {
        auto a = clockHands;
        int cnt = 0;
        
        int tmp = mask;
        for (int j = 0; j < n; j++) {
            int k = tmp % 4; // k = 0~3
            tmp /= 4;
            if (k) rotateCell(a, 0, j, k);
            cnt += k;
        }
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int upper = a[i - 1][j]; // upper => 0
                // (upper + k) % 4 = 0
                // upper + k ≡ 0 (mod 4)
                // k ≡ -upper (mod 4)
                // -upper ≡ 4 + (-upper)
                // k ≡ (4 - upper) % 4
                int k = (4 - upper) % 4;
                if (k) rotateCell(a, i, j, k);
                cnt += k;
            }
        }
        
        bool ok = true;
        for (int j = 0; j < n; j++) {
            if (a[n - 1][j] != 0) {
                ok = false;
                break;
            }
        }
        if (ok) best = min(best, cnt);
    }
    return best;
}