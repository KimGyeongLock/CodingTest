#include <string>
#include <vector>
#include <cmath>

using namespace std;

int dist(pair<int, int> a, pair<int, int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second); 
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    vector<pair<int,int>> pos = {
        {3, 1},
        {0, 0}, {0, 1}, {0, 2},
        {1, 0}, {1, 1}, {1, 2},
        {2, 0}, {2, 1}, {2, 2}
    };
    pair<int, int> lp = {3, 0}, rp = {3, 2};
    for (int n : numbers) {
        if (n == 1 || n == 4 || n == 7) {
            answer.push_back('L');
            lp = pos[n];
        }
        else if (n == 3 || n == 6 || n == 9) {
            answer.push_back('R');
            rp = pos[n];
        }
        else {
            int dist1 = dist(pos[n], lp);
            int dist2 = dist(pos[n], rp);
            if (dist1 < dist2) {
                answer.push_back('L');
                lp = pos[n];
            } else if (dist1 > dist2) {
                answer.push_back('R');
                rp = pos[n];
            } else {
                if (hand == "left") {
                    answer.push_back('L');
                    lp = pos[n];
                } else {
                    answer.push_back('R');
                    rp = pos[n];
                }
            }
        }
    }
    return answer;
}