#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <map>
#include <cmath>

using namespace std;

vector<string> split(string str, char del) {
    vector<string> res;
    istringstream iss(str);
    string word;
    while(getline(iss, word, del)) {
        res.push_back(word);
    }
    return res;
}

int timeToInt(string x) {
    int h = stoi(x.substr(0, 2));
    int m = stoi(x.substr(3, 2));
    return h * 60 + m;
}

int betweenTime(string a, string b) {
    int t1 = timeToInt(a);
    int t2 = timeToInt(b);
    return t2 - t1;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    unordered_map<string, string> mp;
    map<string, int> ans;
    for (string r : records) {
        vector<string> sp = split(r, ' ');
        string time = sp[0], number = sp[1], type = sp[2];
        if (type == "IN") {
            mp[number] = time;
        } else {
            string intime = mp[number];
            int total = betweenTime(intime, time);
            ans[number] += total;
            mp.erase(number);
        }
    }
    
    for (auto& m : mp) {
        string intime = m.second;
        int total = betweenTime(intime, "23:59");
        ans[m.first] += total;
    }
    
    for (auto& m : ans) {
        int time = m.second;
        int money = 0;
        if (time >= fees[0]) {
            money += fees[1];
            time -= fees[0];
        } else {
            answer.push_back(fees[1]);
            continue;
        }
        money += ceil((double) time / fees[2]) * fees[3];
        answer.push_back(money);
    }
    return answer;
}