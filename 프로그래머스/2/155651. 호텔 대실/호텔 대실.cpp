#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int toMin(string str) {
    int h = stoi(str.substr(0, 2));
    int m = stoi(str.substr(3, 2));
    return h * 60 + m;
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    
    sort(book_time.begin(), book_time.end(), [&](const auto& a, const auto& b) {
        return toMin(a[0]) < toMin(b[0]);
    });
    
    priority_queue<int, vector<int>, greater<>> pq;
    for (auto b : book_time) {
        if (!(pq.empty() || pq.top() > toMin(b[0]))) {
            pq.pop();
        } 
        pq.push(toMin(b[1]) + 10);
        
    }
    
    return pq.size();
}