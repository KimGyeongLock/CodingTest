#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int N;
    cin >> N;

    priority_queue<int, vector<int>, greater<int> > A;
    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;
        A.push(a);
    }

    int sum = 0;
    while (!A.empty())
    {
       int a = A.top();
       A.pop();
       if (A.empty()) break;
       int b = A.top();
       A.pop();

        // cout << a << " " << b << "\n";
       A.push(a+b);
       sum += (a+b);
    }
    
    cout << sum;

}