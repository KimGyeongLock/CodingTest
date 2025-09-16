#include <string>
#include <vector>

using namespace std;
constexpr int MOD = 10007;
int solution(int n, vector<int> tops) {
    vector<int> a(n+1, 0), b(n+1, 0);
    
    a[0] = 0;
    b[0] = 1;
    
    for (int i = 1; i <= n; i++) {
        if (tops[i-1] == 1) {
            a[i] = (a[i-1] + b[i-1]) % MOD;
            b[i] = (2*a[i-1] + 3*b[i-1]) % MOD;
        } else {
            a[i] = (a[i-1] + b[i-1]) % MOD;
            b[i] = (a[i-1] + 2*b[i-1]) % MOD;
        }
    }
    return (a[n] + b[n]) % 10007;
}