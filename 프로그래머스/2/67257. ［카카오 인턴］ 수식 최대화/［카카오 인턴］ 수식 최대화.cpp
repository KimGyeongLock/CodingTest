#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long applyOp(long long a, long long b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
    }
    return 0;
}

long long evalWithOrder(vector<long long> nums, vector<char> ops, vector<char>& order) {
    for (char target : order) {
        vector<long long> n2;
        vector<char> o2;
        long long cur = nums[0];
        for (int i = 0; i < ops.size(); i++) {
            if (ops[i] == target) {
                cur = applyOp(cur, nums[i + 1], ops[i]);
            } else {
                n2.push_back(cur);
                o2.push_back(ops[i]);
                cur = nums[i + 1];
            }
        }
        n2.push_back(cur);
        nums.swap(n2);
        ops.swap(o2);
    }
    return abs(nums[0]);
}

long long solution(string expression) {
    vector<long long> nums;
    vector<char> ops;
    int val = 0;
    for (char c : expression) {
        if (isdigit(c)) {
            val = val * 10 + (c - '0');
        } else {
            nums.push_back(val);
            val = 0;
            ops.push_back(c);
        }
    }
    nums.push_back(val);
    
    vector<char> base = {'+', '-', '*'};
    long long best = 0;
    sort(base.begin(), base.end());
    do {
        best = max(best, evalWithOrder(nums, ops, base));
    } while(next_permutation(base.begin(), base.end()));
    return best;
}