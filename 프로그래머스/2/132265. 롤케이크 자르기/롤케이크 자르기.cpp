#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    
    int n = topping.size();
    unordered_map<int, int> cnt;
    for (int t : topping) cnt[t]++;
    
    unordered_set<int> A;
    int B_cnt = cnt.size();
    for (int i = 0; i < n; i++) {
        A.insert(topping[i]);
        cnt[topping[i]]--;
        if (cnt[topping[i]] == 0) {
            B_cnt--;
        }
        if (A.size() == B_cnt) answer++;
    }
    
    return answer;
}