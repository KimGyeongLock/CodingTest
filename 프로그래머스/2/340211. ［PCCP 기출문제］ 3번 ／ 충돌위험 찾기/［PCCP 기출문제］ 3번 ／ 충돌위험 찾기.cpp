#include <string>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

int makeKey(int r, int c, int t) {
    int pos = r * 100 + c;
    return pos * 100000 + t;
}

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;
    unordered_map<int, int> mp;
    for (auto route : routes) {
        int idx = route[0] - 1;
        int r = points[idx][0];
        int c = points[idx][1];
        
        int t = 0;
        
        mp[makeKey(r, c, t)]++;
        
        for (int i = 1; i < route.size(); i++) {
            int tidx = route[i] - 1;
            int tr = points[tidx][0];
            int tc = points[tidx][1];
            
            int dr = (tr > r) ? 1 : (tr < r ? -1 : 0);
            while (r != tr) {
                r += dr;
                t += 1;
                mp[makeKey(r, c, t)]++;
            }
            
            int dc = (tc > c) ? 1 : (tc < c ? -1 : 0);
            while (c != tc) {
                c += dc;
                t += 1;
                mp[makeKey(r, c, t)]++;
            }
        }
    }
    
    for (auto m : mp) {
        if (m.second >= 2) answer++;
    }
    return answer;
}