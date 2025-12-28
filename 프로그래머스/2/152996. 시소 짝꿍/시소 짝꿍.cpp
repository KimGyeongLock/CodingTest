#include <string>
#include <vector>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    vector<long long> cnt(1001, 0);
    for (int w : weights) cnt[w]++;
    
    for (int w = 100; w <= 1000; w++) {
        if (cnt[w] == 0) continue;
        
        // 1 : 1 (같은 무게)
        answer += cnt[w] * (cnt[w] - 1) / 2; // cnt[w]C_2
        
        // 1 : 2
        if (2 * w <= 1000) answer += cnt[w] * cnt[2 * w];
        
        // 2 : 3
        if (3 * w % 2 == 0 && 3 * w / 2 <= 1000) answer += cnt[w] * cnt[3 * w / 2];
        
        // 3 : 4
        if (4 * w % 3 == 0 && 4 * w / 3 <= 1000) answer += cnt[w] * cnt[4 * w / 3];
    }
    
    return answer;
}