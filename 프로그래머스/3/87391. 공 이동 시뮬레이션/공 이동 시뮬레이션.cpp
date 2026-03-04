#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, int m, int x, int y, vector<vector<int>> queries) {
    long long r1 = x, r2 = x;
    long long c1 = y, c2 = y;
    
    for (int i = queries.size() - 1; i >= 0; i--) {
        int type = queries[i][0];
        long long d = queries[i][1];
        
        if (type == 0) { // ->
            c2 = min((long long) m - 1, c2 + d);
            if (c1 != 0) c1 += d;
        }
        else if (type == 1) { // <-
            c1 = max((long long) 0, c1 - d);
            if (c2 != m - 1) c2 -= d;
        }
        else if (type == 2) { // v
            r2 = min((long long) n - 1, r2 + d);
            if (r1 != 0) r1 += d;
        }
        else if (type == 3) { // ^
            r1 = max((long long) 0, r1 - d);
            if (r2 != n - 1) r2 -= d;
        }
        
        if (r1 > r2 || c1 > c2) return 0;
    }
    
    return (r2 - r1 + 1) * (c2 - c1 + 1);
}