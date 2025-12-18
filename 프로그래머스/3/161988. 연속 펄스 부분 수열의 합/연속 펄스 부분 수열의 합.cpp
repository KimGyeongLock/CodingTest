#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long solution(vector<int> sequence) {
    int n = sequence.size();
    long long cur = 0, best = 0;
    for (int i = 0; i < n; i++) {
        long long num = sequence[i] * (i % 2 == 0 ? 1 : -1);
        cur = max(num, cur + num);
        best = max(best, cur);
    }
    cur = 0;
    for (int i = 0; i < n; i++) {
        long long num = sequence[i] * (i % 2 == 0 ? -1 : 1);
        cur = max(num, cur + num);
        best = max(best, cur);
    }
    return best;
}