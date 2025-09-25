#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> jinsu(int n, int k) {
    vector<int> res;
    while(n >= k) {
        res.push_back(n % k);
        n /= k;
    }
    if (n <= k) res.push_back(n);
    reverse(res.begin(), res.end());
    return res;
}

long vecToInt(vector<int>& v) {
    long res = 0;
    for (int d : v) {
        res = res * 10 + d;
    }
    // for (int i = 0; i < v.size(); i++) {
    //     res += v[i] * (pow(10, v.size() - i - 1));
    // }
    return res;
}

bool isPrime(long x) {
    if (x < 2) return false;
    if (x == 2 || x == 3) return true;
    if (x % 2 == 0 || x % 3 == 0) return false;
    
    for (long i = 5; i * i <= x; i += 6) {
        if (x % i == 0 || x % (i + 2) == 0) return false;
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    
    vector<int> vec = jinsu(n, k);
    vector<int> temp;
    for (int i : vec) {
        if (i == 0) {
            if (!temp.empty()) {
                long res = vecToInt(temp);
                if (isPrime(res)) {
                    answer++;
                }
                temp.clear();
            }
        } else {
            temp.push_back(i);
        }
    }
    if (!temp.empty()) {
        long res = vecToInt(temp);
        if (isPrime(res)) {
            answer++;
        }
    }
    
    return answer;
}