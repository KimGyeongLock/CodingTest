#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    
    int d = n - 1;
    int p = n - 1;
    while (true) {
        
        while (d >= 0 && deliveries[d] == 0) d--;
        while (p >= 0 && pickups[p] == 0) p--;

        if (d < 0 && p < 0) break;
        
        answer += (max(d, p)+1) * 2;
        
        int capA = cap, capB = cap;
        for (int i = d; i >= 0 && capA > 0; i--) {
            int tmp = min(deliveries[i], capA);
            deliveries[i] -= tmp;
            capA -= tmp;
        }
        
        for (int i = p; i >= 0 && capB > 0; i--) {
            int tmp = min(pickups[i], capB);
            pickups[i] -= tmp;
            capB -= tmp;
        }
    }
    
    return answer;
}