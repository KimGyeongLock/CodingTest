#include <string>
#include <vector>
#include <algorithm>

using namespace std;
 
static int toMin(const string& hhmm) {
    int h = stoi(hhmm.substr(0, 2));
    int m = stoi(hhmm.substr(3, 2));
    return h * 60 + m;
}

struct Plan {
    string name;
    int start;
    int dur;
};

vector<string> solution(vector<vector<string>> plans) {
    vector<Plan> v;
    for (auto &p : plans) {
        v.push_back({p[0], toMin(p[1]), stoi(p[2])});
    }
    
    sort(v.begin(), v.end(), [&](const Plan a, const Plan b) {
       return a.start < b.start; 
    });
    
    vector<string> answer;
    vector<pair<string, int>> st;
    
    int n = v.size();
    
    for (int i = 0; i < n; i++) {
        int curStart = v[i].start;
        int curDur = v[i].dur;
        int nextStart = (i + 1 < n ? v[i+1].start : 1e9);
        
        st.push_back({v[i].name, curDur});
        
        int gap = nextStart - curStart;
        
        while (!st.empty() && gap > 0) {
            auto &top = st.back();
            if (top.second <= gap) {
                gap -= top.second;
                answer.push_back(top.first);
                st.pop_back();
            } else {
                top.second -= gap;
                gap = 0;
            }
        }
    }
    
    while (!st.empty()) {
        answer.push_back(st.back().first);
        st.pop_back();
    }
    return answer;
}