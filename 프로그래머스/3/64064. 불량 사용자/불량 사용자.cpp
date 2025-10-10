#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <functional>
#include <algorithm>

using namespace std;

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    int n = user_id.size();
    int m = banned_id.size();
    
    auto compare = [&](string target) -> vector<int> {
        vector<int> vec;
        for (int i = 0; i < n; i++) {
            const string& str = user_id[i];
            if (str.length() != target.length()) continue;
            bool flag = false;
            for (int i = 0; i < str.length(); i++) {
                if (target[i] == '*') continue;
                if (target[i] != str[i]) {
                    flag = true;
                    break;
                }
            }
            if (!flag) vec.push_back(i);
        }
        return vec;
    };
    
    vector<vector<int>> matches(m);
    for (int i = 0; i < m; i++) {
        matches[i] = (compare(banned_id[i]));
    }
    
    set<string> uniq;
    vector<int> used(n, false);
    vector<string> cur;
    function<void(int)> dfs = [&](int idx) {
        if (idx == m) {
            vector<string> keyv = cur;
            
            sort(keyv.begin(), keyv.end());
            string key;
            for (string k : keyv) key += k;
            uniq.insert(key);
            return;
        }
        
        for (int i : matches[idx]) {
            if (used[i]) continue;
            used[i] = true;
            cur.push_back(user_id[i]);
            dfs(idx + 1);
            cur.pop_back();
            used[i] = false;
        }
        
    };
    
    dfs(0);
    return uniq.size();
}