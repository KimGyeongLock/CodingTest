#include <string>
#include <vector>
#include <climits>

using namespace std;

int solution(vector<vector<int>> beginning, vector<vector<int>> target) {
    int n = beginning.size();
    int m = beginning[0].size();
    int answer = INT_MAX;
    
    for (int mask = 0; mask < (1 << n); mask++) {
        int rowFlips = 0;
        for (int x = mask; x; x >>= 1) if (x & 1) rowFlips++;
        
        int colFlips = 0;
        bool ok = true;
        
        for (int c = 0; c < m && ok; c++) {
            bool allSame = true;
            bool allOpp = true;
            
            for (int r = 0; r < n; r++) {
                int cur = beginning[r][c];
                if (mask & (1 << r)) cur ^= 1;
                
                if (cur != target[r][c]) allSame = false;
                if ((cur ^ 1) != target[r][c]) allOpp = false;
            }
            
            if (allSame) {
                
            } else if (allOpp) {
                colFlips++;
            } else {
                ok = false;
            }
        }
        
        if (ok) {
            int total = rowFlips + colFlips;
            answer = min(answer, total);
        }
    }
    
    return answer == INT_MAX ? -1 : answer;
}