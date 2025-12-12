#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    
    long long R1 = 1LL * r1 * r1;
    long long R2 = 1LL * r2 * r2;
    for (int x = 1; x <= r2; x++) {
        long long X = 1LL * x * x;
        
        long long max_v = floor(sqrt(R2 - X));
        long long min_v = 0;
        if (x <= r1) {
            min_v = ceil(sqrt(R1 - X));
        }
        
        answer += (max_v - min_v) + 1;
    }
    return answer * 4;
}