#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> elements) {
    unordered_set<int> st;
    int n = elements.size();
    
    for (int i = 0; i < n; i++) {
        elements.push_back(elements[i]);
    }
    vector<int> sum(2*n + 1, 0);
    for (int i = 0; i < n * 2; i++) {
        sum[i+1] = elements[i] + sum[i];
    }
    
    for (int i = 0; i < n; i++) {
        for (int len = 1; len <= n; len++) {
            st.insert(sum[len + i] - sum[i]);
        }
    }
    
    return st.size();
}