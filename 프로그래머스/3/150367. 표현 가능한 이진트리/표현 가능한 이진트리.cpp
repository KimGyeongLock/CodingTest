#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> binary(long long numbers) {
    vector<int> res;
    while (numbers > 1) {
        res.push_back(numbers % 2);
        numbers /= 2;
    }
    res.push_back(numbers);
    reverse(res.begin(), res.end());
    
    int len = res.size();
    int k = 1;
    while (((1 << k) - 1) < len) k++;
    int full_len = (1 << k) - 1;
    res.insert(res.begin(), full_len - len, 0);
    return res;
}

bool ok(vector<int>& v, int l, int r) {
    if (l == r) return true;
    int m = (l + r) / 2;
    if (v[m] == 0) {
        for (int i = l; i <= r; i++) if (v[i] == 1) return false;
        return true;
    }
    
        return ok(v, l, m - 1) && ok(v, m + 1, r);

} 

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    
    for (long long n : numbers) {
        vector<int> vec = binary(n);

        int s = vec.size();
        if (ok(vec, 0, s - 1)) answer.push_back(1);
        else answer.push_back(0);
    }
    return answer;
}