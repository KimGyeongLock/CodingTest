#include <string>
#include <vector>
#include <cmath>

using namespace std;

const int dx[4] = {1, 0, 0, -1};   // d, l, r, u
const int dy[4] = {0, -1, 1,  0};
const char mv[4] = {'d','l','r','u'};

string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "";
    int dist = abs(x - r) + abs(y - c);
    if (dist > k) return "impossible";
    
    for (int i = 0; i < k; i++) {
        int rem = k - i - 1;
        bool moved = false;
        for (int j = 0; j < 4; j++) {
            int nx = x + dx[j];
            int ny = y + dy[j];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m) {
                int nd = abs(nx - r) + abs(ny - c);
                if (nd <= rem) {
                    answer.push_back(mv[j]);
                    x = nx; y = ny;
                    moved = true;
                    break;
                }
            }
        }
        if (!moved) return "impossible";
    }
    return answer;
}