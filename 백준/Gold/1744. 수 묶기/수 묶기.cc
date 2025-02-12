#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int N;
    cin >> N;

    priority_queue<int> plusPq;
    priority_queue<int, vector<int>, greater<int> > minusPq;
    int one = 0;
    int zero = 0;
    int sum = 0;


    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;
        if (a == 1) one++;
        else if (a == 0) zero++;
        else if (a < 0) {
            minusPq.push(a);
        } else if (a > 1) {
            plusPq.push(a);
        }
    }

    while(plusPq.size() >= 2) {
        int a = plusPq.top();
        plusPq.pop();
        int b = plusPq.top();
        plusPq.pop();
        sum += (a*b);
    }

    while(!plusPq.empty()) {
        int a = plusPq.top();
        plusPq.pop();
        sum += a;
    }

    while(minusPq.size() >= 2) {
        int a = minusPq.top();
        minusPq.pop();
        int b = minusPq.top();
        minusPq.pop();
        sum += (a*b);
    }

    if (!minusPq.empty()) {
        if (zero == 0) {
            sum += minusPq.top();
            minusPq.pop();
        }
    }

    
    cout << sum + one;

}