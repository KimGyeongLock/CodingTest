#include <iostream>
#include <queue>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;
        queue<pair<int, int> > q;
        priority_queue<int> pq;

        for (int i = 0; i < n; i++) {
            int priority;
            cin >> priority;
            q.push(make_pair(i, priority));
            pq.push(priority);
        }

        int count = 0;
        while (!q.empty()) {
            int index = q.front().first;
            int value = q.front().second;
            q.pop();

            if (value == pq.top()) {
                pq.pop();
                count++;
                if (index == m) {
                    cout << count << '\n';
                    break;
                }
            } else {
                q.push(make_pair(index, value));
            }
        }
    }
    return 0;
}
