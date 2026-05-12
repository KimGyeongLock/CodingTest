#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>

using namespace std;

vector<string> func(vector<string> user_id, string id) {
    vector<string> result;
    for (string t : user_id) {
        if (t.length() != id.length()) continue;

        bool same = true;
        for (int i = 0; i < id.length(); i++) {
            if (id[i] == '*') continue;
            if (t[i] == id[i]) continue;
            same = false;
            break;
        }
        if (same) result.push_back(t);
    }
    return result;
}

vector<vector<string>> result;
unordered_map<string, bool> visited;
unordered_set<int> st;

void dfs(int idx, const vector<string>& user_id, vector<string> comb) {
    if (idx == result.size()) {
        int r = 0;
        for (int i = 0; i < user_id.size(); i++) {
            r <<= 1;
            for (string c : comb) {
                if (c == user_id[i]) {
                    r |= 1;
                    break;
                }
            }
        }
        
        st.insert(r);
        return;
    }
    
    for (string id : result[idx]) {
        if (visited[id]) continue;
        visited[id] = true;
        comb.push_back(id);
        dfs(idx+1, user_id, comb);
        comb.pop_back();
        visited[id] = false;
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int n = banned_id.size();
    result.resize(n);
    for (string s : user_id) {
        visited[s] = false;
    }
    for (int i = 0; i < n; i++) {
        result[i] = func(user_id, banned_id[i]);
    }
    
    vector<string> comb;
    dfs(0, user_id, comb);
    return st.size();
}