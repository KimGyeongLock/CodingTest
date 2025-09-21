#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    long sum = 0, sum1 = 0;
    if (sum % 2 == 1) return -1;
    
    queue<int> q1, q2;
    for (int i : queue1) {
        sum += i;
        sum1 += i;
        q1.push(i);
    }
    for (int j : queue2) {
        sum += j;
        q2.push(j);
    }
    long half = sum / 2;
    for (int i : queue1) {
        if (half < i) return -1;
    }
    for (int j : queue2) {
        if (half < j) return -1;
    }
    while (sum1 != half) {
        answer += 1;
        if (answer >= 3*(queue1.size() + queue2.size())) return -1;
        if (sum1 > half) {
            int f = q1.front();
            q1.pop();
            q2.push(f);
            sum1 -= f;
        } else if (sum1 < half) {
            int f = q2.front();
            q2.pop();
            q1.push(f);
            sum1 += f;
        }
    }
    
    return answer;
}