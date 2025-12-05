#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isPossible(int num, const vector<int> diffs, const vector<int> times, long long limit) {
    long long time = 0;
    for (int i = 0; i < diffs.size(); i++) {
        int d = diffs[i];
        if (d <= num) {
            time += times[i];
        } else {
            int time_cur = times[i];
            int time_prev = i == 0 ? 0 : times[i-1];
            long long t = (d - num) * (time_cur + time_prev) + time_cur;
            time += t;
        }
    }
    return time <= limit;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;
    long long left = 1, right = *max_element(diffs.begin(), diffs.end());
    while (left <= right) {
        long long mid = (left + right) / 2;
        
        if (isPossible(mid, diffs, times, limit)) {
            right = mid - 1;
            answer = mid;
        } else {
            left = mid + 1;
        }
    }
    return answer;
}