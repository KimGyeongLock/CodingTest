#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int m = weak.size();
    vector<int> w(weak);
    for (int i = 0; i < m; i++) {
        w.push_back(n + weak[i]);
    }
    
    int answer = INT_MAX;
    for (int start = 0; start < m; start++) {
        sort(dist.begin(), dist.end());

        do {
            int used = 1;
            int cover = w[start] + dist[used - 1];
            bool ok = true;
            for (int i = start; i < start + m; i++) {
                if (w[i] > cover) {
                    used++;
                    if (used > dist.size()) {
                        ok = false;
                        break;
                    }
                    cover = w[i] + dist[used - 1];
                }
            }
            if (ok) answer = min(answer, used);
        } while(next_permutation(dist.begin(), dist.end()));
    }
    
    return answer== INT_MAX ? -1 : answer;
}