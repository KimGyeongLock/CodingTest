#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;    
    stack<int> st;
    
    int max_v = 0;
    for (int o : order) {
        if (max_v < o) {
            for (int i = max_v + 1; i < o; i++) st.push(i);
            max_v = o;
        } else {
            if (o == st.top()) st.pop();
            else break;
        }
        answer++;
    }
    
    return answer;
}