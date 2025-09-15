#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<int> tops) {
    const int MOD = 10007;

    // A[i]: i칸까지 채웠을 때 오른쪽 경계가 '사다리꼴'
    // B[i]: i칸까지 채웠을 때 오른쪽 경계가 '평행사변형'
    int A = 0; // A[0]
    int B = 1; // B[0]

    for (int i = 1; i <= n; ++i) {
        int prevA = A, prevB = B;

        // A[i]
        A = (prevA + prevB) % MOD;

        // B[i]
        if (tops[i-1] == 1) {
            B = ( (2*prevA) % MOD + (3*prevB) % MOD ) % MOD;
        } else {
            B = ( (1*prevA) % MOD + (2*prevB) % MOD ) % MOD;
        }
    }

    return (A + B) % MOD;
}
