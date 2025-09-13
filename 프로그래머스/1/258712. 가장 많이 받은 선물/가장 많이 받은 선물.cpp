#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<string> split(const string& str) {
    vector<string> res;
    istringstream iss(str);
    string word;
    while (iss >> word) {
        res.push_back(word);
    }
    return res;
}

unordered_map<string, int> mp;
vector<vector<int>> trade;
vector<int> rate;

int solution(vector<string> friends, vector<string> gifts) {
    int cnt = friends.size();
    for (int i = 0; i < cnt; i++){
        mp[friends[i]] = i;
    }
    
    trade.resize(cnt, vector<int>(cnt, 0));
    rate.resize(cnt, 0);
    
    for (string s : gifts) {
        vector<string> sp = split(s);
        trade[mp[sp[0]]][mp[sp[1]]]++;
        rate[mp[sp[0]]]++;
        rate[mp[sp[1]]]--;
    }
    
    int max_v = 0;
    for (int i = 0; i < cnt; i++) {
        int c = 0;
        for (int j = 0; j < cnt; j++) {
            if (trade[i][j] > trade[j][i]) c++;
            else if (trade[i][j] == trade[j][i]) {
                if (rate[i] > rate[j]) c++;
            }
        }
        max_v = max(max_v, c);
    }
    return max_v;
}