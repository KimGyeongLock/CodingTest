#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> split(string str, char delimiter) {
    vector<string> res;
    stringstream ss(str);
    string word;
    while(getline(ss, word, delimiter)) {
        res.push_back(word);
    }
    return res;
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    unordered_map<string, int> mp;
    unordered_map<string, vector<string>> mp2;
    for (string r : report) {
        vector<string> vec = split(r, ' ');
        if (find(mp2[vec[0]].begin(), mp2[vec[0]].end(), vec[1]) != mp2[vec[0]].end()) continue;
        mp[vec[1]]++;
        mp2[vec[0]].push_back(vec[1]);
    }
    
    vector<string> ban;
    for (auto& m : mp) {
        cout << m.first << " " << m.second << "\n";
        if (m.second >= k) ban.push_back(m.first);
    }
    
    for (string id : id_list) {
        int cnt = 0;
        for (string ban_id : mp2[id]) {
            if (find(ban.begin(), ban.end(), ban_id) != ban.end()) {
                cnt++;
            }
        }
        answer.push_back(cnt);
    }
    
    return answer;
}