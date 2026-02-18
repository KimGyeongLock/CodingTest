#include <string>
#include <vector>
#include <climits>

using namespace std;

int dx[5] = {0, 1, 0, -1, 0};
int dy[5] = {0, 0, 1, 0, -1};

void rotateCell(vector<vector<int>>& a, int x, int y, int k) {
    int n = a.size(); 
    
    for (int i = 0; i < 5; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
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
        for (int r = 0; r < n; r++) {
            int k = tmp % 4;
            tmp /= 4;
            if (k) rotateCell(a, 0, r, k);
            cnt += k;
        }
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int upper = a[i - 1][j];
                int k = (4 - upper) % 4;
                if (k) rotateCell(a, i, j, k);
                cnt += k;
            }
        }
        
        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (a[n - 1][i] != 0) {
                ok = false;
                break;
            }
        }
        
        if (ok) {
            best = min(best, cnt);   
        }
    }
    
    
    return best;
}