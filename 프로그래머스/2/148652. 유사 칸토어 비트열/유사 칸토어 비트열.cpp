#include <string>
#include <vector>

using namespace std;

// 0: 1
// 1: 11011 5
// 2: (11011)(11011)(00000)(11011)(11011) 25
// 3: 125

static long long pow5[21], pow4[21];

long long f(int n, long long len) {
    if (len <= 0) return 0;
    
    long long blockLen = pow5[n - 1]; // 5
    long long blockOnes = pow4[n - 1]; // 4
    
    long long full = len / blockLen; // 17 / 5 
    long long rem = len % blockLen; // 2
    
    long long ans = 0;
    
    for (long long i = 0; i < full; i++) {
        if (i == 2) continue;
        ans += blockOnes; 
    }
    
    if (full != 2) {
        ans += f(n - 1, rem); // 0 ~ 2
    } 
    return ans;
}

int solution(int n, long long l, long long r) {
    pow5[0] = pow4[0] = 1;
    for (int i = 1; i <= 20; i++) {
        pow5[i] = pow5[i - 1] * 5LL;
        pow4[i] = pow4[i - 1] * 4LL;
    }
    return f(n, r) - f(n, l - 1);
}