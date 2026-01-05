#include <string>
#include <vector>
#include <cmath>

using namespace std;

const int dx[4] = {1, 0, 0, -1};
const int dy[4] = {0, -1, 1, 0};
const char dir[4] = {'d', 'l', 'r', 'u'};

bool isPossible(int n, int m, int x, int y, int r, int c, int k) {
    if (x < 1 || x > n || y < 1 || y > m) return false;
    int dist = abs(x - r) + abs(y - c);
    if (dist > k || (k - dist) % 2 == 1) return false;
    return true;
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "";
    
    // x,y -> r,c
    // 불가능한 경우
    int dist = abs(x - r) + abs(y - c);
    if (dist > k || (k - dist) % 2 == 1) return "impossible";
    
    //
    int nx = x, ny = y;
    for (int step = 0; step < k; step++) {
        for (int i = 0; i < 4; i++) {
            if (isPossible(n, m, nx + dx[i], ny + dy[i], r, c, k - step - 1)) {
                nx += dx[i];
                ny += dy[i];
                answer.push_back(dir[i]);
                break;
            }
        }
    }
    
           
    return answer;
}