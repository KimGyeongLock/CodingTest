#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    vector<int> u;
    while(k != 1) {
        u.push_back(k);
        if (k % 2 == 0) k /= 2;
        else {
            k *= 3;
            k += 1;
        }
    }
    u.push_back(1);
    int n = u.size() - 1;
    
    // 넓이
    vector<double> dd_sum(1, 0);
    for (int i = 0; i < n; i++) {
        double d = (u[i] + u[i+1]) / 2.0;
        dd_sum.push_back(dd_sum[i] + d);
    }
    
    for (auto& r : ranges) {
        int a = r[0];
        int b = n + r[1];
        if (a > b) answer.push_back(-1);
        else answer.push_back(dd_sum[b] - dd_sum[a]);
    }
    
    return answer;
}