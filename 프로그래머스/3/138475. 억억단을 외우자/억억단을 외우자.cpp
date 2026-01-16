#include <string>
#include <vector>

using namespace std;

vector<int> solution(int e, vector<int> starts) {
    
    vector<int> d(e + 1, 0);
    for (int i = 1; i <= e; i++) {
        for (int j = i; j <= e; j += i) {
            d[j]++;
        }
    }
    
    vector<int> best(e + 1);
    best[e] = e;
    int curBest = e;
    for (int i = e - 1; i >= 1; i--) {
        if (d[curBest] <= d[i]) curBest = i;
        best[i] = curBest;
    }
    
    vector<int> answer;
    for (int s : starts) {
        answer.push_back(best[s]);
    }
    
    return answer;
}