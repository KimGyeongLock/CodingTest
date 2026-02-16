#include <string>
#include <vector>
#include <climits>

using namespace std;

int solution(vector<vector<int>> beginning, vector<vector<int>> target) {
    int n = beginning.size();
    int m = beginning[0].size();
    const int INF = INT_MAX;
    int answer = INF;
    
    for (int mask = 0; mask < (1 << n); mask++) { // 00000 (1, 0으로 오픈 표시) < 100000
        int rowFlips = 0;
        for (int x = mask; x; x >>= 1) rowFlips += (x & 1); // 101 -> 10 -> 1 (1의 갯수 = 3)
        
        int colFlips = 0;
        bool ok = true;
        
        for (int c = 0; c < m && ok; c++) { //열 검사
            bool allSame = true;
            bool allOpp = true;
            
            for (int r = 0; r < n; r++) {
                int cur = beginning[r][c];
                if (mask & (1 << r)) cur ^= 1; // (1 << 0) => 0001 (1 << 1) => 0010 (1 << 2) 0100 (XOR) 
                
                if (cur != target[r][c]) allSame = false;
                if ((cur ^ 1) != target[r][c]) allOpp = false;
            }
            
            if (allSame) {
                
            } else if (allOpp) {
                colFlips++;
            } else {
                ok = false; // 섞여 있음
            }
        }
        
        if (ok) {
            int total = rowFlips + colFlips;
            if (total < answer) answer = total;
        }
    }
    
    return answer == INF ? -1 : answer;
}