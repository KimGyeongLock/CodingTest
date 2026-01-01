#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    
    int d = n - 1;
    int p = n - 1;

    while(true) {
        while(d >= 0 && deliveries[d] == 0) d--;
        while(p >= 0 && pickups[p] == 0) p--;
        
        if (d < 0 && p < 0) break;
        
        int far = max(d, p);
        answer += (far + 1) * 2;
        
        int capA = cap;
        int capB = cap;
        for (int i = d; i >= 0 && capA; i--) {
            if (deliveries[i] > 0) {
                int tmp = min(deliveries[i], capA);
                capA -= tmp;
                deliveries[i] -= tmp;
            }
        }
        for (int i = p; i >= 0 && capB; i--) {
            if (pickups[i] > 0) {
                int tmp = min(pickups[i], capB);
                capB -= tmp;
                pickups[i] -= tmp;
            }
        }
    }
    return answer;
}