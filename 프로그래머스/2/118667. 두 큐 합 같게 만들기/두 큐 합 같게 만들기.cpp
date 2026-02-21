#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    int n = queue1.size();
    queue<int> q1, q2;
    long t1 = 0, t2 = 0;
    for (int i : queue1) {
        q1.push(i);
        t1 += i;
    }
    for (int i : queue2) {
        q2.push(i);
        t2 += i;
    }
    
    while (t1 != t2) {
        answer++;
        if (t1 > t2) {
            t1 -= q1.front();
            t2 += q1.front();
            q2.push(q1.front());
            q1.pop();
        }
        else {
            t2 -= q2.front();
            t1 += q2.front();
            q1.push(q2.front());
            q2.pop();
        }
        if (answer > 3 * n) return -1;
    }
    return answer;
}