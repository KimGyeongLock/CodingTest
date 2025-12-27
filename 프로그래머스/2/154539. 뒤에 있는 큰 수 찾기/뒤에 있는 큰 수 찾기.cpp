#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    int n = numbers.size();
    vector<int> answer(n, -1);
    vector<int> st;
    
    for (int i = 0; i < n; i++) {
        while (!st.empty() && numbers[st.back()] < numbers[i]) {
            answer[st.back()] = numbers[i];
            st.pop_back();
        }
        st.push_back(i);
    }
    return answer;
}