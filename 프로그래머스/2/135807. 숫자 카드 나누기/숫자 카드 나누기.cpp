#include <bits/stdc++.h>
using namespace std;

static int gcd_all(const vector<int>& v) {
    int g = 0;
    for (int x : v) g = std::gcd(g, x);
    return g;
}

static bool divides_any(const vector<int>& v, int d) {
    for (int x : v) {
        if (x % d == 0) return true; // 하나라도 나눠떨어지면 실패 조건
    }
    return false;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int gA = gcd_all(arrayA);
    int gB = gcd_all(arrayB);

    int ans = 0;

    // gA가 arrayB의 어떤 수도 나누면 안 됨
    if (!divides_any(arrayB, gA)) ans = max(ans, gA);

    // gB가 arrayA의 어떤 수도 나누면 안 됨
    if (!divides_any(arrayA, gB)) ans = max(ans, gB);

    return ans;
}
