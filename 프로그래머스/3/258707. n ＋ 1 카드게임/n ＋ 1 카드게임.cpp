#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(int coin, vector<int> cards) {
    int answer = 1;
    int n = cards.size();
    int target = n + 1;
    
    unordered_set<int> have;
    unordered_set<int> pool;
    
    int idx = 0;
    for (; idx < n/3; idx++) {
        have.insert(cards[idx]);
    }
    
    while(idx < n) {
        
        for (int k = 0; k < 2 && idx < n; k++, idx++) {
            pool.insert(cards[idx]);
        }
        
        bool progressed = false;
        
        int a = -1;
        int b = -1;
        for (int x : have) {
            int y = target - x;
            if (have.count(y)) {
                a = x;
                b = y;
                break;
            }
        }
        
        if (a != -1) {
            have.erase(a);
            have.erase(b);
            progressed = true;
        }
        
        
        if (!progressed && coin >= 1) {
            a = b = -1;
            for (int x : have) {
                int y = target - x;
                if (pool.count(y)) {
                    a = x;
                    b = y;
                    break;
                }
            }
            
            if (a != -1) {
                have.erase(a);
                pool.erase(b);
                coin -= 1;
                progressed = true;
            }
        }
        
        if (!progressed && coin >= 2) {
            a = b = -1;
            for (int x : pool) {
                int y = target - x;
                if (pool.count(y)) {
                    a = x;
                    b = y;
                    break;
                }
            }
            
            if (a != -1) {
                pool.erase(a);
                pool.erase(b);
                coin -= 2;
                progressed = true;
            }
        }
        
        if (!progressed) break;
        answer++;
    }
    return answer;
}