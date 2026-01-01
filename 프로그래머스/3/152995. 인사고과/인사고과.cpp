#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> scores) {
    int wa = scores[0][0];
    int wb = scores[0][1];
    int wsum = wa + wb;
    
    sort(scores.begin(), scores.end(), [](const vector<int>& x, const vector<int>& y) {
        if (x[0] != y[0]) return x[0] > y[0];
        return x[1] < y[1];
    });
    
    int maxB = -1;
    int rank = 1;
    
    for (auto &s : scores) {
        int a = s[0], b = s[1];
        
        if (b < maxB) {
            if (a == wa && b == wb) return -1;             
            continue;
        }
        
        maxB = max(maxB, b);
        
        if (a + b > wsum) rank++;
    }
    return rank;
}