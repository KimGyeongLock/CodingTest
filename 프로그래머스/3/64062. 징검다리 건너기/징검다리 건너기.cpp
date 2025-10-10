#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool can(vector<int>& stones, int cnt, int k) {
    int count = 0;
    for (int s : stones) {
        if (s - cnt <= 0) {
            count++;
        } else {
            count = 0;
        }
        if (count >= k) return false;
    }
    return true;
}

int solution(vector<int> stones, int k) {
    int answer = 0;
    int left = 0, right = *max_element(stones.begin(), stones.end());
    while (left <= right) {
        int mid = (left + right) / 2;
        if (can(stones, mid, k)) {
            answer = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return answer + 1;
}